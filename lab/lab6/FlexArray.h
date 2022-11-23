#ifndef FLEXARRAY_H
#define FLEXARRAY_H
#include <iostream>
#include "string.h"
using namespace std;

class FlexArray
{
    private:
        int m_length;
 
    public:
        FlexArray(int length);
        ~FlexArray();

        friend FlexArray operator+(const FlexArray &d1, const FlexArray &d2);
        FlexArray operator*=(int a);
        void operator=(const FlexArray &d1);
        friend std::ostream& operator<<(std::ostream& out, const FlexArray &d1);
 
        int getLength() const { return m_length; }
};

FlexArray::FlexArray(int length)
{
    m_length = length; 
     int *array = new int[length]; 
 
    std::cout << "I just allocated an array of integers of length " << length << '\n';
 
    array[0] = 7; 
    delete[] array;
    array = 0; // використовуйте nullptr замість 0 в C++11
}

FlexArray::~FlexArray()
{
}


 

FlexArray operator+(const FlexArray &d1, const FlexArray &d2)
{
 // Використовуємо конструктор FlexArray і operator+(int, int).
 return FlexArray(d1.m_length + d2.m_length);
}

FlexArray FlexArray::operator*=(int a) //тут неявний параметр, на який вказує вказівник *this
{
    m_length=m_length*a;
    return FlexArray(m_length);
}

void FlexArray::operator=(const FlexArray &d1)
{
    m_length = d1.m_length + 1;
}

std::ostream& operator<<(std::ostream& out, const FlexArray &d1)
{
	out << d1.m_length << " - довжина масиву";
	return out;
}
#endif