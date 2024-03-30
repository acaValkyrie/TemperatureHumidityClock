#include <Arduino.h>
#include <Wire.h>
#include "Clock.h"
#include "TempHumid.h"
#include "e-Paper.h"

TempHumid tempHumid;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  tempHumid.retrieveData();
  float temperature = tempHumid.getTemperature();
  float humidity = tempHumid.getHumidity();
  setDataOnDisplay(String(temperature) + "C" + String(humidity) + "%");
}

void loop() {
  // measure temp and humid
  // get_time
  // update display
  tempHumid.retrieveData();
  float temperature = tempHumid.getTemperature();
  float humidity = tempHumid.getHumidity();
  setDataOnDisplay("temp:" + String(temperature) + "C", "humid:" + String(humidity) + "%");

  // sleep 3hours
  int interval = 30; // unit:sec
  // esp_deep_sleep(interval*1000*1000/*us*/);
  delay(interval*1000);
}