#include "e-Paper.h"
#include <SPI.h>
#include "epd1in54_V2.h"
#include "imagedata.h"
#include "epdpaint.h"

Epd epd;
unsigned char image[1024];
Paint paint(image, 0, 0);
byte HL = 0;

void setupDisplay(){
  epd.LDirInit();
  // epd.Clear();
}

void setDataOnDisplay(String data_string1, String data_string2)
{
  // Clearをしないと砂嵐みたいな画像が出力される。
  epd.Clear();

  paint.SetWidth(200);
  paint.SetHeight(50);

  paint.Clear(UNCOLORED);
  char data_char_array1[data_string1.length()+1];
  data_string1.toCharArray(data_char_array1, data_string1.length()+1);
  paint.DrawStringAt(15, 4, data_char_array1, &Font20, COLORED);
  
  char data_char_array2[data_string2.length()+1];
  data_string2.toCharArray(data_char_array2, data_string2.length()+1);
  paint.DrawStringAt(15, 25, data_char_array2, &Font20, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());

  epd.DisplayFrame();
}