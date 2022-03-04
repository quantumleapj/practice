#include "Led.h"

Led::Led(int pin) : pin(pin) //멤버변수(지역변수)
{
  pinMode(pin, OUTPUT); //이 핀은 지역변수이다 //this->pin 이건 멤버변수
}

Led::~Led()
{
}

void Led::on()
{
  digitalWrite(pin, HIGH);
}

void Led::off()
{
  digitalWrite(pin, LOW);
}

void Led::toggle()
{
  int v = !digitalRead(pin); //현재 나가고 있는 값이 뭔지 읽어온다.
  //내가 원하는 값은 현재값의 반대값이니까 느낌표붙인다.
  digitalWrite(pin, v); //현재상태의 반대상태로 내보내는 것.
}

void Led::blink(int delay_time)
{
  toggle();
  if (delay_time > 0)
  {
    delay(delay_time);
  }
}