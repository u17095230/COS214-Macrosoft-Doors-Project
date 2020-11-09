#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;

class Location
{
private:
    string country;
    string raceway;
    bool european;
public:
    Location();
    Location(string c,string r, bool tf);
    void setCountry(string C);
    string getCountry();
    void setRaceway(string R);
    string getRaceway();
    void setEuropean(bool tf);
    bool getEuropean();
};

#endif
