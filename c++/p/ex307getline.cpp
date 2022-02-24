#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]){

string s1, addr;
cout << "name: " ;
cin >> s1;
cin.ignore(); // 엔터키 제거
cout << "address: ";
getline(cin, addr);
cout << s1 << " from " << addr << ", how do you do?" << endl;

return 0;
}