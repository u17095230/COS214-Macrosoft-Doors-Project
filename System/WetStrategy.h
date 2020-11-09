//
// Created by Alexander Schmid on 2020/11/07.
//

#ifndef UNTITLED_WETSTRATEGY_H
#define UNTITLED_WETSTRATEGY_H
#include"Strategy.h"
#include<string>
#include"VeryWetStrategy.h"
#include"HighTyreDegredationStrategy.h"
#include"RepairsNeededStrategy.h"
#include"OriginalStrategy.h"


using namespace std;

class WetStrategy: public Strategy {
private:
    string afterTyre;
    int numPitstops;
    string typeStrat;
    string* degradeAdditions;
    bool changeTyre;



public:
    WetStrategy();
    WetStrategy(int num, int degradeLaps);
    ~WetStrategy();
    void handleChange(Race*c, string newStrat);
    void dispConditions();
    void setTyresForStops(string* tyre);
    void setNumPitstops(int i);
    string getTyreArrayAt(int i);
    string retTypeStrat();
    void setDegradeLaps(int i);
    void setDegradeAdditions(string* add);
    int getNumPitstops()
    {
        return numPitstops;
    };
    string* getDegradeAdditions();
    int getDegrade();
    void setChangeTyre(bool i);


    int degradeLaps;


};


#endif //UNTITLED_WETSTRATEGY_H
