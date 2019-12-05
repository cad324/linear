#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Stepper.h>

// number of steps per internal motor revolution
const float STEPS_PER_REV = 32;

// amount of gear reduction
const float GEAR_RED = 64;

// number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

// number of steps required
int steps_required = 100;

// max speed
const int speed_max = 700;

//3D coordinate arrays - x,y,z
int point3D[4];

int point_index = 0; //index for point3D

String point = ""; //x,y, or z point as a string

//Coordinates corresponding to both blocks
int block1_bucket[] = {1, 2, 3};
int block2_bucket[] = {4, 5, 6};

// create instance of stepper class
// specify pins used for motor coils
//Stepper steppermotor(STEPS_PER_REV, 18, 16, 19, 17);
//Stepper steppermotor2(STEPS_PER_REV, 32, 22, 14, 23);
AccelStepper stepper1(AccelStepper::FULL4WIRE, 53, 49, 51, 47);
AccelStepper stepper2(AccelStepper::FULL4WIRE, 45, 41, 43, 39);
AccelStepper stepper3(AccelStepper::FULL4WIRE, 37, 33, 35, 31);
AccelStepper stepper4(AccelStepper::FULL4WIRE, 52, 48, 50, 46);
AccelStepper stepper5(AccelStepper::FULL4WIRE, 44, 40, 42, 38);
AccelStepper stepper6(AccelStepper::FULL4WIRE, 36, 32, 34, 30);
//Stepper stepperMotor1 = Stepper(0, 53, 49, 51, 47);
//Stepper stepperMotor2 = Stepper(0, 45, 41, 43, 39);
//Stepper stepperMotor3 = Stepper(0, 37, 33, 35, 31);
//Stepper stepperMotor4 = Stepper(0, 52, 48, 50, 46);
//Stepper stepperMotor5 = Stepper(0, 44, 40, 42, 38);
//Stepper stepperMotor6 = Stepper(0, 36, 32, 34, 30);
MultiStepper steppers;

// Initialize stepper
Stepper stepperMotor1(STEPS_PER_REV, 53, 49, 51, 47);
Stepper stepperMotor2(STEPS_PER_REV, 45, 41, 43, 39);
Stepper stepperMotor3(STEPS_PER_REV, 37, 33, 35, 31);
Stepper stepperMotor4(STEPS_PER_REV, 52, 48, 50, 46);
Stepper stepperMotor5(STEPS_PER_REV, 44, 40, 42, 38);
Stepper stepperMotor6(STEPS_PER_REV, 36, 32, 34, 30);

//turns motor to raise block
void stepUp(Stepper stepperMotor) {
  steps_required = STEPS_PER_OUT_REV / 2;
  stepperMotor.setSpeed(1000);
  stepperMotor.step(steps_required);
}

//turns motor to return block to position
void stepDown(Stepper stepperMotor) {
  steps_required = - STEPS_PER_OUT_REV / 2;
  stepperMotor.setSpeed(1000);
  stepperMotor.step(-steps_required);
}

//compare whether 2 arrays are equal
boolean array_cmp(int *a, int *b){
     int len_a = sizeof(a);
     int len_b = sizeof(b);
     if (len_a != len_b) return false;
     for (int n=0;n<3;n++) if (a[n]!=b[n]) return false;

     //ok, if we have not returned yet, they are equal :)
     return true;
}

void setup() {
  Serial.begin(9600);
  Serial.println("starting...");
  stepperMotor1.setSpeed(speed_max);
  stepperMotor2.setSpeed(speed_max);
  stepperMotor3.setSpeed(speed_max);
  stepperMotor4.setSpeed(speed_max);
  stepperMotor5.setSpeed(speed_max);
  stepperMotor6.setSpeed(speed_max);
  stepper1.setMaxSpeed(speed_max);
  stepper2.setMaxSpeed(speed_max);
  stepper3.setMaxSpeed(speed_max);
  stepper4.setMaxSpeed(speed_max);
  stepper5.setMaxSpeed(speed_max);
  stepper6.setMaxSpeed(speed_max);
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
//  steppers.addStepper(stepper3);
//  steppers.addStepper(stepper4);
//  steppers.addStepper(stepper5);
//  steppers.addStepper(stepper6);
}

void loop() {

  
//  long positions[2]; // Array of desired stepper positions
//  
//  positions[0] = 1000;
//  positions[1] = 50;
//  steppers.moveTo(positions);
////  stepper1.runSpeedToPosition();
//  steppers.runSpeedToPxosition(); // Blocks until all are in position
//  delay(500);

  stepperMotor1.step(4);
  stepperMotor2.step(4);
//  stepperMotor3.step(4);
//  stepperMotor4.step(4);
//  stepperMotor5.step(4);
//  stepperMotor6.step(4);

  if (Serial.available() > 0) {
    int incoming = Serial.read();
    char incoming_char = (char) incoming;
    if (incoming_char == '1') {
      stepUp(stepperMotor1);
    }
    if (incoming_char == '2') {
      stepUp(stepperMotor2);
    }
    if (incoming_char == '3') {
      stepUp(stepperMotor3);
    }
    if (incoming_char == '4') {
      stepUp(stepperMotor4);
    }
    if (incoming_char == '5') {
      stepUp(stepperMotor1);
    }
    if (incoming_char == '6') {
      stepUp(stepperMotor1);
    }
  }
  
  // Move to a different coordinate
//  positions[0] = -100;
//  positions[1] = 100;
//  steppers.moveTo(positions);
////  stepper1.runSpeedToPosition();
//  steppers.runSpeedToPosition(); // Blocks until all are in position
//  delay(500);

  
  // slow – 4-step CW sequence to observe lights on driver board
//  steppermotor.setSpeed(1);
//  steps_required = 4;
//  steppermotor.step(steps_required);
//  delay(1000);

//  if (Serial.available() > 0) {
//    int incoming = Serial.read();
//    char incoming_char = (char) incoming;
//    if (incoming_char == ',') {
//      point3D[point_index] = point.toInt();
//      ++point_index;
//      point = "";
//    } else if (incoming_char == '.') {
//      // rotate CW 1/2 turn slowly
//      point3D[point_index] = point.toInt();
//      if (array_cmp(point3D, block1_bucket)) {
////        stepUp(steppermotor);
////        stepDown(steppermotor2);
//        int steps_required = STEPS_PER_OUT_REV / 2;
//        for (int i = 0; i < steps_required; i++) {
//          steppermotor.setSpeed(1000);
//          steppermotor2.setSpeed(1000);
//          steppermotor.step(1);
//          steppermotor2.step(1);
//        }
//      } else if (array_cmp(point3D, block2_bucket)) {
//        stepDown(steppermotor);
//        stepUp(steppermotor2);
//      }
//      point_index = 0;
//      point = "";
//      
//    } else {
//      point += String(incoming_char);
//    }
//    Serial.println(incoming_char);
//  }
}
