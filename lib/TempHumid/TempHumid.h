#ifndef TEMP_HUMID_H
#define TEMP_HUMID_H

#include <Arduino.h>
#include <Wire.h>
#include <TimeLib.h>
#define ADR 0x38

class TempHumid{
    private:
        float temperature;
        float humidity;
    public:
        void retrieveData();
        float getTemperature();
        float getHumidity();
};

#endif