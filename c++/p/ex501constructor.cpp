#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
  int hour;
  int minute;
  // 생성자
  Time(int h, int m)
  {
    hour = h;
    minute = m;
  }
  void print()
  {
    cout << hour << ":" << minute << endl;
  }
};

int main(int argc, char const *argv[])
{

  return 0;
}