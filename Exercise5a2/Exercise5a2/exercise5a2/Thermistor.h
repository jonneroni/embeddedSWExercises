/*
Thermistor.h
Anton Leinonen & Jonne Kaajalahti
Initializes Thermistor.cpp variables and functions and includes the look-up table
*/


#ifndef THERMISTOR_H
#define THERMISTOR_H

#define THERMISTOR_PIN 0

const int LUTThermistor[32] = { 250, 275, 300, 325, 350, 375, 400, 425, 450, 475, 500, 525, 550, 575, 600, 625, 650, 675, 700, 725, 750, 775, 784, 825, 850, 875, 900, 925, 937, 950, 975, 1000};
const float LUTCelsius[32] = { 1.4, 4, 6.4, 8.8, 11.1, 13.4, 15.6, 17.8, 20, 22.2, 24.4, 26.7, 29, 31.3, 33.7, 36.1, 38.7, 41.3, 44.1, 47.1, 50.2, 53.7, 55, 61.5, 66.2, 71.5, 77.9, 85.7, 90.3, 96, 111.2, 139.5};

float thermistorToCelsiusConverter(int thermValue);
float getTemperature();
int getVoltage();

#endif /* THERMISTOR_H */