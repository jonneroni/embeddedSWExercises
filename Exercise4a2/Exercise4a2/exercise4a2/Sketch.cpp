/* Exercise4a2
Authors: Jonne Kaajalahti, Anton Leinonen
Using interrupts, red LEDs change state depending on the states of green and yellow LED
*/
#include <Arduino.h>

#define RED_LED1 4
#define RED_LED2 5
#define YELLOW_LED 3
#define GREEN_LED 2
volatile byte stateGreen = HIGH;
volatile byte stateYellow = LOW;

void blinkRed1(){
	// ISR function, RED_LED1 turns on when GREEN_LED is off and vice versa
	stateGreen = !stateGreen;
	digitalWrite(RED_LED1, stateGreen);
}

void blinkRed2(){
	// ISR function, RED_LED2 turns on when YELLOW_LED is on and vice versa
	stateYellow = !stateYellow;
	digitalWrite(RED_LED2, stateYellow);
}

// function to blink green and yellow LEDs so that green is on (and off) for 1 second and yellow is on (and off) for 0.5 seconds
void blinkGreenYellow(){
	digitalWrite(GREEN_LED, HIGH);
	digitalWrite(YELLOW_LED, HIGH);
	delay(500);
	digitalWrite(YELLOW_LED, LOW);
	delay(500);
	digitalWrite(GREEN_LED, LOW);
	digitalWrite(YELLOW_LED, HIGH);
	delay(500);
	digitalWrite(YELLOW_LED, LOW);
	delay(500);
}

void setup() {
	pinMode(RED_LED1, OUTPUT);
	pinMode(RED_LED2, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	attachInterrupt(digitalPinToInterrupt(GREEN_LED), blinkRed1, CHANGE);
	attachInterrupt(digitalPinToInterrupt(YELLOW_LED), blinkRed2, CHANGE);
}

void loop() {
	blinkGreenYellow();
}