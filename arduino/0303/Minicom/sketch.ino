#include "MiniCom.h"
#include <Led.h>
Led led(8);
MiniCom com;
void setup()
{
  com.init();
  com.print(0, "[[MiniCom]]");
  com.setInterval(1000, check); // 1초 간격으로
}
void loop()
{
  com.run();
}
void check()
{
  int on = led.toggle();
  if (on)
  {
    com.print(1, "led on");
  }
  else
  {
    com.print(1, "led off");
  }
}