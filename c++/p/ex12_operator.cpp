#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]){
int x = 100;
int y = 200;
int result = x + y;
cout << "x + y : " << result << endl;
cout << "x - y : " << x - y << endl;
cout << "x / y : " << x /y << endl;
cout << "x % 3 : " << x % 3 << endl;

x = 100;
x++; // x 는 101
cout << x << endl;
x--;
cout << x << endl;
cout << ++x << endl;
cout << x++ << endl;
cout << x << endl;
cout << --x << endl;
cout << x-- << endl;
cout << x << endl;

return 0;
}