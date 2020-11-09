#ifndef LOGISTICS_H
#define LOGISTICS_H

#include "TransportType.h"
#include "Date.h"
#include "Location.h"
#include <iostream>

using namespace std;

class Logistics
{
private:
    TransportType * transportType;
public:
    Logistics();
    Logistics(TransportType* transportType); // constructor
    ~Logistics(); // delete pointers
    void CheckForRaces();
    //go through calender checking for races
    //if race is within the week and in europe call set transport type to european and call transport
    //if race is in exactly in 3 months and is not in europe set transport type
    //to non european equipment and call transport.
    //if race is within the week and non european set transport type to
    //non european car and call transport.
    void Transport(Date* D,Location* L); //execute strategy
    void SetTransportType(TransportType* tType);
    void TransportBackToFactory();

};

#endif