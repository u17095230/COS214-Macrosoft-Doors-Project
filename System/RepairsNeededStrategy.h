//
// Created by Alexander Schmid on 2020/11/07.
//


#ifndef UNTITLED_REPAIRSNEEDEDSTRATEGY_H
#define UNTITLED_REPAIRSNEEDEDSTRATEGY_H
#include"Strategy.h"
#include<string>
#include"VeryWetStrategy.h"
#include"HighTyreDegredationStrategy.h"
#include"OriginalStrategy.h"

using namespace std;

class RepairsNeededStrategy: public Strategy {
private:
    bool changeTyre;
    string newPitstopTyre;
    int numPitstops;
    string typeStrat;
    string* degradeAdditions;

public:
    RepairsNeededStrategy();
    ~RepairsNeededStrategy();
    RepairsNeededStrategy(int num,string* tyreArr,int degradeLaps);
    void handleChange(Race*c, string newStrat);
    void dispConditions();
    void setTyresForStops(string* newTyre);
    void setNumPitstops(int i);
    string getTyreArrayAt(int i);
    string retTypeStrat();
    void setDegradeLaps(int i);
    void setDegradeAdditions(string* add);
    int getDegrade();
    void setChangeTyre(bool i);

    int getNumPitstops()
    {
        return numPitstops;
    };

    string* getDegradeAdditions();




};


#endif //UNTITLED_REPAIRSNEEDEDSTRATEGY_H