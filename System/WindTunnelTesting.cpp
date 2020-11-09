//
// Created by Alexander Schmid on 2020/11/06.
//

#include "WindTunnelTesting.h"

#include "ElectronicsTesting.h"
#include<iostream>

WindTunnelTesting::WindTunnelTesting()
{
    next = nullptr;
    chanceMultiplier1 = 0.95;
    chanceMultiplier2 = 0.95;

}

void WindTunnelTesting::testComponent(CarBuild* i)
{
   // cout<<"TICKO: "<<i->getComponent(2)<<endl;

    if(i->getComponent(0)->getTestPassed()==false)
    {
        cout<<"Aerodynamics:"<<endl;

        int chance = rand()%100*chanceMultiplier1;
   //     cout<<"REGGIE"<<endl;

        if(chance<=23)
        {
            i->getComponent(0)->setTestPassed(true);
            cout<<endl;
            cout<<"The car has passed its aerodynamics testing."<<endl;
            cout<<endl;
        }
        else if(chance>23 && chance<92)
        {
            cout<<endl;
            cout<<"There are some slight issues with the cards aerodynamics."<<endl;
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"The aerodynamics of the car are causing major drag and wind resistance."<<endl;
            cout<<endl;
        }
        windtunnelUses = windtunnelUses-1;

        chanceMultiplier1 = chanceMultiplier1-0.07;
        cout<<"You have "<<windtunnelUses<<" windtunnel tokens left."<<endl;
        cout<<endl;
    }

    //REDUCE WINDTUNNEL TICKETS



    if(i->getComponent(1)->getTestPassed()==false)
    {
        cout<<"Chassis:"<<endl;
        int chance = rand()%100*chanceMultiplier2;

        if(chance<=23)
        {
            i->getComponent(1)->setTestPassed(true);
            cout<<endl;
            cout<<"The car has passed its chassis testing. The wind resistance of the base chassis is at a minimum"<<endl;
            cout<<endl;
        }
        else if(chance>23 && chance<85)
        {
            cout<<endl;
            cout<<"The base chassis of the car is causing too much wind resistance. This must be improved."<<endl;
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"The base chassis is causing major wind resistance and even flexs due to this is certain areas."<<endl;
            cout<<endl;
        }
        windtunnelUses = windtunnelUses-1;

        chanceMultiplier2 = chanceMultiplier2-0.07;
        cout<<"You have "<<windtunnelUses<<" windtunnel tokens left."<<endl;
        cout<<endl;
    }

    next->testComponent(i);

}
