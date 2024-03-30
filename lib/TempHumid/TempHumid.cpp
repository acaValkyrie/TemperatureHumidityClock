#include "TempHumid.h"

TempHumid::TempHumid(){
    temperature = 0.0f;
    humidity = 0.0f;
}

void TempHumid::retrieveData(){
    uint8_t buf[8];
    long a;
    int flg;

    flg = 1;
    while (flg)
    {
        Wire.beginTransmission(ADR);
        Wire.write(0xac);
        Wire.write(0x33);
        Wire.write(0x00);
        Wire.endTransmission();
        delay(100);

        Wire.requestFrom(ADR, 6);
        for (uint8_t i = 0; i < 6; i++)  buf[i] = Wire.read();

        if (buf[0] & 0x80) {

        }
        else{ flg = 0;}
    }
    a = buf[1];
    a <<= 8;
    a |= buf[2];
    a <<= 4;
    a |= ((buf[3] >> 4) & 0x0f);
    humidity = a / 10485.76;

    a = (buf[3] & 0xf);
    a <<= 8;
    a |= buf[4];
    a <<= 8;
    a |= buf[5];
    temperature = a / 5242.88 - 50;
}

float TempHumid::getTemperature(){
    return temperature;
}

float TempHumid::getHumidity(){
    return humidity;
}