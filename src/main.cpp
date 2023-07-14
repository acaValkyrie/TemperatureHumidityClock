#include <Arduino.h>
#include <Wire.h>
#include "Clock.h"
#include "TempHumid.h"
#include "e-Paper.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:


  unsigned long interval = 10800; // unit:sec
  esp_sleep_enable_timer_wakeup(interval*1000000);
  esp_deep_sleep_start();
}