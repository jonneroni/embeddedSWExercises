/*
Thermistor.cpp
Anton Leinonen & Jonne Kaajalahti
Reads thermistor voltage and if called, converts it into a Celsius value.
*/
#include <Arduino.h>
#include "Thermistor.h"

float getTemperature(){
	volatile int thermistorValue = 0;
	volatile float celsiusTemperature = 0;
	thermistorValue = analogRead(THERMISTOR_PIN);
	celsiusTemperature = thermistorToCelsiusConverter(thermistorValue);
	return (celsiusTemperature);
}

float thermistorToCelsiusConverter(int thermValue){
	// this function converts the thermistor reading into a Celsius value based on the given Look-up Table
	int i = 0;
	int differenceThermistorStep = 0;
	float differenceCelsiusStep = 0;
	int differenceValues = 0;
	float percentage = 0;
	float finalTemp = 0;
	for (i = 0; i < 32; i++){ // we search the correct position of the thermistor reading in the Look-up Table (for example between 475 and 500)
		if (thermValue < LUTThermistor[i]){
			break;
		}
	}
	// calculating the Celsius value
	differenceThermistorStep = LUTThermistor[i+1] - LUTThermistor[i];
	differenceCelsiusStep = LUTCelsius[i+1] - LUTCelsius[i];
	differenceValues = thermValue - LUTThermistor[i];
	percentage = (float)differenceValues / differenceThermistorStep;
	
	return ((percentage*differenceCelsiusStep) + LUTCelsius[i]);
}

int getVoltage(){
	// this function reads the thermistor and returns a voltage value
	int voltage = analogRead(THERMISTOR_PIN);
	return (voltage);
}