#pragma once
#include <iostream>
#include <string>
using namespace std;

class PrintData
{
public:
  void print(int i) { cout << i << endl; }
  void print(double f) { cout << f << endl; }
  void print(string s = "No Data!") { cout << s << endl; }
};