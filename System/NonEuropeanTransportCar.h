#ifndef NONEUROPEANTRANSPORTCAR_H
#define NONEUROPEANTRANSPORTCAR_H

#include "TransportType.h"
#include <iostream>
using namespace std;

class NonEuropeanTransportCar: public TransportType
{
public:
    void Transport(Date* D,Location* L) override; //executeOperation
    ~NonEuropeanTransportCar();
private:
    //all these functions are called by Transport();
    void CharterFlight(Date* D,Location* L);
    void PackPlane();
    void FlyToTrack(Location* L);
    void OffLoad(Location* L);
};

#endif