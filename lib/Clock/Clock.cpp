#include "Clock.h"

void Clock::wifiSyncJST()
{
    //---------内蔵時計のJST同期--------
    // WiFi接続
    WiFi.begin(ssid, password);
    #if SERIAL_ENABLE
        Serial.println("Connecting to WiFi");
    #endif
    while (WiFi.status() != WL_CONNECTED){
        #if SERIAL_ENABLE
            Serial.print(".");
        #endif
    }
    #if SERIAL_ENABLE
        Serial.println("Connected");
    #endif
    // NTPサーバからJST取得
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    delay(1000);
    // 内蔵時計の時刻がNTP時刻に合うまで待機
    #if SERIAL_ENABLE
        Serial.println("Waiting for NTP time sync");
    #endif
    while (sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET)
    {
        delay(1000);
    }
    #if SERIAL_ENABLE
        Serial.println("NTP time synced");
    #endif
    // WiFi切断
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
}

String Clock::getDateTimeString()
{
    time_t now = time(NULL);
    tm = localtime(&now);
    int month, day, hour, minute, second;
    month = tm->tm_mon + 1;
    day = tm->tm_mday;
    hour = tm->tm_hour;
    minute = tm->tm_min;
    second = tm->tm_sec;
    return String(month) + "/" + String(day) + " " + String(hour) + ":" + String(minute) + ":" + String(second);
}