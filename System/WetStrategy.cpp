//
// Created by Alexander Schmid on 2020/11/07.
//

#include "WetStrategy.h"
#include<iostream>


WetStrategy::WetStrategy()
{
    tyres = nullptr;
}

WetStrategy::~WetStrategy()
{
    delete tyres;
}

WetStrategy::WetStrategy(int num, int degradeLaps)
{
    //num++;
    typeStrat = "Wet";

    numPitstops = num;
    this->degradeLaps = degradeLaps;


    tyres = new string[num];

}

void WetStrategy::handleChange(Race*c, string newStrat)
{
    if(newStrat=="VeryWet")
    {
        c->setStrategy(new VeryWetStrategy(tyres,numPitstops,degradeLaps));
    }
    else if(newStrat=="HighDeg")
    {
        c->setStrategy(new HighTyreDegredationStrategy(tyres,numPitstops,degradeLaps));
    }
    else if(newStrat=="Repair")
    {
        c->setStrategy(new RepairsNeededStrategy(numPitstops,tyres,degradeLaps));
    }
}

void WetStrategy::dispConditions()
{
    string disp = "The track is mildly wet and thus intermediate wet tyres (green) must be used.\nTaking this into account," + afterTyre;
    disp = disp + " The tyre choice line up is now:";

    cout<<disp<<endl;
    cout<<endl;

    for(int i = 0; i<numPitstops;i++)
    {
        cout<<i+1<<") "<<tyres[i]<<endl;
    }
    cout<<endl;
    cout<<endl;
}

void WetStrategy::setTyresForStops(string* tyre)
{

    for(int i =0;i<numPitstops;i++)
    {
        tyres[i]=tyre[i];
    }

}

void WetStrategy::setNumPitstops(int i)
{
    numPitstops = i;
}

string WetStrategy::getTyreArrayAt(int i)
{
    return tyres[i];
}

string WetStrategy::retTypeStrat()
{
    return typeStrat;
}

void WetStrategy::setDegradeLaps(int i)
{
    degradeLaps = i;
}

void WetStrategy::setDegradeAdditions(string* add)
{
    degradeAdditions = new string[degradeLaps];

    for(int i =0; i<degradeLaps;i++)
    {
        degradeAdditions[i] = add[i];
    }
}

string* WetStrategy::getDegradeAdditions()
{
    return degradeAdditions;
}

int WetStrategy::getDegrade()
{
    return degradeLaps;
}

void WetStrategy::setChangeTyre(bool i)
{
    changeTyre = i;
}


