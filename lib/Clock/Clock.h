#ifndef CLOCK_H
#define CLOCK_H

#include <Arduino.h>
#include <esp_sntp.h>
#include <TimeLib.h>
#include <WiFi.h>
#include "wifi_info.h"

#define SERIAL_ENABLE false

class Clock
{
    public:
        bool wifiSyncJST();
        String getDateTimeString();
};

#endif