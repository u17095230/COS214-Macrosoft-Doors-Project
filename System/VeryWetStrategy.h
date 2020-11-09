//
// Created by Alexander Schmid on 2020/11/07.
//

#ifndef UNTITLED_VERYWETSTRATEGY_H
#define UNTITLED_VERYWETSTRATEGY_H
#include"Strategy.h"
#include<string>
#include"VeryWetStrategy.h"
#include"HighTyreDegredationStrategy.h"
#include"RepairsNeededStrategy.h"
#include"OriginalStrategy.h"

using namespace std;

class VeryWetStrategy: public Strategy {
private:
    string afterTyre;
    int numPitstops;
    string typeStrat;
    string* degradeAdditions;
    bool changeTyre;

public:
    VeryWetStrategy();
    VeryWetStrategy(string* tyresArr,int& num,int degradeLaps);
    ~VeryWetStrategy();
    void handleChange(Race*c, string newStrat);
    void dispConditions();
    void setTyresForStops(string* tyre);
    void setNumPitstops(int i);
    string getTyreArrayAt(int i);
    string retTypeStrat();
    int getNumPitstops()
    {
        return numPitstops;
    };
    void setDegradeLaps(int i);
    void setDegradeAdditions(string* add);
    string* getDegradeAdditions();
    int getDegrade();
    void setChangeTyre(bool i);




    int degradeLaps;





};


#endif //UNTITLED_VERYWETSTRATEGY_H
