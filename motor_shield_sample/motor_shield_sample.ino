/*
 SEEED Studio Stepper Motor Control - one revolution
 
 Adapts the Stepper example for use with the SEEED STUDIO motor shield.
 This program drives a unipolar or bipolar stepper motor
 by using the included Stepper library of the Arduino.
 The motor is attached to the Seeed Studio motor shield and an Arduino.
 
 The digital pins 8,11,12,13 drive the L298N and are used when creating the stepper object
 Digital pins 9 and 10 must be high to enable the chip.
 
 The motor should revolve one revolution in one direction, then
 one revolution in the other direction. 
 
 
 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe
 Modified 4 July 2012
 By R. Dumouchelle
 
 */
 
#include <Stepper.h>
 
int pinI1=8;//define I1 interface
int pinI2=11;//define I2 interface 


 
const int stepsPerRevolution = 85;  // change this to fit the number of steps per revolution
// for your motor
 
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,11,12,13);           
 
void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(210);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
  digitalWrite(pinI1,LOW);
}
 
void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(800);
  delay(1000);
 
  //step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-800);
  delay(1000);
}

