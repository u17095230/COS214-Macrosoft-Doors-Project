#include "NonEuropeanTransportEquipment.h"

#include <iostream>

using namespace std;

void NonEuropeanTransportEquipment::Transport(Date* D,Location* L)
{
    int day = D->getDay();
    string month =D->convertToString(D->getMonth());
    string coun = L->getCountry();
    string race = L->getRaceway();
    cout<< "Now preparing to transport the equipment to " << coun << " " << race << " 3 months before the race on the date " << day << " " << month <<endl;
    PrepareContainer(L);
    PackContainer();
    ShipContainer(L);
    //im dumb and didnt think to pass the varibles instead of the objects;
    cout<<endl;
}

void NonEuropeanTransportEquipment::PrepareContainer(Location* L)
{
    string coun = L->getCountry();
    string race = L->getRaceway();
    cout<< "A Container has been prepared to ship the needed equipment to " << coun << " " << race << endl;
}

void NonEuropeanTransportEquipment::PackContainer()
{
    cout<< "The Container has been packed and is ready to be shipped" << endl;
}

void NonEuropeanTransportEquipment::ShipContainer(Location* L)
{
    string coun = L->getCountry();
    string race = L->getRaceway();
    cout << "The Ship with the container of equipment has departed for " << coun << " " << race << endl;
}

NonEuropeanTransportEquipment::~NonEuropeanTransportEquipment()
{
}

