#include "FlexArray.cpp"
// #include "FlexArray.h"
#include <iostream>

using namespace std;

int main()
{
 FlexArray dollars1(7);
 FlexArray dollars2(9);
 FlexArray dollarsSum = dollars1 + dollars2;
 std::cout << "I have " << dollarsSum.getLength() << " dollars." << std::endl;
    
    
 return 0;
}