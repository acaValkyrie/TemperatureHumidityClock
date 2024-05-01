#ifndef E_PAPER_H
#define E_PAPER_H

#include <stdio.h>
#include <Arduino.h>

#define COLORED     0
#define UNCOLORED   1

void setupDisplay();
void sleepDisplay();
void resetDisplay();
void setDataOnDisplay(String temperature, String humidity, String time);

#endif