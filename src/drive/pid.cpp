#include "pid.hpp"
#include "main.h"
#include "pros/llemu.hpp"
#include <iostream>
#include <string>

PID::PID(double kP_, double kI_, double kD_) {
  kP = kP_;
  kI = kI_;
  kD = kD_;
}
void PID::set(double setpoint_) { setpoint = setpoint_; }
PID::~PID() {}
double PID::compute(double sensorValue) {
  double error = setpoint - sensorValue;
  double integral = integral + error;
  double prevError = 0;
  if (fabs(error) < setpoint) { // fabs is absolute value for floats
    integral += error;
    std::cout << integral << " integral " << std::endl;
  }
  if (error == 0) {
    integral = 0;
  }
  double derivative = error - prevError;
  std::cout << derivative << " derivative " << std::endl;
  prevError = error;
  pros::lcd::set_text(2, std::to_string(sensorValue)); 
  pros::lcd::set_text(3, std::to_string(error));
  pros::lcd::set_text(4, std::to_string(setpoint));
  pros::lcd::set_text(5, std::to_string(gyro.get_rotation()));
  // pros::lcd::set_text(6, std::to_string(l1.get_position()));
  return error * kP + integral * kI + derivative * kD;
}
void Drive(double setpoint, int time) {
  r1.tare_position();
  l1.tare_position();
  double degrees_per_rotation = 480;
  double circumference = 3.25 * M_PI;
  double tick_per_inch = (degrees_per_rotation / circumference);
  double distance = (setpoint) * tick_per_inch;
  // setpoint is in inches, so convert to ticks for degrees
  drive_PID.set(distance);
  // sets the target in order to drive this distance
  int t_d = 0;
  while (t_d < time) {
    double power =
        drive_PID.compute((r1.get_position() + l1.get_position()) / 2);
    // gets the average of the wheels to do pid more accurately
    set_tank(power, power);
    if (drive_PID.power < 0.2) {
      t_d += 10;
    } else {
      t_d = 0;
    }
    pros::delay(10);
  }
  set_tank(0, 0);
  pros::delay(75);
}

void Turn(double setpoint, int time) {
  int t_t = 0;
  turn_PID.set(setpoint);
  while (t_t < time) {
    double power = turn_PID.compute(gyro.get_rotation());
    std::cout << l1.get_actual_velocity() << " motor l1 " << r1.get_actual_velocity() << " motor r1 " << std::endl;
    set_tank(-power, power);
    if (turn_PID.power < 0.2) {
      t_t += 10;
    } else {
      t_t = 0;
    }
    pros::delay(10);
  }
  set_tank(0, 0);
  pros::delay(75);
}
