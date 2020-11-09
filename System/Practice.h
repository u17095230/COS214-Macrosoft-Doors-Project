#if !defined(Practice_H)
#define Practice_H

#include "Track.h"

class Practice: public Track
{
private:

public:
    Practice();
    Practice(Car** list);
    ~Practice(){delete Cars[0];delete Cars[1]; };
    virtual void completeNumLaps(int numlaps);
    virtual void setCarList(Car** list);
};

#endif

