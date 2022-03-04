#include <Led.h>

const int pu_sw_pin=2;
Led led1(4);

const int pd_sw_pin=3;
Led led2(5);

void setup()
{
  pinMode(pd_sw_pin,INPUT);
  pinMode(pu_sw_pin,INPUT);
}

void loop()
{
  boolean pd_sw, pu_sw;

  pu_sw = digitalRead(pu_sw_pin);
  led1.setValue(pu_sw);

  pd_sw = digitalRead(pd_sw_pin);
  led2.setValue(pd_sw);

}