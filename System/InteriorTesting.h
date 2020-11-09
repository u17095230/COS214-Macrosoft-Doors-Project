//
// Created by Alexander Schmid on 2020/11/07.
//

#ifndef FORMULAONETEAM_INTERIORTESTING_H
#define FORMULAONETEAM_INTERIORTESTING_H

#include"Testing.h"

class InteriorTesting: public Testing {

private:
    double chanceMultiplier;

public:
    InteriorTesting();
    void testComponent(CarBuild* i);
};


#endif //FORMULAONETEAM_INTERIORTESTING_H
