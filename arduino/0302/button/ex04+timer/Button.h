#pragma once

#include <Arduino.h>

typedef void(*button_callback_t)();

class Button{
  protected:
  int pin;
  button_callback_t callback;

  public:
  Button(int pin);
  void setCallback(button_callback_t callback);
  int read();
  void check();
};