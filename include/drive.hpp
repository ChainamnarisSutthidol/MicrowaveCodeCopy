#pragma once
#include "api.h"
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor r1(12, pros::E_MOTOR_GEARSET_06, false,
                      pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor r2(3, pros::E_MOTOR_GEARSET_06, false);
inline pros::Motor r3(2, pros::E_MOTOR_GEARSET_06, true);
inline pros::Motor l1(18, pros::E_MOTOR_GEARSET_06, true,
                      pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor l2(9, pros::E_MOTOR_GEARSET_06, true);
inline pros::Motor l3(8, pros::E_MOTOR_GEARSET_06, false);
inline pros::Motor intake(20, pros::E_MOTOR_GEARSET_06, true);
inline pros::Motor flywheel(1, pros::E_MOTOR_GEARSET_06, false);
inline pros::Imu gyro(14);
inline pros::ADIDigitalOut wings1('d');
inline pros::ADIDigitalOut wings2('h');
inline pros::ADIDigitalOut hang('e');

void set_tank(int r_power, int l_power);
void set_tankAuton(int r_power, int l_power, double drive_time);
void joystick_control();
void FarSide();
void CloseSideWP();
void CloseSideDis();
void skills();
void Drive(double setpoint, int time);
void Turn(double setpoint, int time);
void brake_initialize();
void flywheel_shoot(double times, double delay);
void Wait(double time);
void Slow_D(double power, double time);
double ema(double input, double alpha);
void flySpeed(double flywheel_rpm);
void extend_wings(std::string mode);
