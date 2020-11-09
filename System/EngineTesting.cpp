//
// Created by Alexander Schmid on 2020/11/07.
//

#include "EngineTesting.h"

#include "WindTunnelTesting.h"

#include "ElectronicsTesting.h"
#include<iostream>

EngineTesting::EngineTesting()
{
    next = nullptr;
    chanceMultiplier = 0.95;


}

void EngineTesting::testComponent(CarBuild* i)
{

    if(i->getComponent(3)->getTestPassed()==false)
    {
        cout<<"Engine: "<<endl;

        int chance = rand()%100*chanceMultiplier;

        if(chance<=38)
        {
            i->getComponent(3)->setTestPassed(true);
            cout<<endl;
            cout<<"The car has passed its engine testing. The engine is running within acceptable parameters."<<endl;
            cout<<endl;
        }
        else if(chance>38 && chance<92)
        {
            cout<<endl;
            cout<<"There appears to be issues involving the finer tuning of the engine."<<endl;
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"The car is experiencing serious issues ranging from the car struggling to start to random stalls.\n This must be urgently fixed "<<endl;
            cout<<endl;
        }

        chanceMultiplier = chanceMultiplier-0.07;


    }

    next->testComponent(i);

}