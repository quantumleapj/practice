#include <Led.h>
Led led(8);
boolean led_val = LOW;
void setup()
{
}
void loop()
{
  delay(500);         // 500ms 지연
  led_val = !led_val; // LED 출력 변수 반전
  led.setValue(led_val);
}
