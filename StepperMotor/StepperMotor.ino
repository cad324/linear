#include <Stepper.h>

// number of steps per internal motor revolution
const float STEPS_PER_REV = 32;

// amount of gear reduction
const float GEAR_RED = 64;

// number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

// number of steps required
int steps_required;

// create instance of stepper class
// specify pins used for motor coils
Stepper steppermotor(STEPS_PER_REV, 18, 16, 19, 17);

void setup() {

}

void loop() {
  // slow – 4-step CW sequence to observe lights on driver board
//  steppermotor.setSpeed(1);
//  steps_required = 4;
//  steppermotor.step(steps_required);
//  delay(1000);

  // rotate CW 1/2 turn slowly
  steps_required = STEPS_PER_OUT_REV / 2;
  steppermotor.setSpeed(500);
  steppermotor.step(steps_required);
  delay(1000);

  // rotate CCW 1/2 turn slowly
  steps_required = -STEPS_PER_OUT_REV / 2;
  steppermotor.setSpeed(500);
  steppermotor.step(steps_required);
  delay(1000);

  // rotate CCW 1/2 turn quickly
//  steps_required = - STEPS_PER_OUT_REV / 2;
//  steppermotor.setSpeed (100);
//  steppermotor.step(-steps_required);
//  delay(2000);
}
