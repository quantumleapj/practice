#include <Led.h>
#include <Button.h>
Led led(8);
Button btn(2);
boolean led_st = LOW;
void flash(void)
{
  if (!btn.debounce())
    return;
  led_st = !led_st; // LED 상태 반전
  led.setValue(led_st);
}
void setup()
{
  btn.attachInterrupt(flash, FALLING);
}
void loop() {}
