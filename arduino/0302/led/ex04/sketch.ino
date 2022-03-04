const int led1_pin = 3;
const int led2_pin = 4;
const int led3_pin = 5;
const int led4_pin = 6;
void setup()
{
pinMode(led1_pin, OUTPUT); // 3번 핀 출력 설정
pinMode(led2_pin, OUTPUT); // 4번 핀 출력 설정
pinMode(led3_pin, OUTPUT); // 5번 핀 출력 설정
pinMode(led4_pin, OUTPUT); // 6번 핀 출력 설정
// LED 모두 off
digitalWrite(led1_pin, LOW); // 3번 핀 LOW 출력(off) 
digitalWrite(led2_pin, LOW); // 4번 핀 LOW 출력(off) 
digitalWrite(led3_pin, LOW); // 5번 핀 LOW 출력(off)
digitalWrite(led4_pin, LOW); // 6번 핀 LOW 출력(off) 
}

void loop() {
// LED1만 ON
digitalWrite(led4_pin, LOW); // LED4 off 
digitalWrite(led1_pin, HIGH); // LED1 on 
delay(1000);
// LED2만 ON
digitalWrite(led1_pin, LOW); // LED1 off
digitalWrite(led2_pin, HIGH); // LED2 on 
delay(1000);
// LED3만 ON
digitalWrite(led2_pin, LOW); // LED2 off 
digitalWrite(led3_pin, HIGH); // LED3 on
delay(1000);
// LED4만 ON
digitalWrite(led3_pin, LOW); // LED3 off
digitalWrite(led4_pin, HIGH); // LED4 on
delay(1000);
}
