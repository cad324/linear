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
const int MAX_EXTENSION = 1000;

// Initialize all motor positions to be 0
int motor_pos[30] = { 0 };

int get_depth(byte c) {
  switch (c) {
    case '0':
      return 0;
    case '1':
      return MAX_EXTENSION / 10;
    case '2':
      return 2 * MAX_EXTENSION / 9;
    case '3':
      return 3 * MAX_EXTENSION / 9;
    case '4'
      return 4 * MAX_EXTENSION / 9;
    case '5':
      return 5 * MAX_EXTENSION / 9;
    case '6':
      return 6 * MAX_EXTENSION / 9;
    case '7':
      return 7 * MAX_EXTENSION / 9;
    case '8':
      return 8 * MAX_EXTENSION / 9;
    case '9':
      return MAX_EXTENSION;
    default:
      Serial.println("Something is wrong on the Kinect side");
  }
}

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
      int pos = motor_pos[i];
      int depth = get_depth(incoming);
      motor_pos[i] = depth;
      int move_val = constrain(depth - pos, -MAX_EXTENSION, MAX_EXTENSION);
//    can this be negative?
      steppers[i].moveTo(move_val); 
      steppers[i].run(); 
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
