#include "main.h"

double setpoint = 0;
double kv = 0.23;
double PID_I = 0;

void set_speed(double f_speed){
    setpoint = f_speed;
    fw_PID.set(f_speed);
}
void flywheel_compute(){
    double current_speed = ema(flywheel.get_actual_velocity(), 0.5); // uses alpha weight to filter out flywheel noise
    if(current_speed < setpoint - 20){ // bang_bang
        flywheel = 127;
    } else if(current_speed > setpoint + 20){
        flywheel = kv * setpoint;
    } else{
        PID_I += fw_PID.compute(current_speed);
        flywheel = PID_I + kv * setpoint;
    }
}
