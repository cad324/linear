#include <AccelStepper.h>
// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::FULL4WIRE, 53, 49, 51, 47);
AccelStepper stepper2(AccelStepper::FULL4WIRE, 45, 41, 43, 39);
AccelStepper stepper3(AccelStepper::FULL4WIRE, 37, 33, 35, 31);
AccelStepper stepper4(AccelStepper::FULL4WIRE, 52, 48, 50, 46);
AccelStepper stepper5(AccelStepper::FULL4WIRE, 44, 40, 42, 38);
AccelStepper stepper6(AccelStepper::FULL4WIRE, 36, 32, 34, 30);

AccelStepper steppers[] = {stepper1, stepper2, stepper3, stepper4, stepper5, stepper6};

const int LED = 12;

void setup()
{
    pinMode(LED, OUTPUT);
    int max_speed = 500;
    Serial.begin(9600);
    for (int i = 0; i < 30; i++) {
      steppers[i].setMaxSpeed(max_speed);
      steppers[i].setAcceleration(100.0);
    }
    stepper1.setMaxSpeed(max_speed);
    stepper1.setAcceleration(100.0);
//    stepper3.setMaxSpeed(max_speed);
//    stepper3.setAcceleration(100.0);
//    stepper4.setMaxSpeed(max_speed);
//    stepper4.setAcceleration(100.0);
//    stepper5.setMaxSpeed(max_speed);
//    stepper5.setAcceleration(100.0);
//    stepper6.setMaxSpeed(max_speed);
//    stepper6.setAcceleration(100.0);
//    
//    stepper2.setMaxSpeed(500.0);
//    stepper2.setAcceleration(100.0);
//    
//    stepper3.setMaxSpeed(300.0);
//    stepper3.setAcceleration(100.0);
//    stepper3.moveTo(100000); 
}
void loop()
{
    // Change direction at the limits
//    if (stepper1.distanceToGo() == 0)
//        stepper1.moveTo(-stepper1.currentPosition());
//    stepper1.run();
//    stepper2.run();
//    stepper3.run();
  if (Serial.available() >= 30) {
    for (int i = 0; i < 30; i++) {
      byte incoming = Serial.read();
      if (incoming == '1') {
        digitalWrite(LED, HIGH);
        stepper1.moveTo(1000);
        stepper1.run();
        steppers[i].moveTo(1000);
        steppers[i].run();
      } else {
        digitalWrite(LED, LOW);
      }
   }

//    if (incoming_char == '1') {
//      stepper1.moveTo(1000);
//    }
//    if (incoming_char == '2') {
//      stepper2.moveTo(1000);
//    }
//    if (incoming_char == '3') {
//      stepper3.moveTo(1000);
//    }
//    if (incoming_char == '4') {
//      stepper4.moveTo(1000);
//    }
//    if (incoming_char == '5') {
//      stepper5.moveTo(1000);
//    }
//    if (incoming_char == '6') {
//      stepper6.moveTo(1000);
//    }
  }
  //moving adjacent blocks back to rest (position 0)
//  if (stepper1.distanceToGo() < 999 & stepper1.distanceToGo() > 0) {
//    stepper2.moveTo(0);
//  }
//  if (stepper2.distanceToGo() < 999 & stepper2.distanceToGo() > 0) {
//    stepper1.moveTo(0);
//    stepper3.moveTo(0);
//  }
//  if (stepper3.distanceToGo() < 999 & stepper3.distanceToGo() > 0) {
//    stepper2.moveTo(0);
//    stepper4.moveTo(0);
//  }
//  if (stepper4.distanceToGo() < 999 & stepper4.distanceToGo() > 0) {
//    stepper5.moveTo(0);
//    stepper6.moveTo(0);
//  }
//  if (stepper5.distanceToGo() < 999 & stepper5.distanceToGo() > 0) {
//    stepper6.moveTo(0);
//    stepper4.moveTo(0);
//  }
//  if (stepper6.distanceToGo() < 999 & stepper6.distanceToGo() > 0) {
//    stepper5.moveTo(0);
//  }
//  stepper1.run();
//  stepper2.run();
//  stepper3.run();
//  stepper4.run();
//  stepper5.run();
//  stepper6.run();
}
