/* Exercise3a4
Authors: Jonne Kaajalahti & Anton Leinonen
Display temperature that the sensor is reading with 7-segment display
*/


#include <Arduino.h>

#define THERM_PIN 0

// pins for the 7-segment display
#define A_LED 2
#define B_LED 8
#define C_LED 6
#define D_LED 5
#define E_LED 4
#define F_LED 3
#define G_LED 7

// struct for the look-up table
typedef struct {
	float c;
	float thermistor;
}temperatureType;

// first values represent Celsius degrees and second ones the sensors values
const temperatureType Temp[32] = {
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

void onlyDOn() {
	digitalWrite(D_LED, LOW);
	digitalWrite(E_LED, HIGH);
	digitalWrite(F_LED, HIGH);
	digitalWrite(A_LED, HIGH);
	digitalWrite(G_LED, HIGH);
	digitalWrite(C_LED, HIGH);
	digitalWrite(B_LED, HIGH);
}
// functions for all numbers to be displayed on the 7-segment display
void number0() {
	digitalWrite(D_LED, LOW);
	digitalWrite(E_LED, LOW);
	digitalWrite(F_LED, LOW);
	digitalWrite(A_LED, LOW);
	digitalWrite(G_LED, HIGH);
	digitalWrite(C_LED, LOW);
	digitalWrite(B_LED, LOW);
	delay(250);
}

void number1() {
	digitalWrite(D_LED, HIGH);
	digitalWrite(E_LED, HIGH);
	digitalWrite(F_LED, HIGH);
	digitalWrite(A_LED, HIGH);
	digitalWrite(G_LED, HIGH);
	digitalWrite(C_LED, LOW);
	digitalWrite(B_LED, LOW);
	delay(250);
}

void number2() {
	digitalWrite(D_LED, LOW);
	digitalWrite(E_LED, LOW);
	digitalWrite(F_LED, HIGH);
	digitalWrite(A_LED, LOW);
	digitalWrite(G_LED, LOW);
	digitalWrite(C_LED, HIGH);
	digitalWrite(B_LED, LOW);
	delay(250);
}

void number3() {
	digitalWrite(D_LED, LOW);
	digitalWrite(E_LED, HIGH);
	digitalWrite(F_LED, HIGH);
	digitalWrite(A_LED, LOW);
	digitalWrite(G_LED, LOW);
	digitalWrite(C_LED, LOW);
	digitalWrite(B_LED, LOW);
	delay(250);
}

void number4() {
	digitalWrite(D_LED, HIGH);
	digitalWrite(E_LED, HIGH);
	digitalWrite(F_LED, LOW);
	digitalWrite(A_LED, HIGH);
	digitalWrite(G_LED, LOW);
	digitalWrite(C_LED, LOW);
	digitalWrite(B_LED, LOW);
	delay(250);
}

void number5() {
	digitalWrite(D_LED, LOW);
	digitalWrite(E_LED, HIGH);
	digitalWrite(F_LED, LOW);
	digitalWrite(A_LED, LOW);
	digitalWrite(G_LED, LOW);
	digitalWrite(C_LED, LOW);
	digitalWrite(B_LED, HIGH);
	delay(250);
}

void number6() {
	digitalWrite(D_LED, LOW);
	digitalWrite(E_LED, LOW);
	digitalWrite(F_LED, LOW);
	digitalWrite(A_LED, LOW);
	digitalWrite(G_LED, LOW);
	digitalWrite(C_LED, LOW);
	digitalWrite(B_LED, HIGH);
	delay(250);
}

void number7() {
	digitalWrite(D_LED, HIGH);
	digitalWrite(E_LED, HIGH);
	digitalWrite(F_LED, HIGH);
	digitalWrite(A_LED, LOW);
	digitalWrite(G_LED, HIGH);
	digitalWrite(C_LED, LOW);
	digitalWrite(B_LED, LOW);
	delay(250);
}

void number8() {
	digitalWrite(D_LED, LOW);
	digitalWrite(E_LED, LOW);
	digitalWrite(F_LED, LOW);
	digitalWrite(A_LED, LOW);
	digitalWrite(G_LED, LOW);
	digitalWrite(C_LED, LOW);
	digitalWrite(B_LED, LOW);
	delay(250);
}

void number9() {
	digitalWrite(D_LED, LOW);
	digitalWrite(E_LED, HIGH);
	digitalWrite(F_LED, LOW);
	digitalWrite(A_LED, LOW);
	digitalWrite(G_LED, LOW);
	digitalWrite(C_LED, LOW);
	digitalWrite(B_LED, LOW);
	delay(250);
}

void shutAllLeds() {
	digitalWrite(D_LED, HIGH);
	digitalWrite(E_LED, HIGH);
	digitalWrite(F_LED, HIGH);
	digitalWrite(A_LED, HIGH);
	digitalWrite(G_LED, HIGH);
	digitalWrite(C_LED, HIGH);
	digitalWrite(B_LED, HIGH);
	delay(250);
}

int getFirstChar(float celsValue) {
	int celsInt = celsValue;
	if (celsInt >= 10 && celsInt < 100) {
		return celsInt / 10;
	}
	else if (celsInt < 10) {
		return celsInt;
	}
}

int getSecondChar(float celsValue) {
	int celsInt = celsValue;
	if (celsInt > 10 && celsInt < 100) {
		return (celsInt - ((celsInt / 10) * 10));
	}
	else if (celsInt < 10) {
		return 10;
	}
}

// function to convert sensors value to Celsius
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

// function to display given number
void displayChar(int number){
	if (number == 1) {
		number1();
	}
	else if (number == 2) {
		number2();
	}
	else if (number == 3) {
		number3();
	}
	else if (number == 4) {
		number4();
	}
	else if (number == 5) {
		number5();
	}
	else if (number == 6) {
		number6();
	}
	else if (number == 7) {
		number7();
	}
	else if (number == 8) {
		number8();
	}
	else if (number == 9) {
		number9();
	}
	else if (number == 10) {
		shutAllLeds();
		digitalWrite(G_LED, LOW);
	}
}

// function to display number 3 and letter E in sequence 3 times
void blinkThreeAndE() {
	for (int i = 0; i < 3; i++) {
		// number 3
		digitalWrite(D_LED, LOW);
		digitalWrite(E_LED, LOW);
		digitalWrite(F_LED, LOW);
		digitalWrite(A_LED, LOW);
		digitalWrite(G_LED, LOW);
		digitalWrite(C_LED, HIGH);
		digitalWrite(B_LED, HIGH);
		delay(500);
	
		// letter E
		digitalWrite(C_LED, LOW);
		digitalWrite(B_LED, LOW);
		digitalWrite(E_LED, HIGH);
		digitalWrite(F_LED, HIGH);
		delay(500);
	}
}

void circleThreeTimes() {
	// makes a circle clockwise smoothly 3 times
	for (int i = 0; i < 3; i++) {
		shutAllLeds();
		delay(250);
		onlyDOn();
		delay(250);
		digitalWrite(E_LED, LOW);
		delay(250);
		digitalWrite(F_LED, LOW);
		delay(250);
		digitalWrite(A_LED, LOW);
		delay(250);
		digitalWrite(B_LED, LOW);
		delay(250);
		digitalWrite(C_LED, LOW);
		delay(250);
	}
}



void setup() {
	pinMode(THERM_PIN, INPUT);	
	pinMode(A_LED, OUTPUT);
	pinMode(B_LED, OUTPUT);
	pinMode(C_LED, OUTPUT);
	pinMode(D_LED, OUTPUT);
	pinMode(E_LED, OUTPUT);
	pinMode(F_LED, OUTPUT);
	pinMode(G_LED, OUTPUT);
}


void loop() {
	volatile int thermistorValue = 0;	// we initialize the variables as volatile in order to see the values change without serial monitor etc.
	volatile float celsiusValue = 0.0;
	int celsiusFirstChar = 0;
	int celsiusSecondChar = 0;
	thermistorValue = analogRead(THERM_PIN);	// read the thermal value from the sensor
	celsiusValue = thermToCelsius(thermistorValue);
	celsiusFirstChar = getFirstChar(celsiusValue);
	celsiusSecondChar = getSecondChar(celsiusValue);
	
	// following functions inside loop are shown on 7-segment display
	blinkThreeAndE();
	delay(1500);
	shutAllLeds();
	delay(250);
	displayChar(celsiusFirstChar);
	delay(2000);
	shutAllLeds();
	delay(250);
	displayChar(celsiusSecondChar);
	delay(2000);
	shutAllLeds();
	delay(250);
	circleThreeTimes();
	// shut all LEDs and start again
	delay(250);
	shutAllLeds();
	delay(2000);
}

