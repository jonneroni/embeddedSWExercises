/*
Led.h
Anton Leinonen & Jonne Kaajalahti
Initializes Led.cpp functions
*/


#ifndef LED_H
#define LED_H

#define RED_LED 5
#define YELLOW_LED 6
#define GREEN_LED 7

void redLedOn();
void greenLedOn();
void ledOff();
void yellowLedBlink(int blinkDelay);

#endif /* LED_H */