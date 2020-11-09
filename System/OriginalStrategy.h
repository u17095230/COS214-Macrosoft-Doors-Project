#include <climits>
//
// Created by Alexander Schmid on 2020/11/01.
//

#ifndef UNTITLED_ORIGINALSTRATEGY_H
#define UNTITLED_ORIGINALSTRATEGY_H
#include"Strategy.h"
#include<string>

using namespace std;

class OriginalStrategy: public Strategy{
private:
    int numPitstops;
    int degradeLaps;
    string typeStrat;
    string* degradeAdditions;
    bool changeTyre;

public:
    OriginalStrategy();
    OriginalStrategy(int numStops,int degradeLaps);
    ~OriginalStrategy();
    void handleChange(Race*c, string newStrat);
    void dispConditions();
    void setNumPitstops(int i);
    int getNumPitstops()
    {
        return numPitstops;
    };
    void setTyresForStops(string* tyre);
    string getTyreArrayAt(int i);
    string retTypeStrat();
    void setDegradeLaps(int i);

    void setDegradeAdditions(string* add);
    string* getDegradeAdditions();
    int getDegrade();
    void setChangeTyre(bool i);

    //   bool changeTyre;


};

#endif