/*
Exercise 5a2
Anton Leinonen & Jonne Kaajalahti
The code gets a temperature reading from a thermistor, returns it as Celsius and based on that turns a LED on.
It also blinks a yellow LED based on the LSB of two's complement of a voltage reading, that we also get from the thermistor.
There's a timer interrupt to blink the red LED about once a second.
*/
#include <Arduino.h>
#include "Thermistor.h"
#include "Math.h"
#include "Led.h"
volatile int timerOneCounter = 0;

void setup() {
	pinMode(THERMISTOR_PIN, INPUT);
	pinMode(RED_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
	
	// initialize timer1
	noInterrupts();           // disable all interrupts
	TCCR1A = 0;
	TCCR1B = 0;

	// Set timerOneCounter to the correct value for our interrupt interval
	timerOneCounter = 3424;   // preload timer 65536-16MHz/256/1Hz

	TCNT1 = timerOneCounter;   // preload timer
	TCCR1B |= (1 << CS12);    // 256 prescaler
	TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
	interrupts();
}

ISR(TIMER1_OVF_vect)        // interrupt service routine
{
	TCNT1 = timerOneCounter;   // preload timer
	digitalWrite(RED_LED, digitalRead(RED_LED) ^ 1);
}

void loop() {
	float celsiusTemperature = getTemperature(); // gets temperature reading from the thermistor
	
	if (celsiusTemperature < 25.00){
		// turns the green LED on if it's colder than 25 degrees
		greenLedOn();
	}
	
	else if (celsiusTemperature >= 25.00){
		// turns the red LED on if it's 25 degrees or warmer
		redLedOn();
	}
	
	delay(1000);
	ledOff(); // calls the function ledOff()
	//delay(200);
	
	int voltage = getVoltage(); // gets a voltage reading from the thermistor
	
	int bit = checkBit(voltage); // checks LSB of two's complement of voltage
	
	for (int i = 0; i < 5; i++){
		if (bit == 1){
			// if LSB of two's complement is 1, gives the function yellowLedBlink a value of 1000
			yellowLedBlink(1000); // calls the function yellowLedBlink with a value of 1000 milliseconds (1 second)
		}
		
		else if (bit == 0){
			// if LSB of two's complement is 0, gives the function yellowLedBlink a value of 200
			yellowLedBlink(200); // calls the function yellowLedBlink with a value of 200 milliseconds (0.2 seconds)
		}
	}
}
