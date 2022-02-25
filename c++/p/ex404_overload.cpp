#include <iostream>
#include <string>

#include "PrintData.h"
#include "Car.h"
#include "Circle.h"

using namespace std;
int main(int argc, char const *argv[]){

PrintData prn;
prn.print(1);
prn.print(3.3);
prn.print("C++ is cool.");
prn.print();

return 0;
}