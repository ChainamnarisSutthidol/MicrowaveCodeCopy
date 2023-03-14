#pragma once
#include "api.h"
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor r1(9, pros::E_MOTOR_GEARSET_18, true,
                      pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor r2(20, pros::E_MOTOR_GEARSET_18, true);
inline pros::Motor l1(2, pros::E_MOTOR_GEARSET_18, false,
                      pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor l2(1, pros::E_MOTOR_GEARSET_18, false);
inline pros::Motor rollers(8, true);
inline pros::Motor flywheel(7, false);
inline pros::Motor indexer(10, false);
inline pros::ADIDigitalOut pew('a');
inline pros::ADIDigitalOut expansion('b');
inline pros::Imu gyro(14);

void set_tank(int r_power, int l_power);
void joystick_control();
void match_auto(int type);
void skills();
void Drive(double setpoint, int time, int f_speed);
void Turn(double setpoint, int time, int f_speed);
void brake_initialize();
void flywheel_shoot(double times, double delay);
void Wait(int time);
void Slow_D(double power, double time);
double ema(double input, double alpha);