#include "e-Paper.h"
#include <SPI.h>
#include "epd1in54_V2.h"
#include "imagedata.h"
#include "epdpaint.h"

Epd epd;
unsigned char image[1024];
Paint paint(image, 0, 0);

void setupDisplay(){
  epd.LDirInit();
}

void sleepDisplay(){
  epd.Sleep();
}

void resetDisplay(){
  epd.Reset();
}

void setDataOnDisplay(String temperature, String humidity, String time)
{
  // Clearをしないと砂嵐みたいな画像が出力される。
  epd.Clear();

  paint.SetWidth(200);
  paint.SetHeight(60);

  paint.Clear(UNCOLORED);
  String temperature_string = temperature + "'C";
  char temperature_char_array[temperature_string.length()+1];
  temperature_string.toCharArray(temperature_char_array, temperature_string.length()+1);
  paint.DrawStringAt(15, 5, temperature_char_array, &Font20, COLORED);
  
  String humidity_string = humidity + "%";
  char humidity_char_array[humidity_string.length()+1];
  humidity_string.toCharArray(humidity_char_array, humidity_string.length()+1);
  paint.DrawStringAt(15, 25, humidity_char_array, &Font20, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
  // epd.DisplayFrame();

  paint.SetWidth(200);
  paint.SetHeight(30);
  paint.Clear(UNCOLORED);
  time = time;
  char time_char_array[time.length()+1];
  time.toCharArray(time_char_array, time.length()+1);
  paint.DrawStringAt(15, 0, time_char_array, &Font20, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 170, paint.GetWidth(), paint.GetHeight());

  epd.DisplayFrame();
}