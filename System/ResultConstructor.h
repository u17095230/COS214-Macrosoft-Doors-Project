//
// Created by Alexander Schmid on 2020/11/08.
//

#ifndef FORMULAONETEAM_RESULTCONSTRUCTOR_H
#define FORMULAONETEAM_RESULTCONSTRUCTOR_H
#include<string>
#include"Results.h"
#include"Car.h"

using namespace std;

class ResultConstructor: public Results {
private:
    int totalScore;
public:
    ResultConstructor(Car* c1,Car* c2);
    string dispType();
    void determineResults();
    int returnTotalScore();
    int getD1Score();
    int getD2Score();
};


#endif //FORMULAONETEAM_RESULTCONSTRUCTOR_H
