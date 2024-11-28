#pragma once
#include "api.h"

class PID {
public:
  PID(double kP_ = 0, double kI_ = 0, double kD_ = 0);
  ~PID();
  double compute(double sensorValue);
  void set(double setpoint_);
  void setConstants(double kP_ = 0, double kI_ = 0, double kD_ = 0);
  double power;
  double setpoint;
  double derivative;
  double error;

private:
  double kP;
  double kI;
  double kD;
  double prevError;
  double integral;
};

inline PID drive_PID(3.6, 0.02, 3);
inline PID turn_PID(1.95,50, 0.1);
void Drive(double setpoint, int time);
void Turn(double target, int time);
