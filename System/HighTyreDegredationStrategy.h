//
// Created by Alexander Schmid on 2020/11/01.
//

#ifndef UNTITLED_HIGHTYREDEGREDATIONSTRATEGY_H
#define UNTITLED_HIGHTYREDEGREDATIONSTRATEGY_H
#include"Strategy.h"
#include<string>
#include"WetStrategy.h"

using namespace std;

class HighTyreDegredationStrategy: public Strategy {
private:
    string* newPitstopTyre;
    int numPitstopsPlus;
    int degradeLaps;
    string typeStrat;
    string* degradeAdditions;
    bool changeTyre;



public:
    HighTyreDegredationStrategy();
    HighTyreDegredationStrategy(string* tyresArr,int& num,int degradeLaps);//, int extraStops);
    ~HighTyreDegredationStrategy();
    void handleChange(Race*c, string newStrat);
    void dispConditions();
    // void copyAndIncrementTyres(string* tyre);
    void setTyresForStops(string* tyre);
    void setNumPitstops(int i);
    void setExtraPitstops(int i);
    string getTyreArrayAt(int i);
    string retTypeStrat();
    void setDegradeLaps(int i);
    void setDegradeAdditions(string* add);
    string* getDegradeAdditions();
    int getDegrade();
    void setChangeTyre(bool i);

    int getNumPitstops()
    {
        return numPitstops;
    };


};


#endif //UNTITLED_HIGHTYREDEGREDATIONSTRATEGY_H
