#include "FlexArray.h"
#include <iostream>

using namespace std;

int main()
{
    FlexArray flex1(7);
    FlexArray flex2(9);
    FlexArray flexSum = flex1 + flex2;
    flexSum *= 2;
    std::cout << flexSum << std::endl;
    flex1 = flex2;
    std::cout << flex1 << std::endl;

    
    
 return 0;
}