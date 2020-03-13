/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo baseServo, elbow1Servo, elbow2Servo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
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

const int deadband = 50;

int basePos = 0;    // variable to store the servo position 
int elbow1Pos = 0;    // variable to store the servo position 
int elbow2Pos = 0;    // variable to store the servo position 
int valueX = 0;
int valueY = 0;
 
void setup() 
{ 
  baseServo.attach(baseCmdPin);  // attaches the servo on pin 6 to the servo object 
  elbow1Servo.attach(elbow1CmdPin);  // attaches the servo on pin 6 to the servo object 
  elbow2Servo.attach(elbow2CmdPin);  // attaches the servo on pin 6 to the servo object 
  Serial.begin(9600);
} 

int joyValue(int value, int pos, int minAngle, int maxAngle)
{
  if (value > 512 + deadband) pos = pos + 1;
  if (value < 512 - deadband) pos = pos - 1;
  if (pos > maxAngle) pos = maxAngle;
  if (pos < minAngle) pos = minAngle;  
  return pos;
}
 
void loop() 
{ 
  valueX = analogRead(inputXPin);
  //delay(100);
  valueY = analogRead(inputYPin);
  //delay(100);
  elbow1Pos = joyValue(valueX, elbow1Pos, elbow1MinAngle, elbow1MaxAngle);
  elbow2Pos = joyValue(valueY, elbow2Pos, elbow2MinAngle, elbow2MaxAngle);
  elbow1Servo.write(elbow1Pos);
  delay(15);
  elbow2Servo.write(elbow2Pos);  
  delay(15);
//  for(pos = 70; pos <= 120; pos += 1) // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    Serial.println(analogRead(A0));
//    delay(15);                       // waits 15ms for the servo to reach the position 
//  } 
//  for(pos = 120; pos>=70; pos-=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    Serial.println(analogRead(A0));
//    delay(15);                       // waits 15ms for the servo to reach the position 
//  } 
//  Serial.println("Motor 1");
//  Serial.println(analogRead(A0));
//  Serial.println("Motor 2");
//  Serial.println(analogRead(A1));
//  Serial.println("Motor 3");
//  Serial.println(analogRead(A2));
//  delay(1000);
} 
