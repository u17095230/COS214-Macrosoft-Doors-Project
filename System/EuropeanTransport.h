#ifndef EUROPEANTRANSPORT_H
#define EUROPEANTRANSPORT_H

#include "TransportType.h"

using namespace std;

class EuropeanTransport: public TransportType
{
public:
    void Transport(Date* D,Location* L) override; //executeOperation
    ~EuropeanTransport();
private:
    //all these functions are called by Transport();
    void PrepareTruck(Date* D);
    void PackTruck();
    void DriveToTrack(Location* L);

    void CharterFlight(Date* D,Location* L);
    void PackPlane();
    void FlyToTrack(Location* L);

    void OffLoad(Location* L);
};

#endif
