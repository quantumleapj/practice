#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
  int x, y;

public:
  void draw() {}
  void move() {}
};
class Reactangle : public Shape
{
protected:
  int width;
  int height;

public:
  int calcArea()
  {
    return width * height;
  }
};

int main(int argc, char const *argv[])
{

  return 0;
}