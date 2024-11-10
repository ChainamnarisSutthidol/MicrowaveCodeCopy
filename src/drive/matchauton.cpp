#include "drive.hpp"
#include "main.h"
#include <string>

void RedRightSide(){
    mogomech.set_value(true);
    // Drive(-12, 750);
    Slow_D(-90, 350);
    Slow_D(-50, 550);
    mogomech.set_value(false);
    Wait(350);
    AutoIntake(1000);
    pros::delay(750);
    Turn(-90, 1000);
    intake.move_velocity(450);
    Slow_D(100, 360);
    pros::delay(2500);
    intake.move_velocity(0);
    Turn(125, 1500);
    Drive(15, 1000);
}

void RedLeftSide(){
    mogomech.set_value(true);
    // Drive(-12, 750);
    Slow_D(-90, 350);
    Slow_D(-50, 525);
    mogomech.set_value(false);
    Wait(350);
    AutoIntake(1000);
    Wait(350);
    Turn(90, 750);
    intake.move_velocity(450);
    Wait(750);
    Slow_D(-25, 300);
    Turn(180, 750);
    intake.move_velocity(0);
    Slow_D(50, 500);
    Wait(500);
    Drive(-9, 750);
    intake.move_velocity(450);
    Wait(1000);
    Turn(90, 900);
    Slow_D(25, 375);
    Turn(180, 750);
    Slow_D(40, 850);
    Wait(500);
    intake.move_velocity(450);
    Slow_D(-70, 175);
    Wait(900);
    Turn(270, 750);
    Drive(18, 1000);
}

void BlueRightSide(){
    mogomech.set_value(true);
    // Drive(-12, 750);
    Slow_D(-90, 350);
    Slow_D(-50, 525);
    mogomech.set_value(false);
    Wait(350);
    AutoIntake(1000);
    Wait(350);
    Turn(-90, 750);
    intake.move_velocity(450);
    Slow_D(50, 900);
    Wait(750);
    Slow_D(-25, 200);
    Turn(-180, 750);
    Slow_D(50, 550);
    Wait(500);
    Drive(-9, 750);
    intake.move_velocity(375);
    Wait(1000);
    Turn(-90, 900);
    Slow_D(25, 375);
    Turn(-180, 750);
    Slow_D(30, 900);
    Wait(500);
    intake.move_velocity(450);
    Slow_D(-70, 175);
    Wait(900);
    Turn(-270, 750);
    Drive(18, 1000);
}

void BlueLeftSide(){
    mogomech.set_value(true);
    // Drive(-12, 750);
    Slow_D(-90, 350);
    Slow_D(-50, 550);
    mogomech.set_value(false);
    Wait(350);
    AutoIntake(1000);
    pros::delay(750);
    Turn(90, 1000);
    intake.move_velocity(450);
    Slow_D(70, 600);
    pros::delay(2000);
    intake.move_velocity(0);
    Turn(-125, 1500);
    Drive(14, 1000);
}




void matchAuton(int mode){
    if (mode == 1){
        RedRightSide();
    }
    if(mode == 2){
        RedLeftSide();
    }
    if(mode == 3){
        BlueRightSide();
    }
    if(mode == 4){
        BlueLeftSide();
    }
}