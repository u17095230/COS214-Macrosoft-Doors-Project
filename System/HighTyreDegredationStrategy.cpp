#include "HighTyreDegredationStrategy.h"
#include"VeryWetStrategy.h"
#include<iostream>
HighTyreDegredationStrategy::HighTyreDegredationStrategy()
{

}

HighTyreDegredationStrategy::~HighTyreDegredationStrategy()
{
    delete tyres;
}

HighTyreDegredationStrategy::HighTyreDegredationStrategy(string* tyresArr, int& num, int degradeLaps)
{
    numPitstopsPlus= 0;

    typeStrat = "HighDeg";

    //num = num +degradeLaps;
    numPitstopsPlus = num;

    tyres = new string[numPitstopsPlus];

    for(int i = 0; i<numPitstopsPlus;i++)
    {
        tyres[i] = tyresArr[i];
    }


}

void HighTyreDegredationStrategy::handleChange(Race*c, string newStrat)
{

    if(newStrat=="VeryWet")
    {
        c->setStrategy(new VeryWetStrategy(tyres,numPitstopsPlus,degradeLaps));
    }
    else if(newStrat=="Wet")
    {
        c->setStrategy(new WetStrategy( numPitstopsPlus, degradeLaps));
    }
    else if(newStrat=="Repair")
    {
        c->setStrategy(new RepairsNeededStrategy(numPitstopsPlus,tyres,degradeLaps));
    }
}

void HighTyreDegredationStrategy::dispConditions()
{

    string disp ="Tyre degradation is happening faster than expected. The team has added " + to_string(degradeLaps);
    disp = disp + " pitstops and the following tyres sets are planned for each stop of the day:";
    cout<<disp<<endl;

    for(int i = 0; i<numPitstopsPlus;i++)
    {
        cout<<i+1<<") "<<tyres[i]<<endl;
    }
    cout<<endl;
}


void HighTyreDegredationStrategy::setTyresForStops(string* tyre)
{
    string* temp = new string[numPitstopsPlus+degradeLaps];
    for(int i =0; i<numPitstopsPlus; i++)
    {
        temp[i] = tyres[i];
    }

    for(int i = 0; i<degradeLaps;i++)
    {
        temp[numPitstopsPlus+i] = tyre[i];
    }
    numPitstopsPlus = numPitstopsPlus+degradeLaps;

    tyres = temp;
}

void HighTyreDegredationStrategy::setNumPitstops(int i)
{
    numPitstopsPlus = i;
}

void HighTyreDegredationStrategy::setExtraPitstops(int i)
{
    degradeLaps = i;
}

string HighTyreDegredationStrategy::getTyreArrayAt(int i)
{
    return tyres[i];
}

string HighTyreDegredationStrategy::retTypeStrat()
{
    return typeStrat;
}

void HighTyreDegredationStrategy::setDegradeLaps(int i)
{
    degradeLaps = i;
}

void HighTyreDegredationStrategy::setDegradeAdditions(string* add)
{
    cout<<"Pingo3"<<endl;

    degradeAdditions = new string[degradeLaps];

    for(int i =0; i<degradeLaps;i++)
    {
        degradeAdditions[i] = add[i];
    }
}

string* HighTyreDegredationStrategy::getDegradeAdditions()
{
    return degradeAdditions;

}

int HighTyreDegredationStrategy::getDegrade()
{
    return degradeLaps;
}

void HighTyreDegredationStrategy::setChangeTyre(bool i)
{
    changeTyre = i;
}



