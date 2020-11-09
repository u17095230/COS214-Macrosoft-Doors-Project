#include "Practice.h"

Practice::Practice()
{
}

Practice::Practice(Car ** list)
{
    setCarList(list);
}



void Practice::completeNumLaps(int numlaps)
{
    cout<<endl;
    cout << numlaps << " laps completed during this practice session, driver is now familiarized with track." << endl;
    cout<<endl;

}

void Practice::setCarList(Car** list)
{
    Cars = list;
}