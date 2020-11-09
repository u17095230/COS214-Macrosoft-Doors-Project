#include "EuropeanTransport.h"

#include <iostream>

using namespace std;

void EuropeanTransport::Transport(Date* D,Location* L)
{
    int day = D->getDay();
    string month =D->convertToString(D->getMonth());
    string coun = L->getCountry();
    string race = L->getRaceway();
    cout<< "Now preparing to transport the equipment and car to " << coun << " " << race << " for the date " << day << " " << month <<endl;
    PrepareTruck(D);
    CharterFlight(D, L);
    PackTruck();
    PackPlane();
    DriveToTrack(L);
    FlyToTrack(L);
    OffLoad(L);
    cout<<endl;
    //im dumb and didnt think to pass the varibles instead of the objects;
}



void EuropeanTransport::PrepareTruck(Date* D)
{
    int day = D->getDay();
    string month =D->convertToString(D->getMonth());
    cout << "A truck has been prepared to transport equipment for " << day << " " << month << endl;
}

void EuropeanTransport::PackTruck()
{
    cout<< "The Truck has been packed and is ready to depart"<<endl;
}

void EuropeanTransport::DriveToTrack(Location* L)
{
    string coun = L->getCountry();
    string race = L->getRaceway();

    cout << "The Truck has departed for " << coun << " " << race << " raceway" << endl;
}

void EuropeanTransport::CharterFlight(Date* D,Location* L)
{
    int day = D->getDay();
    string month =D->convertToString(D->getMonth());
    string coun = L->getCountry();
    string race = L->getRaceway();

    cout << "A flight to transport the cars has been chartered to " << coun << " " << race << " for the date " << day << " " << month << endl;
}

void EuropeanTransport::PackPlane()
{
    cout<< "The Plane has been Pack and is ready to depart" << endl;
}

void EuropeanTransport::FlyToTrack(Location* L)
{
    string coun = L->getCountry();
    string race = L->getRaceway();

    cout << "The Plane has departed for " << coun << " " << race << endl;
}

void EuropeanTransport::OffLoad(Location* L)
{
    string coun = L->getCountry();
    string race = L->getRaceway();
    cout<< "Equipment and Cars have both been successfully offloaded at " << coun << " " << race << endl;
}

EuropeanTransport::~EuropeanTransport()
{
    //cout << " European Transport is going bye bye" << endl;
}

