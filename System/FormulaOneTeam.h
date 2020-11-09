//
// Created by Alexander Schmid on 2020/11/07.
//

#ifndef FORMULAONETEAM_FORMULAONETEAM_H
#define FORMULAONETEAM_FORMULAONETEAM_H
#include"InputStorage.h"
#include"Logistics.h"
#include"Car.h"

using namespace std;
class FormulaOneTeam {
private:
    int numOfSeasons;
    int racer1Score;
    int racer2Score;
    int totalScore;
    Logistics* logistics;

    int storageCounter;
    InputStorage** store;


    int storageScanner;



    //Car items for racing

    Car * car1;
    Car * car2;
    Car** carrArr;


    //Original data storage for input
    int numPitstops;
    string* array;
    int degradeLaps;
    string* degradation;

    //Wet data storage for input
    int numPitstopsWet;
    string* wetArray;
    int degradeLapsWet;
    string* degradationWet;

    //Very wey data storage for input
    int numPitstopsVeryWet;
    string* veryWetArray;
    int degradeLapsVeryWet;
    string* degradationVeryWet;


public:
    FormulaOneTeam();
    ~FormulaOneTeam();
    FormulaOneTeam(int numSeasons);
    void runChampionships();
    int getNumOfSeasons();
    void setNumOfSeasons(int numOfSeasons);
    void buildCarAndTest();
    void handleLogistics();
    void raceStrategyInput();

    void runRace();

/*
    int getRacer1Score() const;

    void setRacer1Score(int racer1Score);

    int getRacer2Score() const;

    void setRacer2Score(int racer2Score); */

    int getTotalScore() const;

    void setTotalScore(int totalScore);

    bool RaceThisWeek();

    void OrderTyres();

};


#endif //FORMULAONETEAM_FORMULAONETEAM_H
