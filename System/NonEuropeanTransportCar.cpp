#include "NonEuropeanTransportCar.h"

#include <iostream>

using namespace std;

void NonEuropeanTransportCar::Transport(Date* D,Location* L)
{
    int day = D->getDay();
    string month =D->convertToString(D->getMonth());
    string coun = L->getCountry();
    string race = L->getRaceway();
    cout<< "Now preparing to transport the car to " << coun << " " << race << " for the race on the date " << day << " " << month <<endl;
    CharterFlight(D, L);
    PackPlane();
    FlyToTrack(L);
    OffLoad(L);
    cout<<endl;
    //im dumb and didnt think to pass the varibles instead of the objects;
}

void NonEuropeanTransportCar::CharterFlight(Date* D,Location* L)
{
    int day = D->getDay();
    string month =D->convertToString(D->getMonth());
    string coun = L->getCountry();
    string race = L->getRaceway();

    cout << "A flight to transport the cars has been chartered to " << coun << " " << race << " for the date " << day << " " << month << endl;
}

void NonEuropeanTransportCar::PackPlane()
{
    cout<< "The Plane has been Pack and is ready to depart" << endl;
}

void NonEuropeanTransportCar::FlyToTrack(Location* L)
{
    string coun = L->getCountry();
    string race = L->getRaceway();

    cout << "The Plane has departed for " << coun << " " << race <<endl;
}

void NonEuropeanTransportCar::OffLoad(Location* L)
{
    string coun = L->getCountry();
    string race = L->getRaceway();
    cout<< "Equipment and Cars have both been successfully offloaded at " << coun << " " << race << endl;
}

NonEuropeanTransportCar::~NonEuropeanTransportCar()
{
}
