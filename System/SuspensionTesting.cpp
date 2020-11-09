//
// Created by Alexander Schmid on 2020/11/07.
//

#include "SuspensionTesting.h"


#include "WindTunnelTesting.h"

#include "ElectronicsTesting.h"
#include<iostream>

SuspensionTesting::SuspensionTesting()
{
    next = nullptr;
    chanceMultiplier = 0.95;


}

void SuspensionTesting::testComponent(CarBuild* i)
{

    if(i->getComponent(5)!=nullptr) {
        if (i->getComponent(5)->getTestPassed() == false) {
            cout<<"Suspension:"<<endl;

            int chance = rand() % 100 * chanceMultiplier;

            if (chance <= 38) {
                i->getComponent(5)->setTestPassed(true);
                cout << endl;
                cout << "The car has passed its suspension testing." << endl;
                cout << endl;
            } else if (chance > 38 && chance < 92) {
                cout << endl;
                cout << "The suspension seems to be too stiff." << endl;
                cout << endl;
            } else {
                cout << endl;
                cout
                        << "The suspension of the vehicle is too weak and\nthus the chassis of the car is resting on the ground. This needs to be redone"
                        << endl;
                cout << endl;
            }

            chanceMultiplier = chanceMultiplier - 0.07;


        }
    }
    next->testComponent(i);

}