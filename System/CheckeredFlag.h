#if !defined(CheckeredFlag_H)
#define CheckeredFlag_H

#include <string>
#include "FlagObserver.h"

#include <iostream>

class CheckeredFlag: public FlagObserver
{
private:
    bool flagRaised ;
    string state;
public:
    CheckeredFlag(Race* subject): FlagObserver(subject){};
    void raiseFlag();
    void lowerFlag();
    void update();
};





#endif

