#if !defined(Car_H)
#define Car_H

//#include "Strategy.h"
#include <string>
#include <iostream>
using namespace std;

class Car
{
private:
    string tyre;
    string driverName;
    int startPosition;
    int endPosition;
    int Score;
    int tyreIndex;
    bool pitStopDisplayMod;
public:
    Car();
    Car(string name);
    ~Car();
    /*void drive();
    void Stop();*/
    string getDriverName(){return driverName;};
    void setDriverName(string name){driverName =name; };
    int getStartPosition();
    void setStartPosition(int pos);
    int getEndPosition();
    void setEndPosition(int pos);
    int getScore();
    void setScore(int score);
    void changeTyres(string newtyre); //returns old tyre?
};

#endif
