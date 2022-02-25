#pragma once
#include <iostream>
#include <string>

using namespace std;
class Circle
{
public:
  int radius;   // 반지름
  string color; // 색상
  double calcArea()
  {
    return 3.14 * radius * radius;
  }
};
