#ifndef TRANSPORTTYPE_H
#define TRANSPORTTYPE_H
//abstract class
#include "Date.h"
#include "Location.h"
#include <iostream>

using namespace std;

class TransportType
{
public:
    virtual void Transport(Date* D,Location* L) = 0; //execute Operation
    virtual ~TransportType(){};
    //pure virtual function defined by derived classes
};

#endif