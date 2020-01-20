/*
File: Sketch.cpp
Authors: Jonne Kaajalahti, Anton Leinonen
Make servo spin according to two LDR sensors readings (HIGH or LOW)
*/
#include <Arduino.h>
#include "LDR.h"
#include "ServoMotor.h"


void setup() {
	pinMode(LDR_PIN1, INPUT);	// initialize LDR pins as inputs
	pinMode(LDR_PIN2, INPUT);
}


void loop() {
	
	if (LDRRead1() >= 150 && LDRRead2() < 150) {	// if LDR1 is HIGH and LDR2 is LOW, spin servo clockwise
		rotateClockwise();
	}
	else if (LDRRead1() < 150 && LDRRead2() >= 150) {	// if LDR1 is LOW and LDR2 is HIGH, spin servo counterclockwise
		rotateCounterClockwise();
	}
	else {
		servoStop();	// if both LDRs are either high or low, stop the servo
	}
}
