#pragma once
#include "api.h"
inline pros::Controller master(pros::E_CONTROLLER_MASTER);
inline pros::Motor r1(12, pros::E_MOTOR_GEARSET_06, false,
                      pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor r2(3, pros::E_MOTOR_GEARSET_06, false);
inline pros::Motor r3(2, pros::E_MOTOR_GEARSET_06, true);
inline pros::Motor l1(16, pros::E_MOTOR_GEARSET_06, true,
                      pros::E_MOTOR_ENCODER_DEGREES);
inline pros::Motor l2(9, pros::E_MOTOR_GEARSET_06, true);
inline pros::Motor l3(10, pros::E_MOTOR_GEARSET_06, false);
inline pros::Motor intakeStage1(15, pros::E_MOTOR_GEARSET_06, true);
inline pros::Motor intakeStage2(8, pros::E_MOTOR_GEARSET_06, true);
inline pros::Imu gyro(18);
inline pros::ADIDigitalOut mogomech('a');
inline pros::ADIDigitalOut doinker('b');

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
void Wait(double time);
void Slow_D(double power, double time);
double ema(double input, double alpha);
void MogoMechActuate(std::string mode);
void AutoIntake(double time);
