/*
Math.cpp
Anton Leinonen & Jonne Kaajalahti
Checks LSB of two's complement of voltage and returns 1 or 0 as "bit"
*/
#include <Arduino.h>
#include "Math.h"


// the function below gets a voltage reading from the thermistor and
// checks the least significant bit of two's complement of voltage
// it returns 1 if LSB is 1; otherwise it returns 0
int checkBit(int voltage){
	int bit = 0;
	
	if (voltage % 2 == 1){
		bit = 1;
	}
	else if (voltage % 2 == 0){
		bit = 0;
	}
	
	return (bit);
}