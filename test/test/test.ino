#include <AccelStepper.h>

// Define all of the steppers
AccelStepper stepper1(AccelStepper::FULL4WIRE, 53, 49, 51, 47);
AccelStepper stepper2(AccelStepper::FULL4WIRE, 45, 41, 43, 39);
AccelStepper stepper3(AccelStepper::FULL4WIRE, 37, 33, 35, 31);
AccelStepper stepper4(AccelStepper::FULL4WIRE, 29, 25, 27, 23);
AccelStepper stepper5(AccelStepper::FULL4WIRE, 52, 48, 50, 46);
AccelStepper stepper6(AccelStepper::FULL4WIRE, 44, 40, 42, 38);
AccelStepper stepper7(AccelStepper::FULL4WIRE, 36, 32, 34, 30);
AccelStepper stepper8(AccelStepper::FULL4WIRE, 28, 24, 26, 22);
AccelStepper stepper9(AccelStepper::FULL4WIRE, 2, 4, 3, 5);
AccelStepper stepper10(AccelStepper::FULL4WIRE, 6, 8, 7, 9);
//AccelStepper stepper11(AccelStepper::FULL4WIRE, 53, 49, 51, 47);
//AccelStepper stepper12(AccelStepper::FULL4WIRE, 45, 41, 43, 39);
//AccelStepper stepper13(AccelStepper::FULL4WIRE, 37, 33, 35, 31);
//AccelStepper stepper14(AccelStepper::FULL4WIRE, 29, 25, 27, 23);
//AccelStepper stepper15(AccelStepper::FULL4WIRE, 52, 48, 50, 46);
//AccelStepper stepper16(AccelStepper::FULL4WIRE, 44, 40, 42, 38);
//AccelStepper stepper17(AccelStepper::FULL4WIRE, 36, 32, 34, 30);
//AccelStepper stepper18(AccelStepper::FULL4WIRE, 28, 24, 26, 22);
//AccelStepper stepper19(AccelStepper::FULL4WIRE, 2, 4, 3, 5);
//AccelStepper stepper20(AccelStepper::FULL4WIRE, 6, 8, 7, 9);
//AccelStepper stepper21(AccelStepper::FULL4WIRE, 53, 49, 51, 47);
//AccelStepper stepper22(AccelStepper::FULL4WIRE, 45, 41, 43, 39);
//AccelStepper stepper23(AccelStepper::FULL4WIRE, 37, 33, 35, 31);
//AccelStepper stepper24(AccelStepper::FULL4WIRE, 29, 25, 27, 23);
//AccelStepper stepper25(AccelStepper::FULL4WIRE, 52, 48, 50, 46);
//AccelStepper stepper26(AccelStepper::FULL4WIRE, 44, 40, 42, 38);
//AccelStepper stepper27(AccelStepper::FULL4WIRE, 36, 32, 34, 30);
//AccelStepper stepper28(AccelStepper::FULL4WIRE, 28, 24, 26, 22);
//AccelStepper stepper29(AccelStepper::FULL4WIRE, 2, 4, 3, 5);
//AccelStepper stepper30(AccelStepper::FULL4WIRE, 6, 8, 7, 9);

AccelStepper steppersOne[] = {stepper1, stepper2, stepper3, stepper4, stepper5, stepper6, stepper7, stepper8, stepper9, stepper10};
//AccelStepper steppersTwo[] = {stepper11, stepper12, stepper13, stepper14, stepper15, stepper16, stepper17, stepper18, stepper19, stepper20};
//AccelStepper steppersThree[] = {stepper21, stepper22, stepper23, stepper24, stepper25, stepper26, stepper27, stepper28, stepper29, stepper30};

const int LED = 12;
const int MAX_SPEED = 500;
const int MAX_EXTENSION = 1000;

// Initialize all motor positions to be 0
int motor_pos[30] = { 0 };

int get_depth(byte c) {
  switch (c) {
    case '0':
      return 0;
    case '1':
      return MAX_EXTENSION / 9;
    case '2':
      return 2 * MAX_EXTENSION / 9;
    case '3':
      return 3 * MAX_EXTENSION / 9;
    case '4':
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

int get_stepper(byte motor) {
  switch (motor) {
    case 'a':
      return 0;
    case 'b':
      return 1;
    case 'c':
      return 2;
    case 'd':
      return 3;
    case 'e':
      return 4;
    case 'f':
      return 5;
    case 'g':
      return 6;
    case 'h':
      return 7;
    case 'i':
      return 8;
    case 'j':
      return 9;
  }
}

void moveMotor(AccelStepper steppers[], int motor, byte incoming) {
  int pos = motor_pos[motor];
  int depth = get_depth(incoming);
  motor_pos[motor%10] = depth;

  // Move the motor from the current position to the specified depth
  int move_val = constrain(depth - pos, -MAX_EXTENSION, MAX_EXTENSION);
  steppers[motor%10].moveTo(move_val); 
}

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
//    Serial1.begin(9601);
//    Serial2.begin(9602);
    for (int i = 0; i < 10; i++) {
      steppersOne[i].setMaxSpeed(MAX_SPEED);
      steppersOne[i].setAcceleration(100.0);
//      steppersTwo[i].setMaxSpeed(MAX_SPEED);
//      steppersTwo[i].setAcceleration(100.0);
//      steppersThree[i].setMaxSpeed(MAX_SPEED);
//      steppersThree[i].setAcceleration(100.0);
    }

    stepper1.setMaxSpeed(MAX_SPEED);
    stepper1.setAcceleration(100.0);
}

void loop()
{
    // Change direction at the limits
//    if (stepper1.distanceToGo() == 0)
//        stepper1.moveTo(-stepper1.currentPosition());
//    stepper1.run();
//    stepper2.run();
//    stepper3.run();

// Loop through all of the motors to check their position
    if (Serial.available() > 9) {
      digitalWrite(LED, HIGH);
      for (int i = 0; i < 10; i++) {
        byte depth = Serial.read();
        steppersOne[i].moveTo(get_depth(depth));
//        digitalWrite(LED, HIGH);
//        byte incoming_depth = Serial.read();
//        moveMotor(steppersOne, i, incoming_depth);
      } 
    }

//    if (Serial.available() >= 2) {
//      digitalWrite(LED, HIGH);
//      byte incoming_motor = Serial.read();
//      int motor = get_stepper(incoming_motor);
//      byte incoming_depth = Serial.read();
//      moveMotor(steppersOne, motor, incoming_depth);
//    }
//    if (Serial1.available() >= 2) {
//      byte incoming_motor = Serial1.read();
//      int motor = get_stepper(incoming_motor) + 10;
//      byte incoming_depth = Serial1.read();
//      moveMotor(steppersTwo, motor, incoming_depth);
//    }
//    if (Serial2.available() >= 2) {
//      byte incoming_motor = Serial2.read();
//      int motor = get_stepper(incoming_motor) + 20;
//      byte incoming_depth = Serial2.read();
//      moveMotor(steppersThree, motor, incoming_depth);
//    }


  // Run all of the motors 
  for (int i = 0; i < 10; i++) {
    if (i < 10) {
      steppersOne[i].run();
    } 
//    else if (i >= 10 && i < 20) {
//      steppersTwo[i-10].run();
//    } else {
//      steppersThree[i-20].run();
//    }
  }
}
