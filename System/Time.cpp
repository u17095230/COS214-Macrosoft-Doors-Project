#include "Time.h"

#include <iostream>
#include <vector>

using namespace std;

Time& Time::getInstance()
{
    static Time onlyInstance;
    return onlyInstance; //call this function to get passed the instance eg. Time& t = Time::getInstance();
}

Time::Time()
{
    raceDates = {(new Date(25,3)),(new Date(8,4)),(new Date(15,4)),(new Date(29,4)),(new Date(13,5)),(new Date(27,5)),
                 (new Date(10,6)),(new Date(24,6)),(new Date(1,7)),(new Date(8,7)),(new Date(22,7)),(new Date(29,7)),(new Date(26,8)),
                 (new Date(2,9)),(new Date(16,9)),(new Date(30,9)),(new Date(7,10)),(new Date(21,10)),(new Date(28,10)),(new Date(11,11)),(new Date(25,11))};

    raceLocations = {(new Location("Australia","Melbourne",false)),(new Location("Bahrain","Bahrain",false)),(new Location("China","Shanghai",false)),(new Location("Azerbaijan","Baku",true)),
                     (new Location("Spain","Barcelona",true)),(new Location("Monaco","Monte Carlo",true)),(new Location("Canada","Montreal",false)),(new Location("France","Le Castellet",true)),
                     (new Location("Austria","Spielberg",true)),(new Location("United Kingdom","Silverstone",true)),(new Location("Germany","Hockenheim",true)),(new Location("Hungary","Budapest",true)),
                     (new Location("Belgium","Spa-Francorchamps",true)),(new Location("Italy","Monza",true)),(new Location("Singapore","Singapore",false)),(new Location("Russia","Sochi",false)),
                     (new Location("Japan","Suzuka",false)),(new Location("USA","Austin",false)),(new Location("Mexico","Mexico City",false)),(new Location("Brazil","Sao Paolo",false)),
                     (new Location("Abu Dhabi","Abu Dhabi",false))};
    currentDate = new Date(1,1);
    cout<< "The Date is set to " << currentDate->getDay() << "-" << currentDate->getMonth() << endl ;
}

Time::~Time() //destructor deleting race dates
{
    for(int i = 0; i < raceDates.size(); i++)
    {
        delete raceDates[i];
    }
    raceDates.clear();
    for(int i = 0; i < raceLocations.size(); i++)
    {
        delete raceLocations[i];
    }
    raceLocations.clear();
}

vector<Date*> Time::getRaceDates()
{
    return raceDates;
}

vector<Location*> Time::getRaceLocations()
{
    return raceLocations;
}
void Time::ProgressTime()
{
    //get day/ month
    //add 7 to day
    //if day if over certain number ect 30,31 or 28 subtract that number from date and increment month
    //cout new date
    int cDay = currentDate->getDay();
    int cMonth = currentDate->getMonth();

    cDay = cDay + 7;
    if (cDay > 28)
    {
        switch (cMonth)
        {
            case 1:
                if (cDay > 31)
                {
                    cDay = cDay - 31;
                    cMonth++;
                }
                break;
            case 2:
                if (cDay > 29)
                {
                    cDay = cDay - 28;
                    cMonth++;
                }
                break;
            case 3:
                if (cDay > 31)
                {
                    cDay = cDay - 31;
                    cMonth++;
                }
                break;
            case 4:
                if (cDay > 30)
                {
                    cDay = cDay - 30;
                    cMonth++;
                }
                break;
            case 5:
                if (cDay > 31)
                {
                    cDay = cDay - 31;
                    cMonth++;
                }
                break;
            case 6:
                if (cDay > 30)
                {
                    cDay = cDay - 30;
                    cMonth++;
                }
                break;
            case 7:
                if (cDay > 31)
                {
                    cDay = cDay - 31;
                    cMonth++;
                }
                break;
            case 8:
                if (cDay > 31)
                {
                    cDay = cDay - 31;
                    cMonth++;
                }
                break;
            case 9:
                if (cDay > 30)
                {
                    cDay = cDay - 30;
                    cMonth++;
                }
                break;
            case 10:
                if (cDay > 31)
                {
                    cDay = cDay - 31;
                    cMonth++;
                }
                break;
            case 11:
                if (cDay > 30)
                {
                    cDay = cDay - 30;
                    cMonth++;
                }
                break;
            case 12:
                if (cDay > 31)
                {
                    cDay = cDay - 31;
                    cMonth = 1;
                }
                break;
            default :
                cout<< "month is too large" << endl;

        }
    }
    currentDate->setDay(cDay);
    currentDate->setMonth(cMonth);
    cout << "The Time has been advance by a week, the date is now " << cDay << "-" << cMonth << endl;
    cout<<endl;

}

Date *Time::getCurrentDate() {
    return currentDate;
}

void Time::setCurrentDate(int day, int month)
{
    delete this->currentDate;
    currentDate = new Date(day,month);
}