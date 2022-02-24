#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

  cout <<10;
  cout<< " apples"<<endl;
  cout<<endl;

  cout<<10<<" apples."<<endl;

  // cout<<10<<"개의사과가있습니다"<<endl;//이거있으면 이밑으로 출력안됨?!

  int i;
  i=100;
  cout<<i<<endl;


  int y = 100;
  int a{100};
  cout<<y<<a<<endl;

  string s{"hello"};
  cout<<s<<endl;
  
  return 0;
}