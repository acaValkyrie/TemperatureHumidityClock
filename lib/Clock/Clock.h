#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>
#include <esp_sntp.h>
#include <TimeLib.h>
#include <WiFi.h>
#include "wifi_info.h"

const char* ssid      = WIFI_SSID;
const char* password  = WIFI_PASS;
const char* ntpServer = "ntp.nict.jp";
const long  gmtOffset_sec = 32400;
const int   daylightOffset_sec = 0;

#define SERIAL_ENABLE false

class Clock
{
    public:
        Clock();
        void wifiSyncJST();
        String getDateTimeString();
};

struct tm *tm;

#endif