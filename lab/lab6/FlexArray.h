#ifndef FLEXARRAY_H
#define FLEXARRAY_H
#include <iostream>
#include <cstdlib>
#include "string.h"
using namespace std;

class FlexArray
{
    private:
        int m_length;
        int *arr = new int[1];
 
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
    delete[] arr;
    arr = nullptr;
    m_length = length; 
    arr = new int[length]; 
 
    std::cout << "I just allocated an array of integers of length " << length << '\n';
 
    for (int i = 0; i < m_length; ++i)
    {
        arr[i]=rand() % 20;
        cout << arr[i] << "\t";
        if ((i+1) % 5 == 0)
            std::cout << "\n";
        
    }
    cout << "\n";
    cout << "\n";
}
FlexArray::~FlexArray()
{
    delete[] arr;
    arr = nullptr;
}


 

FlexArray operator+(const FlexArray &d1, const FlexArray &d2)
{
 // Використовуємо конструктор FlexArray і operator+(int, int).
 return FlexArray(d1.m_length + d2.m_length);
}

FlexArray FlexArray::operator*=(int a) //тут неявний параметр, на який вказує вказівник *this
{
    m_length=m_length*a;
    int *p = new int[m_length];  // створюємо тимчасовий масив p в а разів більший
    for (int i = 0; i < m_length/a; i++)
    {
        p[i]=arr[i];   // переносимо данні
        if (m_length-i != i)
        p[m_length-i-1]=arr[i];
        
    }

    
    delete [] arr;
    arr = nullptr;
    arr = new int[m_length]; // переініціалізовуємо масив arr на масив в а разів більший

    for (int i = 0; i < m_length; i++)
    {
         arr[i]=p[i];
        
    } 
    delete[] p;
    p = nullptr;
}

void FlexArray::operator=(const FlexArray &d1)
{
    m_length = d1.m_length + 1;
}

std::ostream& operator<<(std::ostream& out, const FlexArray &d1)
{
	for (int i = 0; i < d1.m_length; i++)
    {
        cout << d1.arr[i] << "\t";
        if ((i+1) % 5 == 0)
            std::cout << "\n";
    }
    cout << "\n";
    cout << "I just printed an array of integers of length " << d1.m_length;
	return out;
}

#endif