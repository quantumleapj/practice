#include <SimpleTimer.h>
#include "ColorLed.h"

SimpleTimer timer;
ColorLed leds(9,10,11);

void check(){

leds.random();

}
void setup()
{
  Serial.begin(115200);
  timer.setInterval(1000,check);
}

void loop()
{
  timer.run();
}