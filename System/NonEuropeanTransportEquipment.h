#ifndef NONEUROPEANTRANSPORTEQUIPMENT_H
#define NONEUROPEANTRANSPORTEQUIPMENT_H

#include "TransportType.h"
using namespace std;

class NonEuropeanTransportEquipment: public TransportType
{
public:
    void Transport(Date* D,Location* L) override; //executeOperation
    ~NonEuropeanTransportEquipment();
private:
    //all these functions are called by Transport();
    void PrepareContainer(Location* L);
    void PackContainer();
    void ShipContainer(Location* L);
};

#endif
