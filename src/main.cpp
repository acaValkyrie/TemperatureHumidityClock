#include <Arduino.h>
#include <Wire.h>
#include "Clock.h"
#include "TempHumid.h"
#include "e-Paper.h"

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // measure temp and humid
  // get_time
  // update display

  // sleep 3hours
  unsigned long interval = 3*60*60; // unit:sec
  esp_sleep_enable_timer_wakeup(interval*1000*1000/*us*/);
  esp_deep_sleep_start();
}