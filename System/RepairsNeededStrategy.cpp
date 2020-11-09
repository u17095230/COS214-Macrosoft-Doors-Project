//
// Created by Alexander Schmid on 2020/11/07.
//

//
// Created by Alexander Schmid on 2020/11/01.
//

#include "RepairsNeededStrategy.h"
#include<iostream>

RepairsNeededStrategy::RepairsNeededStrategy()
{
    changeTyre = true;

}

RepairsNeededStrategy::~RepairsNeededStrategy()
{
    delete tyres;
}

RepairsNeededStrategy::RepairsNeededStrategy(int num, string* tyresArr,int degradeLaps)
{
    typeStrat = "Repairs";

    changeTyre = true;
    numPitstops = num;
    this->degradeLaps = degradeLaps;

    tyres = new string[numPitstops];

    for(int i = 0; i<numPitstops;i++)
    {
        tyres[i] = tyresArr[i];
    }




}

void RepairsNeededStrategy::handleChange(Race*c, string newStrat)
{

    if(newStrat=="VeryWet")
    {
        c->setStrategy(new VeryWetStrategy(tyres,numPitstops,degradeLaps));
    }
    else if(newStrat=="HighDeg")
    {
        c->setStrategy(new HighTyreDegredationStrategy(tyres,numPitstops,degradeLaps));
    }
    else if(newStrat=="Wet")
    {
        c->setStrategy(new WetStrategy( numPitstops, degradeLaps));
    }

}

void RepairsNeededStrategy::dispConditions()
{
    string disp ="The car needs repairs and must make a pitstop. ";

    if(changeTyre==false)
    {
        disp = disp + "The team has chosen not to change tyres in this situation.";
    }
    else
    {
        disp = disp + "The team has chosen to use this as a tyre change stop as well as a repair stop.";
    }

    cout<<disp<<endl;


    cout<<endl;
}




void RepairsNeededStrategy::setTyresForStops(string* newTyre)
{
    newPitstopTyre = newTyre[0];


    if (newPitstopTyre=="no"||newPitstopTyre=="No")
    {
        changeTyre = false;
    }
    else
    {
        changeTyre = true;
    }


}

void RepairsNeededStrategy::setNumPitstops(int i)
{

}

string RepairsNeededStrategy::getTyreArrayAt(int i)
{
    return tyres[i];
}

string RepairsNeededStrategy::retTypeStrat()
{
    return typeStrat;
}

void RepairsNeededStrategy::setDegradeLaps(int i)
{
    degradeLaps = i;
}


void RepairsNeededStrategy::setDegradeAdditions(string* add)
{
    degradeAdditions = new string[degradeLaps];

    for(int i =0; i<degradeLaps;i++)
    {
        degradeAdditions[i] = add[i];
    }
}

string* RepairsNeededStrategy::getDegradeAdditions()
{
   return degradeAdditions;
}

int RepairsNeededStrategy::getDegrade()
{
    return degradeLaps;
}

void RepairsNeededStrategy::setChangeTyre(bool i)
{
    changeTyre = i;
}