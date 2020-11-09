#include "Qualifying.h"

Qualifying::Qualifying(Car ** list)
{
    setCarList(list);



}

Qualifying::~Qualifying()
{
    delete Cars[0];
    delete Cars[1];
}

void Qualifying::completeNumLaps(int numlaps)
{
    cout << numlaps << " laps completed during qualifying." << endl<<"Driver Positions updated : "<<endl<<"------------------------"<<endl;
    setCarPositions(Cars);
}

void Qualifying::setCarList(Car** list)
{
    Cars = list;
}

Car** Qualifying::getCarList()
{
    return Cars;
}

void Qualifying::beginQualifying()
{

}



void Qualifying::setCarPositions(Car**cars)
{
    int rand1 = rand() % 25 + 1;
    int rand2 = rand() % 25 + 1;
    int rand3 = rand() % 5 + 1;
    if (rand1 == rand2)
    {
        if ((rand1 - rand3) < 0)
            rand1 = rand1 + rand3;
        else if ((rand1 + rand3) > 25)
            rand1 = rand1 - rand3;
    }
    Cars[0]->setStartPosition(rand1);

    Cars[1]->setStartPosition(rand2);
}
