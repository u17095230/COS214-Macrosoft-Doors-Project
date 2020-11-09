//
// Created by Alexander Schmid on 2020/11/08.
//

#include "ResultDriver.h"

ResultDriver::ResultDriver(Car* c1, Car* c2):Results(c1,c2)
{
    car1 = c1;
    car2 = c2;
}

string ResultDriver::dispType()
{
    return "Driver's Championship ";
}

void ResultDriver::determineResults()
{
    driver1Score = car1->getScore();
    driver2Score = car2->getScore();

    cout<<endl;


    cout<<car1->getDriverName()<<"'s score: "<<car1->getScore()<<endl;
    cout<<car1->getDriverName()<<"'s postion: "<<car1->getEndPosition()<<endl;

    cout<<endl;
    cout<<car2->getDriverName()<<"'s score:"<<car2->getScore()<<endl;
    cout<<car2->getDriverName()<<"'s postion: "<<car2->getEndPosition()<<endl;

}

int ResultDriver::returnTotalScore()
{
    return 0;
}

int ResultDriver::getD1Score()
{
    return driver1Score;
}


int ResultDriver::getD2Score()
{
    return driver2Score;
}
