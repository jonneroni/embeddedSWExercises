/*
Exercise2a3 - 7-segment display
Jonne Kaajalahti & Anton Leinonen
Make 7-segment display display different characters
*/
#include <Arduino.h>

#define A_LED 2
#define B_LED 8
#define C_LED 6
#define D_LED 5
#define E_LED 4
#define F_LED 3
#define G_LED 7


void setup() {
  // setup pin outputs for arduino's digital pins
  pinMode(A_LED,OUTPUT);
  pinMode(B_LED,OUTPUT);
  pinMode(C_LED,OUTPUT);
  pinMode(D_LED,OUTPUT);
  pinMode(E_LED,OUTPUT);
  pinMode(F_LED,OUTPUT);
  pinMode(G_LED,OUTPUT);
}

void OnlyAOn()
	{
		digitalWrite(A_LED, LOW);
		digitalWrite(B_LED, HIGH);
		digitalWrite(C_LED, HIGH);
		digitalWrite(D_LED, HIGH);
		digitalWrite(E_LED, HIGH);
		digitalWrite(F_LED, HIGH);
		digitalWrite(G_LED, HIGH);
	}
void OnlyBOn()
	{
		digitalWrite(A_LED, HIGH);
		digitalWrite(B_LED, LOW);
		digitalWrite(C_LED, HIGH);
		digitalWrite(D_LED, HIGH);
		digitalWrite(E_LED, HIGH);
		digitalWrite(F_LED, HIGH);
		digitalWrite(G_LED, HIGH);
	}
void OnlyCOn()
	{
		digitalWrite(A_LED, HIGH);
		digitalWrite(B_LED, HIGH);
		digitalWrite(C_LED, LOW);
		digitalWrite(D_LED, HIGH);
		digitalWrite(E_LED, HIGH);
		digitalWrite(F_LED, HIGH);
		digitalWrite(G_LED, HIGH);
	}
void OnlyDOn()
	{
		digitalWrite(A_LED, HIGH);
		digitalWrite(B_LED, HIGH);
		digitalWrite(C_LED, HIGH);
		digitalWrite(D_LED, LOW);
		digitalWrite(E_LED, HIGH);
		digitalWrite(F_LED, HIGH);
		digitalWrite(G_LED, HIGH);
	}
void OnlyEOn()
	{
		digitalWrite(A_LED, HIGH);
		digitalWrite(B_LED, HIGH);
		digitalWrite(C_LED, HIGH);
		digitalWrite(D_LED, HIGH);
		digitalWrite(E_LED, LOW);
		digitalWrite(F_LED, HIGH);
		digitalWrite(G_LED, HIGH);
	}
void OnlyFOn()
	{
		digitalWrite(A_LED, HIGH);
		digitalWrite(B_LED, HIGH);
		digitalWrite(C_LED, HIGH);
		digitalWrite(D_LED, HIGH);
		digitalWrite(E_LED, HIGH);
		digitalWrite(F_LED, LOW);
		digitalWrite(G_LED, HIGH);
	}
void OnlyGOn()
	{
		digitalWrite(A_LED, HIGH);
		digitalWrite(B_LED, HIGH);
		digitalWrite(C_LED, HIGH);
		digitalWrite(D_LED, HIGH);
		digitalWrite(E_LED, HIGH);
		digitalWrite(F_LED, HIGH);
		digitalWrite(G_LED, LOW);
	}
void ShutAllLeds()
	{
			digitalWrite(D_LED, HIGH);
			digitalWrite(E_LED, HIGH);
			digitalWrite(F_LED, HIGH);
			digitalWrite(A_LED, HIGH);
			digitalWrite(G_LED, HIGH);
			digitalWrite(C_LED, HIGH);
			digitalWrite(B_LED, HIGH);
	}

void loop() {

	ShutAllLeds();  //sets all leds off
	
	
	// display number 3 and letter E in a sequence 3 times
	for (int i = 0; i < 3; i++)
	{
		// number 3 
		digitalWrite(D_LED, LOW);
		digitalWrite(E_LED, LOW);
		digitalWrite(F_LED, LOW);
		digitalWrite(A_LED, LOW);
		digitalWrite(G_LED, LOW);
		digitalWrite(C_LED, HIGH);
		digitalWrite(B_LED, HIGH);
		
		delay(1000);
		
		// letter E
		digitalWrite(C_LED, LOW);
		digitalWrite(B_LED, LOW);
		digitalWrite(E_LED, HIGH);
		digitalWrite(F_LED, HIGH);
		
		delay(1000);
	}
	
	
	// makes a circle counter clockwise 3 times
	for (int i = 0; i < 3; i++)
	{
		ShutAllLeds();
		delay(250);
		OnlyAOn();
		delay(250);
		digitalWrite(F_LED, LOW);
		delay(250);
		digitalWrite(E_LED, LOW);
		delay(250);
		digitalWrite(D_LED, LOW);
		delay(250);
		digitalWrite(C_LED, LOW);
		delay(250);
		digitalWrite(B_LED, LOW);
		delay(250);
	}


	ShutAllLeds();
	delay(1000);
	
	
	// turn every segment on and then off one-by-one
	for (int i = 0; i < 3; i++)
	{
		for (int i = 2; i < 9; i++ )
		{
			digitalWrite(i, LOW);
			delay(250);
		}
		for (int i = 2; i < 9; i++)
		{
			digitalWrite(i, HIGH);
			delay(250);	
		}
	}
	
	
	 // makes a circle clockwise smoothly 3 times
	 for (int i = 0; i < 3; i++)
	 {
		 ShutAllLeds();
		 delay(250);
		 OnlyDOn();
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
	
	
	// shut all leds and after 2s start again 
	ShutAllLeds();
	delay(2000);
	
	
}
