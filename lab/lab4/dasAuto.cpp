#include <iostream>
#include "dasAuto.h"
using namespace std;
void dasAuto::getHorsepower()
{
    cout << "Power:" << horsepower << endl;
}

void dasAuto::getModel()
{
    cout << "Model:" << model << endl;
}

void dasAuto::getMaxVelocity()
{
    cout << "Max velocity:" << maxVelocity << endl;
}

void dasAuto::getColor()
{
    cout << "Color:" << color << endl ;
}

void dasAuto::getEngineLiters()
{
    cout << "Engine Liters:" << engineLiters << endl;
}

void dasAuto::giveHorsepower()
{
    cout << "Enter horsepower \n";
    cin >> horsepower;
}

void dasAuto::giveModel()
{
    cout << "Enter model" << endl;
    cin >> model;
}

void dasAuto::giveMaxVelocity()
{
    cout << "Enter Max velocity" << endl;
    cin >> maxVelocity;
}

void dasAuto::giveColor()
{
    cout << "Enter Color" << endl;
    cin >> color;
}

void dasAuto::giveEngineLiters()
{
    cout << "Enter Engine Liters" << endl;
    cin >> engineLiters;
}