#ifndef E_PAPER_H
#define E_PAPER_H

#include <SPI.h>
#include "epd1in54_V2.h"
#include "imagedata.h"
#include "epdpaint.h"
#include <stdio.h>



// unsigned long time_start_ms;
// unsigned long time_now_s;
#define COLORED     0
#define UNCOLORED   1

void setDataOnDisplay(String data_string);

#endif