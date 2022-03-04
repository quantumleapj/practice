#include "ColorLed.h"

ColorLed::ColorLed(int red, int green, int blue) : red(red), green(green), blue(blue)
{
}
void ColorLed::rgb(int r, int g, int b)
{
  red.setValue(r);
  green.setValue(g);
  blue.setValue(b);
}
void ColorLed::off(int delay_time)
{
  rgb(0, 0, 0);
  if (delay_time > 0)
  {
    delay(delay_time);
  }
}
void ColorLed::random()
{
  int r = ::random(256); // 0 ~ 255 사이의 정수값
  int g = ::random(256);
  int b = ::random(256);
  rgb(r, g, b);
}