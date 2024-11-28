#include "drive.hpp"
#include "main.h"
#include "pid.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include <string>

void skills() {
    AutoIntake(800);
    Slow_D(90, 225); 
    Wait(250);
    Turn(90, 850);
    Slow_D(-80, 350);
    Slow_D(-50, 350);
    mogomech.set_value(true); // clamps mogo
    Wait(200);
    Turn(0, 750);
    intake.move_velocity(600);
    Slow_D(90, 400);
    Wait(800);
    Turn(-90, 750);
    Slow_D(90, 450);
    Wait(2500);
    Turn(-205, 2000);
    Slow_D(70, 800);
    Wait(350);
    Turn(-135, 1500);
    // Slow_D(100, 250);
}