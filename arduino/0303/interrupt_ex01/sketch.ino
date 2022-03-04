const int sw_pin = 2;
int count = 0;
// 외부 인터럽트1 처리 함수
void flash(void)
{
  count++;
  Serial.println(count);
}
void setup()
{
  Serial.begin(115200);
  pinMode(sw_pin, INPUT_PULLUP);
  // 외부 인터럽트 설정
  attachInterrupt(digitalPinToInterrupt(sw_pin), flash, FALLING);
}
void loop() {}