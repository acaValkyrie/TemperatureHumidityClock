#include <Arduino.h>
#include <Wire.h>
#include "Clock.h"
#include "TempHumid.h"
#include "e-Paper.h"

TempHumid tempHumid;

const int ledPin = 20;

void setup() {
  pinMode(ledPin, OUTPUT);
  Wire.begin();
  setupDisplay();
}
// 24.97 59.2

void loop() {
  // measure temp and humid
  // get_time
  // update display
  
  tempHumid.retrieveData();
  float temperature = tempHumid.getTemperature();
  float humidity = tempHumid.getHumidity();
  // setDataOnDisplay(String(temperature));
  // digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}