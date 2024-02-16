#include "main.h"
#include "pid.hpp"
#include <string>

bool flyBool = false;
bool wingBool = false;
bool hangBool = false;
bool brakeBool = false;
double pastOutput = 0;
double t_time = 0;
std::string mode = "";

void brake_initialize() {
  pros::Motor r1(12);
  r1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor r2(3);
  r2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor r3(2);
  l2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor l1(18);
  l1.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor l2(9);
  l2.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  pros::Motor l3(8);
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

void set_tankAuton(int r_power, int l_power, double drive_time){
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

void extend_wings(std::string mode){
  wings1.set_value(std::stoi(mode));
  wings2.set_value(std::stoi(mode));
}

void joystick_control() {
  int r_joystick = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  int l_joystick = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  set_tank(r_joystick, l_joystick); // driving using joystick y coordinates
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == true){
    intake.move_velocity(600);
  }else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == true){
    intake.move_velocity(-600);
  } else{
    intake.move_velocity(0);
  }
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
    flyBool = !flyBool;
  }
  flySpeed(int(flyBool) * 600);
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) == true){
    wingBool = !wingBool;
    extend_wings(std::to_string(wingBool));
  }
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
    hangBool = !hangBool;
    hang.set_value(hangBool);
  } 
  if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){
    brakeBool = !brakeBool;
    if(brakeBool == true){
      r1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      r2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      r3.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      l1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      l2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      l3.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    } else{
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

