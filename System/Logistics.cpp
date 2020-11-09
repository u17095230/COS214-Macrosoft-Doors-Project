#include "Logistics.h"
#include "Time.h"
#include "TransportType.h"
#include "EuropeanTransport.h"
#include "NonEuropeanTransportCar.h"
#include "NonEuropeanTransportEquipment.h"

#include <vector>
#include <iostream>

using namespace std;

Logistics::Logistics()
{
    transportType = nullptr;
}


Logistics::Logistics(TransportType* tType)
{
    transportType = tType;
}

Logistics::~Logistics()
{
    delete this->transportType; //delete object that is pointed to
}

void Logistics::SetTransportType(TransportType* tType)
{
    if(transportType != nullptr)
    {
        delete transportType; // delete object and set new
        transportType = nullptr;
    }
    this->transportType = tType;
}

void Logistics::CheckForRaces()
{


    Time& t = Time::getInstance();  //get singleton instance
    vector<Date*> vecDates(t.getRaceDates());
    vector<Location*> vecLocations(t.getRaceLocations()); //create new vectors = to time vectors

    int cDay = t.getCurrentDate()->getDay(); //current time day
    int cMonth = t.getCurrentDate()->getMonth(); //current time month

    int cDay6 = cDay + 6; // this should be the day of the race specified in the time object raceDates vector if it is this week
    int cMonthOverflow =  cMonth;

    int cDay28 =  cDay; // checking for 3 months ahead
    int cMonth28 = cMonth;


    // setting cDay to the next sunday and taking into consideration change of month
    if (cDay6 > 28)
    {
        //cout << "month overflow" << endl;
        switch (cMonth) //this should make the cDay and cDay equivalent to rDay rMonday if the race takes place within a week
        {
            case 1:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 2:
                if (cDay6 > 29)
                {
                    cDay6 = cDay6 - 28;
                    cMonthOverflow++;
                };
                break;
            case 3:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 4:
                if (cDay6 > 30)
                {
                    cDay6 = cDay6 - 30;
                    cMonthOverflow++;
                };
                break;
            case 5:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 6:
                if (cDay6 > 30)
                {
                    cDay6 = cDay6 - 30;
                    cMonthOverflow++;
                };
                break;
            case 7:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 8:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 9:
                if (cDay6 > 30)
                {
                    cDay6 = cDay6 - 30;
                    cMonthOverflow++;
                };
                break;
            case 10:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 11:
                if (cDay6 > 30)
                {
                    cDay6 = cDay6 - 30;
                    cMonthOverflow++;
                };
                break;
            case 12:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow = 1;
                };
                break;
            default :
                cout << "month is too large" << endl;
        }
    }

    // Adding 3 month to date and changing month/day
    for(int j = 0 ; j < 3; j++)
    {
        //cout << "adding 4 weeks" << endl;
        cDay28 = cDay28 + 28;
        if (cDay28 > 28)
        {
            //cout << " overflowing month" << endl;
            switch (cMonth28) //this should make the cDay and cDay equivalent to rDay rMonday if the race takes place within a week
            {
                case 1:
                    if (cDay28 > 31) {
                        cDay28 = cDay28 - 31;
                        cMonth28++;
                    };
                    break;
                case 2:
                    if (cDay28 > 29) {
                        cDay28 = cDay28 - 28;
                        cMonth28++;
                    };
                    break;
                case 3:
                    if (cDay28 > 31) {
                        cDay28 = cDay28 - 31;
                        cMonth28++;
                    };
                    break;
                case 4:
                    if (cDay28 > 30) {
                        cDay28 = cDay28 - 30;
                        cMonth28++;
                    };
                    break;
                case 5:
                    if (cDay28 > 31) {
                        cDay28 = cDay28 - 31;
                        cMonth28++;
                    };
                    break;
                case 6:
                    if (cDay28 > 30) {
                        cDay28 = cDay28 - 30;
                        cMonth28++;
                    };
                    break;
                case 7:
                    if (cDay28 > 31) {
                        cDay28 = cDay28 - 31;
                        cMonth28++;
                    };
                    break;
                case 8:
                    if (cDay28 > 31) {
                        cDay28 = cDay28 - 31;
                        cMonth28++;
                    };
                    break;
                case 9:
                    if (cDay28 > 30) {
                        cDay28 = cDay28 - 30;
                        cMonth28++;
                    };
                    break;
                case 10:
                    if (cDay28 > 31) {
                        cDay28 = cDay28 - 31;
                        cMonth28++;
                    };
                    break;
                case 11:
                    if (cDay28 > 30) {
                        cDay28 = cDay28 - 30;
                        cMonth28++;
                    };
                    break;
                case 12:
                    if (cDay28 > 31) {
                        cDay28 = cDay28 - 31;
                        cMonth28 = 1;
                    };
                    break;
                default :
                    cout << "month is too large" << endl;
            }
        }

    }

    // adding 6 to day to get to sunday/raceday
    cDay28 = cDay28 + 6;
    if (cDay28 > 28)
    {
        switch (cMonth28) //this should make the cDay and cDay equivalent to rDay rMonday if the race takes place within a week
        {
            case 1:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 2:
                if (cDay28 > 29) {
                    cDay28 = cDay28 - 28;
                    cMonth28++;
                };
                break;
            case 3:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 4:
                if (cDay28 > 30) {
                    cDay28 = cDay28 - 30;
                    cMonth28++;
                };
                break;
            case 5:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 6:
                if (cDay28 > 30) {
                    cDay28 = cDay28 - 30;
                    cMonth28++;
                };
                break;
            case 7:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 8:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 9:
                if (cDay28 > 30) {
                    cDay28 = cDay28 - 30;
                    cMonth28++;
                };
                break;
            case 10:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 11:
                if (cDay28 > 30) {
                    cDay28 = cDay28 - 30;
                    cMonth28++;
                };
                break;
            case 12:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28 = 1;
                };
                break;
            default :
                cout << "month is too large" << endl;
        }
    }

    for(int i = 0; i < 21; i++) //loop for every race in vector
    {
        int rDay = vecDates[i]->getDay(); //getting raceday
        int rMonth = vecDates[i]->getMonth();//getting race month

        //compare with race dates
        if(cDay6 == rDay && cMonthOverflow == rMonth) //this should be true is there is a race within the week
        {
            bool euroCheck = vecLocations[i]->getEuropean();
            if(euroCheck == true)
            {
                EuropeanTransport* TransportGo = new EuropeanTransport; //setting the strategy
                this->SetTransportType(TransportGo);
                Transport(vecDates[i],vecLocations[i]);
            }
            else
            {
                NonEuropeanTransportCar* TransportGo = new NonEuropeanTransportCar; //setting the strategy
                this->SetTransportType(TransportGo);
                Transport(vecDates[i],vecLocations[i]);
            }
        }

        // need to check if race is within 3 months and get date
        if((rMonth == 3) && (cDay == 1) && (cMonth == 1)) //transport for any non euro races that take place before the 4th month
        {
            bool euroCheck = vecLocations[i]->getEuropean();
            if (euroCheck == false) {
                NonEuropeanTransportEquipment *TransportGo = new NonEuropeanTransportEquipment; //setting the strategy
                this->SetTransportType(TransportGo);
                Transport(vecDates[i], vecLocations[i]);
            }
        }
        //cDay28 and cMonth28 should be equal to a 3 in the same week 3 months form the cday and cmonth
        if(cDay28 == rDay && cMonth28 == rMonth)
        {
            bool euroCheck = vecLocations[i]->getEuropean();
            if(euroCheck == false)
            {
                NonEuropeanTransportEquipment* TransportGo = new NonEuropeanTransportEquipment; //setting the strategy
                this->SetTransportType(TransportGo);
                Transport(vecDates[i],vecLocations[i]);
            }
        }
        if ((cMonth + 3) < rMonth )//break out the loop if we are checking more than 3 months ahead of current date
        {
            break;
        }

    }

}

void Logistics::Transport(Date* D, Location* L)
{
    this->transportType->Transport(D, L); // call transport from derived class of transport type based on class attribute
}

void Logistics::TransportBackToFactory()
{
    cout << "The cars are being flown back to the Factory" << endl;
}