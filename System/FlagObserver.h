#if !defined(FlagObserver_h)
#define FlagObserver_h



/*#include "CheckeredFlag.h"
#include "RedFlag.h"
#include "YellowFlag.h"*/
#include "Race.h"
#include <string>
#include <iostream>
using namespace std;
class Race;

class FlagObserver
{
protected:
    Race* subject;
    bool flagRaised ;
public:
    //Race *subject;
    FlagObserver();
    FlagObserver(Race* subject);
    virtual ~FlagObserver();
    virtual void raiseFlag()=0;
    virtual void lowerFlag()=0;
    virtual void changeFlagState(); // if flag raised lower vica versa
    virtual void update();

    /*friend class CheckeredFlag;
    friend class RedFlag;
    friend class YellowFlag;*/
};

#endif
