#include "drive.hpp"
#include "main.h"

void match_auto(int type) {
  if (type == 1) {
    rollers = 90;
    Slow_D(100, 500);
    Slow_D(-100, 230);
    Turn(-135, 1250, 102);
    rollers = -100;
    Drive(24, 1250, 102);
    Slow_D(50, 1500);
    Turn(-45, 1000, 102);
    Drive(-7, 500, 102);
    Turn(-33.5, 750, 102);
    Wait(800);
    flywheel_shoot(3, 1750);
  }
  if (type == 2) { // offside rollers
    rollers = 90;
    Drive(3, 750, 0);
    Turn(90, 1000, 0);
    Drive(18, 750, 0);
    Turn(180, 1000, 0);
    Drive(8, 500, 0);
    Drive(-3.6, 500, 0); // rolls roller
    rollers = -90;
    Turn(-45, 1750, 102);
    Slow_D(90, 2500);
    Turn(-135, 1000, 102);
    Drive(-5, 800, 102);
    Turn(-128, 500, 102);
    flywheel_shoot(3, 1750);
  }
}
