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
    void giveHorsepower();
    void giveModel();
    void giveMaxVelocity();
    void giveColor();
    void giveEngineLiters();
protected:
    string color;
    int engineLiters;
};
void dasAuto::getHorsepower()
{
    cout << horsepower;
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

void dasAuto::giveHorsepower()
{
    cin >> horsepower;
}

void dasAuto::giveModel()
{
    cin >> model;
}

void dasAuto::giveMaxVelocity()
{
    cin >> maxVelocity;
}

void dasAuto::giveColor()
{
    cin >> color;
}

void dasAuto::giveEngineLiters()
{
    cin >> engineLiters;
}


int main() {
    dasAuto car;
    car.giveColor();
    car.getColor();
}