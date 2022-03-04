#include "PWMLed.h"
PWMLed led(9);
void setup() {
}
void loop()
{
int pwm_val;
for (pwm_val = 0; pwm_val < 256; pwm_val += 5)
{
led.setValue(pwm_val); // PWM 신호 출력
delay(100);
}
led.off();
delay(2000); // 2초 대기
}
