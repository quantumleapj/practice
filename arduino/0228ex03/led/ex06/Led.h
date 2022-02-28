#ifndef LED_H
#define LED_H

#pragma once

class Led{
  protected:
  int pin;

  public:
  Led(int pin);//생성자
  ~Led();//소멸자, 파괴자

  void on();//켜기
  void off();//끄기
  void toggle();//토글
  void blink(int delay_time=0);

  private:
};
#endif