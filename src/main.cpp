#include "main.h"
#include "drive.hpp"
#include <iostream>
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text
 * between "I was pressed!" and nothing.
 */

//  ez::GUI display(
//     {{l1, "left 1"},
//      {l2, "left 2"},
//      {r2, "right 2"},
//      {r1, "right 1"},
//      {l3, "left 3"},
//      {r3, "right 3"},
//      {intake, "intake"},
//      {flywheel, "fly 1"}},

//     {{"Far Side", FarSide},
//     {"Close Side WP", CloseSideWP},
//     {"Close Side Disrupt", CloseSideDis},
//     {"Skills", skills}});
void on_center_button() {
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) {
    pros::lcd::set_text(2, "I was pressed!");
  } else {
    pros::lcd::clear_line(2);
  }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.pros
 */
void initialize() {

  pros::lcd::initialize();
  pros::lcd::print(1, "hallo");
  // pros::lcd::set_background_color(255, 0, 0);

  // pros::lcd::register_btn1_cb(on_center_button);

  brake_initialize();
  gyro.reset();
  rotationSensor.reset();
  rotationSensor.set_reversed(true);
  ladyBrown.tare_position();
  pros::delay(2000);
  // display.enable();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() { //1 = red r 2 = red l 3 = blue r 4 = blue l
    // matchAuton(2);
    Turn(90, 75000);
    // Drive(24, 75000);
    // skills();
    // AutoIntake(800);
  }
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, theBV
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  while (true) {
    joystick_control();
    pros::delay(10);
  }
}
