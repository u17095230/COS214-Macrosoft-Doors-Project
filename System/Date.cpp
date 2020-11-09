#include "Date.h"

#include <string>

using namespace std;

Date::Date()
{

}
Date::Date(int d, int m)
{
    day = d;
    month = m;
}

void Date::setDay(int D)
{
    day = D;
}

int Date::getDay()
{
    return day;
}


void Date::setMonth(int M)
{
    month = M;
}

int Date::getMonth()
{
    return month;
}


string Date::convertToString(int mon)
{
    string result = "";
    switch(mon)
    {
        case 1 :
            result = "January";
            break;
        case 2 :
            result = "Febuary";
            break;
        case 3 :
            result = "March";
            break;
        case 4 :
            result = "April";
            break;
        case 5 :
            result = "May";
            break;
        case 6 :
            result = "June";
            break;
        case 7 :
            result = "July";
            break;
        case 8 :
            result = "August";
            break;
        case 9 :
            result = "September";
            break;
        case 10 :
            result = "October";
            break;
        case 11 :
            result = "November";
            break;
        case 12 :
            result = "December";
            break;
        default :
            result = "invalid Month";
    }
    return result;
    //switch to convert to string date;
}
