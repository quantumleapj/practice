#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  // int number = 0;
  // int *p = &number;
  // cout << p << endl;
  // cout << *p << endl;

  // const char *pstr = "hello world";
  // cout << pstr<<endl;

  // //포인터는 산술연산가능
  // pstr++;
  // cout << pstr<<endl; //ello world가 나온다. 주소값 하나 증가된것.  

  cout<<"argc:"<< argc <<endl;

  for (int i=0;i<argc;i++){
    cout<<"arg:" <<argv[i]<<endl;
  }

  // for (int i=0;i<argv;i++){ //이건 오류남
  //   cout<<"arg:" <<argv[i]<<endl;
  // }




  return 0;
}
