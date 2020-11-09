//
// Created by Alexander Schmid on 2020/11/08.
//

#ifndef FORMULAONETEAM_RESULTDRIVER_H
#define FORMULAONETEAM_RESULTDRIVER_H
#include<string>
#include"Results.h"
#include"Car.h"

using namespace std;

class ResultDriver: public Results {
private:
    int driver1Score;
    int driver2Score;
public:
    ResultDriver(Car* c1, Car* c2);
    string dispType();
    void determineResults();
    int returnTotalScore();
    int getD1Score();
    int getD2Score();


};


#endif //FORMULAONETEAM_RESULTDRIVER_H
