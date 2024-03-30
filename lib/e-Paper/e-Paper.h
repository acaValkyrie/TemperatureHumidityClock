#ifndef E_PAPER_H
#define E_PAPER_H

#include <stdio.h>
#include <Arduino.h>

#define COLORED     0
#define UNCOLORED   1

void setupDisplay();
void setDataOnDisplay(String data_string1, String data_string2);

#endif