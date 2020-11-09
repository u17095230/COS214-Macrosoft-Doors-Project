//
// Created by Alexander Schmid on 2020/11/07.
//


#include "VeryWetStrategy.h"
#include"OriginalStrategy.h"
#include<iostream>

using namespace std;

VeryWetStrategy::VeryWetStrategy()
{
    tyres = nullptr;

}

VeryWetStrategy::~VeryWetStrategy()
{
    delete tyres;
}

VeryWetStrategy::VeryWetStrategy(string* tyresArr,int& num, int degradeLaps)
{
    typeStrat = "VeryWet";

    numPitstops = num;
    this->degradeLaps = degradeLaps;


    tyres = new string[num];
}

void VeryWetStrategy::handleChange(Race*c, string newStrat)
{
    if(newStrat=="HighDeg")
    {
        c->setStrategy(new HighTyreDegredationStrategy(tyres,numPitstops,degradeLaps));
    }
    else if(newStrat=="Wet")
    {
        c->setStrategy(new WetStrategy( numPitstops, degradeLaps));
    }
    else if(newStrat=="Repair")
    {

        c->setStrategy(new RepairsNeededStrategy(numPitstops,tyres,degradeLaps));
    }
}

void VeryWetStrategy::dispConditions()
{

    string disp = "The track is very wet and thus full wet tires (blue) must be used.\nTaking this into account," + afterTyre;
    disp = disp + "tyres were chosen as the first tyre to use for when full wet tires can be removed.\nThe tyre choice line up is now:";

    cout<<disp<<endl;
    cout<<""<<endl;

    for(int i = 0; i<numPitstops;i++)
    {
        cout<<i+1<<") "<<tyres[i]<<endl;
    }
    cout<<endl;
    cout<<endl;

}

void VeryWetStrategy::setTyresForStops(string* tyre)
{
    for(int i =0;i<numPitstops;i++)
    {
        tyres[i]=tyre[i];
    }

}

void VeryWetStrategy::setNumPitstops(int i)
{
    numPitstops = i;
}

string VeryWetStrategy::getTyreArrayAt(int i)
{
    return tyres[i];
}

string VeryWetStrategy::retTypeStrat()
{
    return typeStrat;
}

void VeryWetStrategy::setDegradeLaps(int i)
{
    degradeLaps = i;
}

void VeryWetStrategy::setDegradeAdditions(string* add)
{
    degradeAdditions = new string[degradeLaps];

    for(int i =0; i<degradeLaps;i++)
    {
        degradeAdditions[i] = add[i];
    }
}

string* VeryWetStrategy::getDegradeAdditions()
{
    return degradeAdditions;
}

int VeryWetStrategy::getDegrade()
{
    return degradeLaps;
}

void VeryWetStrategy::setChangeTyre(bool i)
{
    changeTyre = i;
}