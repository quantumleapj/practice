const int pu_led_pin = 3; // 풀업 연결핀
const int pd_led_pin = 4; // 풀다운 연결핀
void setup()
{
  pinMode(pu_led_pin, OUTPUT); // 풀업 LED 연결핀 출력 설정
  pinMode(pd_led_pin, OUTPUT); // 풀다운 LED 연결핀 출력 설정
}
void loop()
{
  digitalWrite(pd_led_pin, HIGH); // 풀다운 LED 연결핀 HIGH 출력
  digitalWrite(pu_led_pin, HIGH); // 풀업 LED 연결핀 HIGH 출력
  // digitalWrite(pd_led_pin, LOW); // 풀다운 LED 연결핀 LOW 출력
  // digitalWrite(pu_led_pin, LOW); // 풀업 LED 연결핀 LOW 출력
}