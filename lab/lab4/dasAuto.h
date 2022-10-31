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
    dasAuto();
    ~dasAuto();
    void getHorsepower();
    void getModel();
    void getMaxVelocity();
    void getColor();
    void getEngineLiters();
    string engine;
    int litersPerKilometer;
    void giveHorsepower();
    void giveModel();
    void giveMaxVelocity();
    void giveColor();
    void giveEngineLiters();
protected:
    string color;
    int engineLiters;
};

dasAuto::dasAuto(/* args */)
{
}

dasAuto::~dasAuto()
{
}

#endif