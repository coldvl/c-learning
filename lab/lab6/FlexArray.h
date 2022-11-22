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

 
        // Виконуємо FlexArray + FlexArray через дружню функцію
        friend FlexArray operator+(const FlexArray &d1, const FlexArray &d2);
 
        int getLength() const { return m_length; }
};

FlexArray::FlexArray(int length)
{
    m_length = length; 
     int *array = new int[length]; // використовуємо оператор new[] для виділення масиву. Зверніть увагу, змінна length не обов'язково повинна бути константою!
 
    std::cout << "I just allocated an array of integers of length " << length << '\n';
 
    array[0] = 7; // присвоюємо елементу під індексом 0 значення 7
 
    delete[] array; // використовуємо оператор delete[] для звільнення виділеної масиву пам'яті
    array = 0; // використовуйте nullptr замість 0 в C++11
}

FlexArray::~FlexArray()
{
}


 
// Примітка: Ця функція не є методом класу!
FlexArray operator+(const FlexArray &d1, const FlexArray &d2)
{
 // Використовуємо конструктор FlexArray і operator+(int, int).
 // Ми маємо доступ до закритого члену m_dollars, оскільки ця функція є дружньою класу FlexArray
 return FlexArray(d1.m_length + d2.m_length);
}
 
#endif