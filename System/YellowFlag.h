#if !defined(YellowFlag_H)
#define YellowFlag_H

#include "FlagObserver.h"
#include <string>
#include <iostream>
using namespace std;

class YellowFlag: public FlagObserver
{
private:
    bool flagRaised ;
public:
    YellowFlag(Race* subject): FlagObserver(subject){};
    void raiseFlag();
    void lowerFlag();
    void update();
};



#endif
