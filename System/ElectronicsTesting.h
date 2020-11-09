//
// Created by Alexander Schmid on 2020/11/07.
//


#ifndef TESTING_ELECTRONICSTESTING_H
#define TESTING_ELECTRONICSTESTING_H
#include"Testing.h"

class ElectronicsTesting:public Testing {

private:
    double chanceMultiplier;
    double chanceMultiplier2;

public:
    ElectronicsTesting();
    void testComponent(CarBuild* i);

};


#endif //TESTING_ELECTRONICSTESTING_H
