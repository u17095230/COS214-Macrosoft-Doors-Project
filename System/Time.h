#ifndef TIME_H
#define TIME_H

#include "Date.h"
#include "Location.h"
#include <vector>

using namespace std;

class Time
{
private:
    //Time* onlyInstance;
    vector<Date*> raceDates;
    vector<Location*> raceLocations;
    Date* currentDate;
public:
    static Time& getInstance();
    vector<Date*> getRaceDates();
    void setCurrentDate(int day, int month);
    vector<Location*> getRaceLocations();
    Date* getCurrentDate();
    void ProgressTime();
protected:
    virtual ~Time();
    Time();
    Time(const Time&){};
    Time& operator=(const Time&);
};

#endif
