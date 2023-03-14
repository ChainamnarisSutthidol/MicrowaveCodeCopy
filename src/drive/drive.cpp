#include "main.h"
#include "pid.hpp"

bool flyBool = false;
bool indexBool = false;
double pastOutput = 0;
void brake_initialize() {
  pros::Motor r1(9);
  r1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  pros::Motor r2(20);
  r2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  pros::Motor l1(2);
  l1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  pros::Motor l2(1);
  l1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
void set_tank(int r_power, int l_power) {
  r1 = r_power;
  r2 = r_power;
  l1 = l_power;
  l2 = l_power;
}

void joystick_control() {
  int r_joystick = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  int l_joystick = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  set_tank(r_joystick, l_joystick);
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == true) {
    rollers.move_velocity(300);
  } else {
    rollers.move_velocity(0);
  }
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == true) {
    rollers.move_velocity(-300);
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
    flyBool = !flyBool;
  }
  flywheel = int(flyBool) * 127;
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
    indexBool = !indexBool;
  }
  indexer = int(indexBool) * 105;
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X) == true &&
      master.get_digital(pros::E_CONTROLLER_DIGITAL_B) == true) {
    expansion.set_value(true);
  }
}
double ema(double input, double alpha) {
  pastOutput = (pastOutput * alpha + input * (1 - alpha));
  return pastOutput;
}
void flywheel_shoot(double times, double delay) {
  indexer = 100;
  Wait(delay * times);
  indexer = 0;
  flywheel = 0;
}
void Slow_D(double power, double time) {
  // makes robot slower for consistent intake
  set_tank(power, power);
  Wait(time);
  set_tank(0, 0);
}
void Wait(int time) { pros::delay(time); }
