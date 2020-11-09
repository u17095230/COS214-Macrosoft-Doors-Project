//
// Created by Alexander Schmid on 2020/11/07.
//


#ifndef UNTITLED_STRATEGY_H
#define UNTITLED_STRATEGY_H
#include<string>
#include"Race.h"

using namespace std;

class Race;

class Strategy {
private:
    string* tyres;
    string typeStrat;
    int numPitstops;
    bool changeTyre;

public:
    Strategy();
    Strategy(int numStops);
    virtual ~Strategy();
    virtual void handleChange(Race* c, string newStrat)=0;
    virtual void dispConditions()=0;
    virtual void setTyresForStops(string* tyre)=0;
    virtual void setNumPitstops(int i)=0;
    virtual string getTyreArrayAt(int i)=0;
    virtual string retTypeStrat()=0;
    virtual void setDegradeLaps(int i)=0;
    virtual int getNumPitstops()=0;
    virtual void setDegradeAdditions(string* add)=0;
    virtual string* getDegradeAdditions()=0;
    virtual int getDegrade()=0;
    virtual void setChangeTyre(bool i)=0;


    friend class OriginalStrategy;
    friend class WetStrategy;
    friend class VeryWetStrategy;
    friend class HighTyreDegredationStrategy;
    friend class RepairsNeededStrategy;

    int degradeLaps;


};


#endif //UNTITLED_STRATEGY_H
