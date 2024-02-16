#include "drive.hpp"
#include "main.h"
#include <string>


void FarSide() {
    extend_wings(std::to_string(true));
    Drive(13.5, 650);
    extend_wings(std::to_string(false));  
    Wait(0.2);
    Turn(-30, 750);    
    intake.move_velocity(-600);
    Drive(30, 850);
    Drive(-8.25, 550);
    intake.move_velocity(0);
    Turn(-115, 950);
    intake.move_velocity(600);
    Drive(45.5, 1200);
    Wait(0.10);
    intake.move_velocity(0);
    Drive(-5, 500);
    Turn(10, 950);
    intake.move_velocity(-600);
    Wait(0.35);
    Turn(-80, 850);
    intake.move_velocity(600);
    Drive(20, 800);
    Wait(0.5);
    Drive(-5, 500);
    intake.move_velocity(0);
    Turn(45, 1050);
    extend_wings(std::to_string(true));
    Drive(46, 1000);
    intake.move_velocity(-600);
    Drive(-2, 300);
    extend_wings(std::to_string(false));
}

void CloseSideWP() {
    Drive(-19, 800);
    Turn(30,1200);
    Drive(-13, 700);
    Drive(5, 750);
    set_tankAuton(-100, -100, 0.5);
    Turn(50,1050);
    Drive(7, 750);
    Turn(10, 850);
    extend_wings(std::to_string(true));
    Drive(15, 950);
    extend_wings(std::to_string(false));
    Drive(3, 500);
    Turn(-43, 750);
    Drive(33, 1000);
    intake.move_velocity(-600);
    Wait(0.15);
    intake.move_velocity(0);
}

void CloseSideDis() {
    Drive(40,1000);
    Turn(90,850);
    extend_wings(std::to_string(true));
    Drive(24,1000);
    Wait(0.5);
    extend_wings(std::to_string(false));
    Drive(0, 13000);
}