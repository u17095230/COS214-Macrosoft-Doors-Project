//
// Created by Alexander Schmid on 2020/11/07.
//

#include "Results.h"

Results::Results(Car* c1, Car* c2)
{
    this->car1 = c1;
    this->car2 = c2;
}

void Results::displayResults()
{
    cout<<dispType()<<"Results:"<<endl;

    determineResults();

}