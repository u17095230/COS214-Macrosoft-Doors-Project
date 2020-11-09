//
// Created by Alexander Schmid on 2020/11/07.
//

#ifndef TESTING_ENGINETESTING_H
#define TESTING_ENGINETESTING_H
#include"Testing.h"

class EngineTesting:public Testing  {

private:
    double chanceMultiplier;

public:
    EngineTesting();
    void testComponent(CarBuild* i);

};


#endif //TESTING_ENGINETESTING_H
