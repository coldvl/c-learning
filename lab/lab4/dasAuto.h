#ifndef DASAUTO_H
#define DASAUTO_H
#include <iostream>
using namespace std;

class dasAuto
{
private:
    int horsepower;
    string model;
    int maxVelocity;
public:
    void getHorsepower();
    void getModel();
    void getMaxVelocity();
    void getColor();
    void getEngineLiters();
    string engine;
    int litersPerKilometer;
    dasAuto(/* args */);
    ~dasAuto();
protected:
    string color;
    int engineLiters;
};

void dasAuto::getHorsepower()
{
    std::cout << horsepower;
}

void dasAuto::getModel()
{
    cout << model;
}

void dasAuto::getMaxVelocity()
{
    cout << maxVelocity;
}

void dasAuto::getColor()
{
    cout << color;
}

void dasAuto::getEngineLiters()
{
    cout << engineLiters;
}

dasAuto::~dasAuto()
{
}

#endif