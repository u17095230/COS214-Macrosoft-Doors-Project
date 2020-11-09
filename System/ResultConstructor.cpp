//
// Created by Alexander Schmid on 2020/11/08.
//

#include "ResultConstructor.h"

ResultConstructor::ResultConstructor(Car* c1, Car* c2):Results(c1,c2)
{
 //  cout<<"POROPO: "<<c1->getEndPosition()<<endl;
    car1 = c1;
    car2 = c2;
}



string ResultConstructor::dispType()
{
    return "Constructor's Championship ";
}

void ResultConstructor::determineResults()
{
    cout<<endl;

    totalScore = 0;

    totalScore = car1->getScore()+car2->getScore();

    cout<<"Your team's score in the race: "<<endl;
    cout<<totalScore<<endl;

}

int ResultConstructor::returnTotalScore()
{
    return totalScore;
}

int ResultConstructor::getD1Score()
{
    return 0;
}

int ResultConstructor::getD2Score()
{
    return 0;
}