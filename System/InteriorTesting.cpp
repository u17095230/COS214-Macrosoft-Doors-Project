//
// Created by Alexander Schmid on 2020/11/07.
//

#include "InteriorTesting.h"

#include "WindTunnelTesting.h"

#include "ElectronicsTesting.h"
#include<iostream>

InteriorTesting::InteriorTesting()
{
    next = nullptr;
    chanceMultiplier = 0.95;


}

void InteriorTesting::testComponent(CarBuild* i)
{

    if(i->getComponent(6)!=nullptr)
    {
    if(i->getComponent(6)->getTestPassed()==false) {
        cout<<"Cockpit Ergonomics: "<<endl;

        int chance = rand() % 100 * chanceMultiplier;

        if (chance <= 38) {
            i->getComponent(6)->setTestPassed(true);
            cout << endl;
            cout << "The cockpit and interior is well designed and meets all requirements." << endl;
            cout << endl;
        } else if (chance > 38 && chance < 82) {
            cout << endl;
            cout << "The cockpit is a bit too cramped for the driver to operate the car properly." << endl;
            cout << endl;
        } else {
            cout << endl;
            cout
                    << "The interior of the car is unacceptable. Critical components are missing and thus that are\nthere have a tendency to shift or even fall off."
                    << endl;
            cout << endl;
        }

        chanceMultiplier = chanceMultiplier - 0.07;
    }

    }


}