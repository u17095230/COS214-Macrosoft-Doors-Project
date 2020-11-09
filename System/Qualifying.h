#if !defined(Qualifying_h)
#define Qualifying_h
#include "Track.h"
#include "Car.h"

using namespace std;

class Qualifying: public Track
{
private:
    Car** Cars;
    //string [] CarOrder;
    //string[][] carorderArray;
    int numCars;
public:
    Qualifying(Car**list);
    ~Qualifying();
    virtual void completeNumLaps(int numlaps);
    virtual void setCarList(Car** list);
    Car** getCarList();
    void beginQualifying(); //updates CarOrder with position being in matching array index.

    void setCarPositions(Car** cars);
};

#endif
