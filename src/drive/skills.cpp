#include "main.h"

void skills() {
  rollers = 90; // spins roller
  Drive(5, 500, 0);
  Drive(-6, 500, 0);
  Turn(110, 1000, 0);
  rollers = -100;    // intakes 1 disc closest
  Slow_D(100, 1300); // spins roller 2
  Drive(-6, 500, 103);
  Turn(0, 1000, 103);
  Drive(-50, 2000, 103); // drives up to high goal
  Turn(10, 500, 103);
  flywheel_shoot(3, 575);
  Turn(0, 500, 0);
  Drive(80, 1750, 0);
  Turn(-135, 1500, 0); // picks up straight 3 in the middle
  rollers = -127;
  Slow_D(85, 2250);
  Wait(500);
  Turn(-37, 1000, 97);
  Wait(500);
  flywheel_shoot(3, 800);
  Turn(-135, 1000, 0); // picks up 3 stack
  Drive(20, 1000, 100);
  Turn(-135, 1000, 100);
  rollers = -100;
  Slow_D(50, 1350);
  Turn(105, 1000, 100);
  flywheel_shoot(3, 900); // shoots 3 stack
  Turn(-135, 1000, 0);    // gets rollers
  Drive(30, 1000, 0);
  Turn(180, 1000, 0);
  rollers = 90; // spins roller
  Drive(8, 500, 0);
  Drive(-6, 500, 0); // spins roller 2
  Turn(-70, 1000, 0);
  rollers = -90; // intakes 1 disc closest
  Slow_D(100, 1600);
  Drive(-4, 500, 0);
  Turn(45, 1000, 0); // expansion
  expansion.set_value(true);
}
