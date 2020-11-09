#if !defined(RedFlag_H)
#define RedFlag_H

#include "FlagObserver.h"
#include "Race.h"
#include <string>
#include <iostream>
using namespace std;
class RedFlag: public FlagObserver
{
private:
    bool flagRaised ;
    string state;
public:
    RedFlag(Race* subject): FlagObserver(subject){};
    void raiseFlag();
    void lowerFlag();
    void update();
};

#endif
