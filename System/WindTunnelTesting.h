//
// Created by Alexander Schmid on 2020/11/07.
//


#ifndef TESTING_WINDTUNNELTESTING_H
#define TESTING_WINDTUNNELTESTING_H
#include"Testing.h"


class WindTunnelTesting:public Testing  {

private:
    double chanceMultiplier1;
    double chanceMultiplier2;

public:
    WindTunnelTesting();
    void testComponent(CarBuild* i);

};


#endif //TESTING_WINDTUNNELTESTING_H
