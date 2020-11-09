
#if !defined(Track_H)
#define Track_H

#include <string>
using namespace std;

#include "Car.h"
//#include "FlagObserver.h"
class Track
{
protected:
    Car** Cars ;
public:
    virtual void setCarList(Car** list) = 0;
    virtual void completeNumLaps(int numlaps)= 0;
   // virtual int PositionToScore(int pos)=0;

};

#endif