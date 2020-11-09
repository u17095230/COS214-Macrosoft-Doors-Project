//
// Created by Alexander Schmid on 2020/11/07.
//

#ifndef FORMULAONETEAM_SUSPENSIONTESTING_H
#define FORMULAONETEAM_SUSPENSIONTESTING_H

#include"Testing.h"

class SuspensionTesting:public Testing {

private:
    double chanceMultiplier;

public:
    SuspensionTesting();

    void testComponent(CarBuild *i);

};

#endif //FORMULAONETEAM_SUSPENSIONTESTING_H
