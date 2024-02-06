#include "e-Paper.h"

EPD1in54 epd;
unsigned char image[1024];
EPDPaint paint(image, 0, 0);
void setupDisplay()
{
  if (epd.init(lutFullUpdate) != 0) {
    return;
  }
  // ここまでは実行される
  epd.clearFrameMemory(0xFF);
  digitalWrite(20, HIGH);
  epd.displayFrame();
  epd.clearFrameMemory(0xFF);
  epd.displayFrame();
  // ここで実行が途切れる
  if (epd.init(lutFullUpdate) != 0) {
    digitalWrite(20, HIGH);
    return;
  }
  epd.setFrameMemory(image);
  epd.displayFrame();
  epd.setFrameMemory(image);
  epd.displayFrame();
}

void setDataOnDisplay(String data_string)
{
  paint.setWidth(32);
  paint.setHeight(96);
  paint.setRotate(ROTATE_270);

  paint.clear(UNCOLORED);
  char data_char_array[data_string.length() + 1];
  data_string.toCharArray(data_char_array, data_string.length() + 1);
  paint.drawStringAt(0, 4, data_char_array, &Font24, COLORED);
  epd.setFrameMemory(paint.getImage(), 80, 72, paint.getWidth(), paint.getHeight());
  epd.displayFrame();
}