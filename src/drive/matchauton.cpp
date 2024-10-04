#include "drive.hpp"
#include "main.h"
#include <string>

void BlueLeftSide(){
    MogoMechActuate(std::to_string(true));
    Drive(-12, 750);
    Slow_D(-50, 675);
    MogoMechActuate(std::to_string(false) );
    AutoIntake(1000);
    pros::delay(750);
    Turn(90, 1000);
    intakeStage1.move_velocity(600);
    intakeStage2.move_velocity(275);
    Slow_D(60, 700);
    pros::delay(1500);
    intakeStage1.move_velocity(0);
    intakeStage2.move_velocity(0);
    Turn(-125, 1500);
    Drive(15, 1000);
    DoinkerActuate(std::to_string(true));
    Turn(-180, 750);
}

void BlueRightSide(){
    MogoMechActuate(std::to_string(true));
    Drive(-12, 750);
    Slow_D(-50, 675);
    MogoMechActuate(std::to_string(false) );
    AutoIntake(1000);
    pros::delay(750);
    Turn(-90, 750);
    intakeStage1.move_velocity(600);
    intakeStage2.move_velocity(275);
    Slow_D(60, 700);
    pros::delay(1500);
    Turn(-180, 750);
}

void RedLeftSide(){
    MogoMechActuate(std::to_string(true));
    Drive(-12, 750);
    Slow_D(-50, 675);
    MogoMechActuate(std::to_string(false) );
    AutoIntake(1000);
    pros::delay(750);
    Turn(-90, 1000);
    intakeStage1.move_velocity(600);
    intakeStage2.move_velocity(275);
    Slow_D(60, 700);
    pros::delay(1500);
    intakeStage1.move_velocity(0);
    intakeStage2.move_velocity(0);
    Turn(-235, 1500);
    Drive(15, 1000);
    DoinkerActuate(std::to_string(true));
    Turn(180, 750);
}

void RedRightSide(){
 
}

void matchAuton(int mode){
    if (mode == 1){
        BlueLeftSide();
    }
    if(mode == 2){
        BlueRightSide();
    }
    if(mode == 3){
        RedLeftSide();
    }
    if(mode == 4){
        RedRightSide();
    }
}