//
// Created by Alexander Schmid on 2020/11/07.
//

#ifndef TESTING_TESTING_H
#define TESTING_TESTING_H


#include"CarBuild.h"

class Testing {
private:
    Testing* next;
    int windtunnelUses;     //we may need to make this be static due to multiple teams using it. When the Season change refresh it.


public:
    Testing();
    void setNext(Testing* n);
    virtual void testComponent(CarBuild* i);

    friend class ElectronicsTesting;
    friend class WindTunnelTesting;
    friend class EngineTesting;
    friend class InteriorTesting;
    friend class SuspensionTesting;

};


#endif //TESTING_TESTING_H
