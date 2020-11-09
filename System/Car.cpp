#include "Car.h"

Car::Car()
{

}

Car::Car(string name)
{
    driverName = name;
    endPosition = -1;
    startPosition = -1;
    Score = -1;
    pitStopDisplayMod = false;

}

Car::~Car()
{

}

//void Car::drive();
//{
//
//}
//
//void Car::Stop()
//{
//
//}

int Car::getStartPosition()
{

    return startPosition;
}

void Car::setStartPosition(int pos)
{
    cout<<driverName<<"'s starting position is : "<<pos<<endl;
    startPosition = pos;
}

int Car::getEndPosition()
{
    return endPosition;
}

void Car::setEndPosition(int pos)
{
    cout<<driverName<<"'s finished in position : "<<pos<<endl;
    endPosition = pos;
}

int Car::getScore()
{
    return Score;
}

void Car::setScore(int score)
{
    Score = score;
}

void Car::changeTyres(string newtyre)
{
    cout<<endl;
    if(pitStopDisplayMod!=0)
    {
        cout << driverName<<"'s car: Replacing old " << tyre << " tyres with new set of tyres of type: " << newtyre << endl;
    }
    else
    {
        cout<<driverName<<"'s car: Starting off with tyres of type "<<newtyre<<endl;
    }
    cout<<endl;
    pitStopDisplayMod = 1;

    tyre = newtyre;
}
