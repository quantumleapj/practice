#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;


int main(int argc, char const *argv[])
{

  Circle obj; // 객체 생성
  obj.radius = 100;
  obj.color = "blue";
  cout << "area of circle " << obj.calcArea() << endl;

  return 0;
}