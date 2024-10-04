#include "drive.hpp"
#include "main.h"
#include "pid.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include <string>

void skills() {
    MogoMechActuate(std::to_string(true));
    Drive(-15, 750);
    Slow_D(-50, 500);
    MogoMechActuate(std::to_string(false));
    AutoIntake(1000);
    pros::delay(750);
    intakeStage2.move_velocity(0);
    Turn(90, 1000);
    intakeStage1.move_velocity(600);
    intakeStage2.move_velocity(275);
    Slow_D(80, 500);
    pros::delay(1500);
    intakeStage1.move_velocity(0);
    intakeStage2.move_velocity(0);
    Turn(-125, 1500);
    Drive(20, 1000);
    Turn(-180, 750);
}
