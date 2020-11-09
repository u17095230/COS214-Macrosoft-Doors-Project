//
// Created by Alexander Schmid on 2020/11/07.
//

#ifndef FORMULAONETEAM_RESULTS_H
#define FORMULAONETEAM_RESULTS_H
#include<iostream>
#include"Car.h"

using namespace std;

class Results {
public:
    Results(Car* c1, Car* c2);
    void displayResults();  //template method
   virtual string dispType()=0;
   virtual void determineResults()=0;
    virtual int returnTotalScore()=0;
   virtual int getD1Score()=0;
   virtual int getD2Score()=0;

protected:
    Car* car1;
    Car* car2;

};


#endif //FORMULAONETEAM_RESULTS_H
