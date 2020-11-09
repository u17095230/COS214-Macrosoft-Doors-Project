#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date
{
private:
    int day;
    int month;
public:
    Date();
    Date(int d, int m);
    void setDay(int D);
    int getDay();
    void setMonth(int M);
    int getMonth();
    string convertToString(int mon);
};

#endif
