#include <Arduino.h>
#include <Wire.h>
#include "Clock.h"
#include "TempHumid.h"
#include "e-Paper.h"

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}