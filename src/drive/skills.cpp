#include "drive.hpp"
#include "main.h"
#include "pid.hpp"
#include "pros/motors.h"
#include <string>

void skills() {
    // Drive(14.5, 950);
    // Turn(-65, 1150);
    // extend_wings(std::to_string(true));
    // flySpeed(600); //spins flywheel/kicker
    // Wait(3);
    // flywheel.move_velocity(0);
    // extend_wings(std::to_string(false));
    
    // Turn(90, 1200);
    // Drive(56, 1100);
    // Turn(-45, 900);
    // Drive(15, 750);
    // intake.move_velocity(-200);
    // Wait(0.25);
    // Turn(135, 1000);
    // set_tankAuton(100, 100, 1.5);
    // Turn(135, 800);
    // extend_wings(std::to_string(true));
    // set_tankAuton(127, 127, 1.5); // middle score
    // extend_wings(std::to_string(false));
    // Drive(-7, 750);
    
    Turn(225, 1400); // turn to right score
    Drive(54, 1500);
    Turn(90, 1100);
    Drive(25, 1100);
    Turn(-135, 1600);
    Drive(-15, 800);
    Drive(7, 700);
    Turn(-135, 600);
    Drive(-15, 800);
    Drive(7, 700); // right score

    Turn(-45, 1200);
    Drive(25, 1200);
    Turn(45, 900);
    Drive(240, 1500); // drive to left score
    Turn(0, 750);
    Drive(-15, 900);
    Turn(45, 750);
    Drive(-15, 900);
    Drive(7, 800);
    Turn(45, 400);
    Drive(-15, 900);
    Drive(7, 800);    
    }