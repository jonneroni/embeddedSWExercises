/*
Exercise1a3 - Traffic lights
Jonne Kaajalahti & Anton Leinonen
The program operates LEDs to work as traffic lights.
*/


#include <Arduino.h>
#define REDLED 9
#define YELLOWLED 8
#define GREENLED 7


void setup() {
	// initialize led pin_outputs
  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
}

void loop() {
	
  // only red light is on
  digitalWrite(REDLED, HIGH);
  delay(2000);
  
  // also yellow light turns on
  digitalWrite(YELLOWLED, HIGH);
  delay(2000);
  
  // red and yellow lights turns off and green turns on
  digitalWrite(REDLED, LOW);
  digitalWrite(YELLOWLED, LOW);
  digitalWrite(GREENLED, HIGH);
  delay(2000);
  
  // green turns off and only yellow is on
  digitalWrite(GREENLED, LOW);
  digitalWrite(YELLOWLED, HIGH);
  delay(2000);
  
  // yellow turns off and only red is on
  digitalWrite(YELLOWLED,LOW);
  digitalWrite(REDLED,HIGH);
}
