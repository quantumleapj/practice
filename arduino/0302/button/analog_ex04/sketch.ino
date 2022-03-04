#include <PWMLed.h>
const int var_pin = A0; // 가변저항 연결핀
PWMLed led(9);
void setup()
{
}
void loop()
{
  int analog_val, pwm_val;
  analog_val = analogRead(var_pin);           // 가변저항 전압값 읽기
  pwm_val = map(analog_val, 0, 1023, 255, 0); // 0~1023 -> 255~0으로 변환
  led.setValue(pwm_val);
}