#include "main.h"
#include "pid.hpp"
#include <string>

bool mogoBool = false;
bool doinkBool = false;
double pastOutput = 0;
double t_time = 0;

void brake_initialize() {
  pros::Motor r1(3);
  r1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor r2(2);
  r2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor r3(12);
  l2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor l1(9);
  l1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor l2(10);
  l2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor l3(20);
  l2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor ladyBrown(9);
  ladyBrown.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

}
void set_tank(int r_power, int l_power) {
  r1.move(r_power);
  r2.move(r_power);
  r3.move(r_power);
  l1.move(l_power);
  l2.move(l_power);
  l3.move(l_power);
}

void set_tankAuton(int r_power, int l_power, double drive_time) {
  r1.move(r_power);
  r2.move(r_power);
  r3.move(r_power);
  l1.move(l_power);
  l2.move(l_power);
  l3.move(l_power);
  Wait(drive_time);
  r1.move(r_power);
  r2.move(r_power);
  r3.move(r_power);
  l1.move(l_power);
  l2.move(l_power);
  l3.move(l_power);
  Wait(0.02);
}

void joystick_control() {
  int r_joystick = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  int l_joystick = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  set_tank(r_joystick, l_joystick); // driving using joystick y coordinates
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == true) {
    intake.move_velocity(450);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == true) {
    intake.move_velocity(-450);
  } else {
    intake.move_velocity(0);
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN) == true) {
    mogoBool = !mogoBool;
    mogomech.set_value(mogoBool);
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B) == true) {
    doinkBool = !doinkBool;
    doinker.set_value(doinkBool);
  }
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    ladyBrown.move_velocity(200);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    ladyBrown.move_velocity(-200);
    // if(rotationSensor.get_position() > 4500){
    //   ladyBrown.move_velocity(0);
    // }
    // if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) && rotationSensor.get_position() > 4500){
    //   ladyBrown.move_velocity(-200);
    // }
    // if (rotationSensor.get_position() > 16000){
    //   ladyBrown.move_velocity(0);
    // }
    std::cout << "Rotation: " << rotationSensor.get_position() << std::endl;
  } else {
    ladyBrown.move_velocity(0);
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
void Wait(double time) { pros::delay(time); }

void AutoIntake(double time){
  intake.move_velocity(450);
  Wait(time);
  intake.move_velocity(0);
}
