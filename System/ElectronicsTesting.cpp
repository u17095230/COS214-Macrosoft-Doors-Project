//
// Created by Alexander Schmid on 2020/11/07.
//
#include "EngineTesting.h"

#include "WindTunnelTesting.h"

#include "ElectronicsTesting.h"

#include<iostream>

ElectronicsTesting::ElectronicsTesting()
{
    next = nullptr;
    chanceMultiplier = 0.95;
    chanceMultiplier2 = 0.95;
}

void ElectronicsTesting::testComponent(CarBuild* i)
{

    if(i->getComponent(2)->getTestPassed()==false)
    {
        cout<<"Electronics: "<<endl;

        int chance = rand()%100;
        chance = chance*chanceMultiplier; //chance multiplier is used to slowly increase the chance of a successful test.

        if(chance<=38)
        {
            i->getComponent(2)->setTestPassed(true);
            cout<<endl;
            cout<<"The car has passed its electronics testing. All the electronics are working exactly as intended."<<endl;
            cout<<endl;
        }
        else if(chance>38 && chance<92)
        {
            cout<<endl;
            cout<<"There are some issues with the electronics of the car. They must be fixed"<<endl;
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"The cars electronic systems are in a terrible state. There are issues ranging from the break lights not\nworking to the onboard computer failing."<<endl;
            cout<<endl;
        }

        chanceMultiplier=chanceMultiplier-0.07;
    }




    if(i->getComponent(4)!=nullptr) {
        if (i->getComponent(4)->getTestPassed()==false) {
            cout<<"Warning System: "<<endl;

            int chance = rand() % 100;
            chance = chance * chanceMultiplier; //chance multiplier is used to slowly increase the chance of a successful test.

            if (chance <= 38) {
                i->getComponent(4)->setTestPassed(true);
                cout << endl;
                cout
                        << "The car has passed its warning system testing. All the warning systems are working exactly as intended."
                        << endl;
                cout << endl;
            } else if (chance > 38 && chance < 92) {
                cout << endl;
                cout << "There are some issues with the warning system of the car. They must be fixed" << endl;
                cout << endl;
            } else {
                cout << endl;
                cout
                        << "The cars warning systems are completely failing to activate when needed and tend to activate seemingly at random."
                        << endl;
                cout << endl;
            }

            chanceMultiplier2 = chanceMultiplier2 - 0.07;
        }
    }
    next->testComponent(i);

}