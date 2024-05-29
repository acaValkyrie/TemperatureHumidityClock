#include <Arduino.h>
#include <Wire.h>
// #include "Clock.h"
#include "TempHumid.h"
#include "e-Paper.h"

TempHumid tempHumid;
// Clock rtc_wifi;
// bool wifi_status = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  // wifi_status = rtc_wifi.wifiSyncJST();
  setupDisplay();
}

void loop() {
  // Serial.println("wakeuped");

  tempHumid.retrieveData();
  float temperature = tempHumid.getTemperature();
  float humidity = tempHumid.getHumidity();
  // Serial.println("  temperature: " + String(temperature) + " humidity: " + String(humidity));
  // /* String time;
  // if (!wifi_status) {
  //   time = "-1";
  // }else{
  //   time = rtc_wifi.getDateTimeString();
  // }
  // Serial.println("  time: " + time); */
  String time = String("--:--");
  setDataOnDisplay(String(temperature), String(humidity), time);
  delay(1000 * 10);

  // // sleep 3hours
  // Serial.println("sleep 30sec");
  sleepDisplay();
  // Serial.println("sleeping...");
  int interval = 60 * 10; // unit:sec
  ::esp_deep_sleep(interval*1000*1000/*us*/);
}
