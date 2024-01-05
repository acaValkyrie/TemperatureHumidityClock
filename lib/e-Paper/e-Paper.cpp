#include "e-Paper.h"

Epd epd;
unsigned char image[1024];
Paint paint(image, 0, 0);

void setDataOnDisplay(String data_string)
{
  epd.LDirInit();
  epd.Clear();

  paint.SetWidth(200);
  paint.SetHeight(24);

  paint.Clear(UNCOLORED);
  char data_char_array[data_string.length() + 1];
  data_string.toCharArray(data_char_array, data_string.length() + 1);
  paint.DrawStringAt(10, 4, data_char_array, &Font24, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 10, paint.GetWidth(), paint.GetHeight());
  
  epd.DisplayFrame();

  epd.HDirInit();
  epd.Clear();
  epd.Sleep();
}