#include <climits>
//
// Created by Alexander Schmid on 2020/11/01.
//

#include "OriginalStrategy.h"
#include "VeryWetStrategy.h"
#include "WetStrategy.h"
#include "RepairsNeededStrategy.h"
#include "HighTyreDegredationStrategy.h"
#include<iostream>

OriginalStrategy::OriginalStrategy()
{

}

OriginalStrategy::~OriginalStrategy()
{
    delete tyres;
}


OriginalStrategy::OriginalStrategy(int numStops,int degradeLaps)
{
    typeStrat = "Original";

    numPitstops = numStops;
   // this->degradeLaps = degradeLaps;

    tyres = new string[numStops];
}

void OriginalStrategy::handleChange(Race *c, string newStrat)
{
    if(newStrat=="VeryWet")
    {
        c->setStrategy(new VeryWetStrategy(tyres,numPitstops,degradeLaps));
    }
    else if(newStrat=="HighDeg")
    {
        //fix shit with input

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

void OriginalStrategy::dispConditions()
{
    int copyStops = numPitstops;
    string disp ="The races is as planned. The team has " + to_string(numPitstops);
    disp = disp + " pitstops planned and the following tyres sets are planned for each stop:";
    cout<<disp<<endl;

    for(int i = 0; i<numPitstops;i++)
    {
        cout<<i+1<<") "<<tyres[i]<<endl;
    }
    cout<<endl;
}

void OriginalStrategy::setTyresForStops(string* tyre)
{
    for(int i =0;i<numPitstops;i++)
    {
        tyres[i]=tyre[i];
    }
}

void OriginalStrategy::setNumPitstops(int i)
{
    numPitstops = i;
}


string OriginalStrategy::getTyreArrayAt(int i)
{
    return tyres[i];
}

string OriginalStrategy::retTypeStrat()
{
    return typeStrat;
}

void OriginalStrategy::setDegradeLaps(int i)
{
    degradeLaps = i;
}

void OriginalStrategy::setDegradeAdditions(string* add)
{

    degradeAdditions = new string[degradeLaps];

    for(int i =0; i<degradeLaps;i++)
    {
        degradeAdditions[i] = add[i];
    }

}

string* OriginalStrategy::getDegradeAdditions()
{
    return degradeAdditions;
}

int OriginalStrategy::getDegrade()
{
    return degradeLaps;
}

void OriginalStrategy::setChangeTyre(bool i)
{
    changeTyre = i;
}