/* Sketch.cpp
Author: Jonne Kaajalahti
Program to read the environments temperature from a sensor and converting the sensors
raw data to Celsius using lookup table.
 */

#include <Arduino.h>


#define THERM_PIN 0

// struct for the look-up table
typedef struct {
	float c;
	float thermistor;
}temperatureType;

// first values represent Celsius degrees and second ones the sensors values
temperatureType Temp[32] = {
	{1.4, 250},
	{4.0, 275},
	{6.4, 300},
	{8.8, 325},
	{11.1, 350},
	{13.4, 375},
	{15.6, 400},
	{17.8, 425},
	{20.0, 450},
	{22.2, 475},
	{24.4, 500},
	{26.7, 525},
	{29.0, 550},
	{31.3, 575},
	{33.7, 600},
	{36.1, 625},
	{38.7, 650},
	{41.3, 675},
	{44.1, 700},
	{47.1, 725},
	{50.2, 750},
	{53.7, 775},
	{55.0, 784},
	{61.5, 825},
	{66.2, 850},
	{71.5, 875},
	{77.9, 900},
	{85.7, 925},
	{90.3, 937},
	{96.0, 950},
	{111.2, 975},
	{139.5, 1000},					
};


void setup() {
	pinMode(THERM_PIN, INPUT);	
}


float thermToCelsius(int thermistorValue);

void loop() {
	volatile int thermistorValue = 0;	// we initialize the variables as volatile in order to see the values change without serial monitor etc.
	volatile float celsiusValue = 0.0;
	thermistorValue = analogRead(THERM_PIN);	// read the thermal value from the sensor
	celsiusValue = thermToCelsius(thermistorValue);
}	


float thermToCelsius(int thermValue) {
	// loops around 32 times (32 values in Look-up tables)
	for(int i=0 ; i < 32 ; i++) {
		// if the sensors reading is found in the look-up table, return the according Celsius value
		if(thermValue == Temp[i].thermistor) {  
			return Temp[i].c; 
		// if the reading is between 2 values in the look-up table, return the average of the according Celsius values
		} else if (thermValue > Temp[i].thermistor && thermValue < Temp[i+1].thermistor) {
			return (Temp[i].c + Temp[i+1].c) / 2;
		}
	}
}

