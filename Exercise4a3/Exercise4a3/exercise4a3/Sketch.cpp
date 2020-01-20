/* Exercise4a3, Sketch.cpp
Authors: Jonne Kaajalahti, Anton Leinonen	
Creating traffic lights with interrupts
*/

#include <Arduino.h>
#define REDLED 2
#define YELLOWLED 4
#define GREENLED 3
volatile byte stateRed = HIGH;
volatile byte stateGreen = HIGH;

// ISR functions for red and green LEDs
void redToYellow() {
	// yellow LEDs state changes when red is turned ON
	stateRed = !stateRed;
	digitalWrite(YELLOWLED, stateRed);
}

void greenToYellow() {
	// yellow LEDs state changes according to green LEDs state (when green is either turned ON or OFF)
	stateGreen = !stateGreen;
	digitalWrite(YELLOWLED, stateGreen);
}

void trafficLights() {
	// a function that turns red and green LEDs on and off allowing the yellow LED to interrupt
	digitalWrite(REDLED, HIGH);
	delay(2000);
	digitalWrite(REDLED, LOW);
	digitalWrite(REDLED, HIGH);
	delay(2000);
	digitalWrite(REDLED, LOW);
	digitalWrite(GREENLED, HIGH);
	delay(2000);
	digitalWrite(GREENLED, LOW);
	delay(2000);
}

void setup() {	
	pinMode(REDLED, OUTPUT);
	pinMode(GREENLED, OUTPUT);
	pinMode(YELLOWLED, OUTPUT);
	attachInterrupt(digitalPinToInterrupt(REDLED), redToYellow, RISING);	// RISING means that whenever the red LED turns ON, yellow LED changes its state
	attachInterrupt(digitalPinToInterrupt(GREENLED), greenToYellow, CHANGE);	// CHANGE means that whenever green LED changes its state, yellow LED changes also
}

void loop() {
	trafficLights();
}

