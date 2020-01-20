/*
Led.cpp
Anton Leinonen & Jonne Kaajalahti
Turns different LEDs on and off
*/

#include <Arduino.h>
#include "Led.h"


void redLedOn(){
	// turns the red LED on
	digitalWrite(RED_LED, HIGH);
}

void greenLedOn(){
	// turns the green LED on
	digitalWrite(GREEN_LED, HIGH);
}

void ledOff(){
	// turns green and red LEDs off
	digitalWrite(GREEN_LED, LOW);
	digitalWrite(RED_LED, LOW);
}

void yellowLedBlink(int blinkDelay){
	// blinks the yellow LED with a delay that is calculated based on a voltage reading
	digitalWrite(YELLOW_LED, HIGH);
	delay(blinkDelay);
	digitalWrite(YELLOW_LED, LOW);
	delay(blinkDelay);
}