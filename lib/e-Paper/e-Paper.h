#ifndef E_PAPER_H
#define E_PAPER_H

#include <SPI.h>
#include "EPD1in54.h"
#include "EPDPaint.h"
#include <stdio.h>

// unsigned long time_start_ms;
// unsigned long time_now_s;
#define COLORED     0
#define UNCOLORED   1

void setupDisplay();
void setDataOnDisplay(String data_string);

#endif