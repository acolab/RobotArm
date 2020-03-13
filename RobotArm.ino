/* RobotArm
 Thomas Trabattoni
*/ 

#include <Servo.h> 
 
Servo baseServo, elbow1Servo, elbow2Servo;  // create servo object to control a servo 

//Feedback range
//motor 4 range 32-970 base
//motor 5 range 145-575 elbow1
//motor 6 range 339-720 elbow2

const int baseCmdPin = 4;
const int baseFeedbackPin = A0;

const int elbow1CmdPin = 5;
const int elbow1FeedbackPin = A1;
const int elbow1MaxAngle = 100;
const int elbow1MinAngle = 0;


const int elbow2CmdPin = 6;
const int elbow2FeedbackPin = A2;
const int elbow2MaxAngle = 140;
const int elbow2MinAngle = 60;

const int inputXPin = A3;
const int inputYPin = A4;

const int deadband = 50;     //minimum deviation from center to be taken into consideration

int basePos = 0;    // variable to store the base servo position
int elbow1Pos = 0;    // variable to store the elbow1 servo position 
int elbow2Pos = 0;    // variable to store the elbow2 servo position 
int valueX = 0;   //variable to store joystick input value
int valueY = 0;   //variable to store joystick input value
 
void setup() 
{ 
  baseServo.attach(baseCmdPin);
  elbow1Servo.attach(elbow1CmdPin);
  elbow2Servo.attach(elbow2CmdPin);
  //Serial.begin(9600);
} 

int joyValue(int value, int pos, int minAngle, int maxAngle)
{
//Manage joystick input regarding deadband and servos angles limits
  if (value > 512 + deadband) pos = pos + 1;
  if (value < 512 - deadband) pos = pos - 1;
  if (pos > maxAngle) pos = maxAngle;
  if (pos < minAngle) pos = minAngle;  
  return pos;
}
 
void loop() 
{ 
  valueX = analogRead(inputXPin);
  valueY = analogRead(inputYPin);
  elbow1Pos = joyValue(valueX, elbow1Pos, elbow1MinAngle, elbow1MaxAngle);
  elbow2Pos = joyValue(valueY, elbow2Pos, elbow2MinAngle, elbow2MaxAngle);
  elbow1Servo.write(elbow1Pos);
  delay(15);
  elbow2Servo.write(elbow2Pos);  
  delay(15);
}
