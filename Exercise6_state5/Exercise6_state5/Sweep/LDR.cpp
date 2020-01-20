/*
File: LDR.cpp
Authors: Jonne Kaajalahti, Anton Leinonen
Functions to read the LDR sensors values and return them as integers
*/ 

#include <Arduino.h>
#include "LDR.h"


int LDRRead1() {
	int LDRValue1 = 0;
	LDRValue1 = analogRead(LDR_PIN1);	// read LDR_PIN1 value and return it
	return LDRValue1;
}

int LDRRead2() {
	int LDRValue2 = 0;
	LDRValue2 = analogRead(LDR_PIN2);	// read LDR_PIN2 value and return it
	return LDRValue2;
}
