#if !defined(Race_H)
#define Race_H

#include <list>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "time.h"
#include "Car.h"
#include "Track.h"
#include "Strategy.h"
//#include "../RaceStrategy/OriginalStrategy.h"
#include "FlagObserver.h"
//#include "Qualifying.h"
/*class YellowFlag;
class RedFlag;
class CheckeredFlag;*/

#include"Strategy.h"
using namespace std;

class  Strategy;

class Race: public Track
{
protected:
    Strategy* strategy;
    int maxLaps;

    vector<class FlagObserver*> observers;

    string raceState;
    int currentlap;
    int NumPitStops;
    int pitstop_gap;
    int pitstop_counter;
    bool degraded;
    bool repaired;
    Car ** Cars;
    int pitstopReducer;

    //Wet strategy variables
    int wetPitstops;
    int wetPitstopsDegrade;
    string* wetArray;
    string* wetArrayDeg;

    //Very wet strategy variables
    int veryWetPitstops;
    int veryWetPitstopsDegrade;
    string* veryWetArray;
    string* veryWetArrayDeg;


    //Repairs


public:

    Race();
    Race(Car**list, int wetPitstops,string* wetArray, int wetPitstopsDegrade, string* wetArrayDeg, int veryWetPitstops,string* veryWetArray, int veryWetPitstopsDegrade, string* veryWetArrayDeg);
    ~Race();

    void checkState(); // continuously running
    void notify();
    void beginRace(int numlaps); //will call completeNumLaps method
    //bool continueRace();
    //bool stopRace(); //stops/pauses race and returns current lapnum
    void endRace(); //race is finished, use this to update positions of cars/drivers
    void updateScores();
    void pitstop();

    int PositionToScore(int pos);


    void attach(FlagObserver* f); // attaches observer
    virtual void completeNumLaps(int numlaps);

    void requestStrategy(string newStrat);
    void displayStrategy();

    int degradeTyre(int degredation);
    bool wetOrVerywet();



    //getters and setters
    void setPitstopgap();
    void setStrategy(Strategy* strat);
    Car** getCarList();
    virtual void setCarList(Car** list);
    int getCurrentLap();
    string getRaceState();
    void setRaceState(string rS);
    void setNumberPitstops(int pitstops);
};

#endif

