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

AccelStepper steppers[] = {stepper1, stepper2, stepper3, stepper4, stepper5, stepper6, stepper7, stepper8, stepper9, stepper10};

// Char representation of 
const int motors[] = {
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
  'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D'
};

const int LED = 12;
const int LEDDepthError = 14;
const int LEDMotorError = 16;
const int MAX_SPEED = 500;
const int MAX_EXTENSION = 2500;

// Initialize all motor positions to be 0
int motor_pos[10] = { 0 };

int get_depth(byte c) {
  digitalWrite(LEDDepthError, LOW);
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
      digitalWrite(LEDDepthError, HIGH);
      Serial.println("Something is wrong on the Kinect side");
  }
}

int get_stepper(byte c) {
  digitalWrite(LEDMotorError, LOW);
  for (int i = 0; i < 30; i++) {
    if (motors[i] == c) {
      return i;
    }
  }
  digitalWrite(LEDMotorError, HIGH);
  Serial.println("Not sending an ASCII code");
}

void moveMotor(int motor, byte incoming) {
  int pos = motor_pos[motor];
  int depth = get_depth(incoming);
  motor_pos[motor] = depth;

  // Move the motor from the current position to the specified depth
  int move_val = depth - pos;
  steppers[motor].moveTo(move_val); 
}

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(LEDMotorError, OUTPUT);
    pinMode(LEDDepthError, OUTPUT);
    Serial.begin(9600);
    for (int i = 0; i < 10; i++) {
      steppers[i].setMaxSpeed(MAX_SPEED);
      steppers[i].setAcceleration(100.0);
    }
}

void loop()
{
// Loop through all of the motors to check their position
    if (Serial.available() > 18) {
      digitalWrite(LED, HIGH);
      for (int i = 0; i < 10; i++) {
//        byte depth = Serial.read();
//        steppers[i].moveTo(get_depth(depth));
//        byte incoming_motor = Serial.read();
//        int motor = get_stepper(incoming_motor) % 10;
        byte incoming_depth = Serial.read();
        moveMotor(i, incoming_depth);
      } 
    }

  // Run all of the motors 
  for (int i = 0; i < 10; i++) {
    steppers[i].run();
  }
}
