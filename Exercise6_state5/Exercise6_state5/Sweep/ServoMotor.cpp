/*
File: Servo.cpp
Authors: Jonne Kaajalahti, Anton Leinonen
Functions to rotate or stop the servo motor
 */ 

#include <Arduino.h>
#include <Servo.h>
#include "ServoMotor.h"

Servo myservo;  // create servo object to control a servo

void rotateClockwise() {
	myservo.attach(SERVO_PIN);	// attaches the servo on SERVO_PIN to the servo object
	myservo.write(0);	// makes the servo spin clockwise (towards position 0)
}

void rotateCounterClockwise() {
	myservo.attach(SERVO_PIN);	// attaches the servo on SERVO_PIN to the servo object
	myservo.write(180);	// makes the servo spin counterclockwise (towards position 180)
}

void servoStop() {
	myservo.detach();	// detaches SERVO_PIN from the servo object
}