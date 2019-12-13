#include <AccelStepper.h>

const int LED = 12;

//AccelStepper stepper(AccelStepper::FULL4WIRE, 44, 40, 42, 38);
AccelStepper stepper(AccelStepper::FULL4WIRE, 53, 49, 51, 47);
//AccelStepper stepper(AccelStepper::FULL4WIRE, 37, 33, 35, 31);
//AccelStepper stepper(AccelStepper::FULL4WIRE, 29, 25, 27, 23);

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  stepper.setMaxSpeed(500);
  stepper.setAcceleration(100.0);
  stepper.moveTo(2500);
  stepper.run();
}

void loop() {
  // put your main code here, to run repeatedly:

}
