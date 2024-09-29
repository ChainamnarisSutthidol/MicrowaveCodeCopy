#include "main.h"
#include "pid.hpp"
#include <string>

bool mogoBool = false;
bool brakeBool = false;
double pastOutput = 0;
double t_time = 0;
std::string mode = "";

void brake_initialize() {
  pros::Motor r1(12);
  r1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor r2(2);
  r2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor r3(1);
  l2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor l1(16);
  l1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor l2(10);
  l2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor l3(9);
  l2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}
void set_tank(int r_power, int l_power) {
  r1 = r_power;
  r2 = r_power;
  r3 = r_power;
  l1 = l_power;
  l2 = l_power;
  l3 = l_power;
}

void set_tankAuton(int r_power, int l_power, double drive_time) {
  r1 = r_power;
  r2 = r_power;
  r3 = r_power;
  l1 = l_power;
  l2 = l_power;
  l3 = l_power;
  Wait(drive_time);
  r1 = 0;
  r2 = 0;
  r3 = 0;
  l1 = 0;
  l2 = 0;
  l3 = 0;
  Wait(0.02);
}

void MogoMechActuate(std::string mode) { mogomech.set_value(std::stoi(mode)); }

void joystick_control() {
  int r_joystick = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  int l_joystick = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  set_tank(r_joystick, l_joystick); // driving using joystick y coordinates
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == true) {
    intakeStage1.move_velocity(600);
    intakeStage2.move_velocity(275);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == true) {
    intakeStage1.move_velocity(-600);
    intakeStage2.move_velocity(-275);
  } else {
    intakeStage1.move_velocity(0);
    intakeStage2.move_velocity(0);
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) == true) {
    mogoBool = !mogoBool;
    MogoMechActuate(std::to_string(mogoBool));
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
    brakeBool = !brakeBool;
    if (brakeBool == true) {
      r1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      r2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      r3.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      l1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      l2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      l3.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    } else {
      brake_initialize();
    }
  }
}
double ema(double input, double alpha) {
  pastOutput = (pastOutput * alpha + input * (1 - alpha));
  return pastOutput;
}
void Slow_D(double power, double time) {
  // makes robot slower for consistent intake
  set_tank(power, power);
  Wait(time);
  set_tank(0, 0);
}
void Wait(double time) { pros::delay(time * 1000); }
