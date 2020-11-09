#include "Location.h"

#include <string>

using namespace std;

Location::Location()
{

}
Location::Location(string c, string r, bool tf)
{
    country = c;
    raceway = r;
    european = tf;
}

void Location::setCountry(string C)
{
    country = C;
}

void Location::setRaceway(string R)
{
    raceway = R;
}

void Location::setEuropean(bool tf)
{
    european = tf;
}

string Location::getCountry()
{
    return country;
}

string Location::getRaceway()
{
    return raceway;
}

bool Location::getEuropean()
{
    return european;
}
