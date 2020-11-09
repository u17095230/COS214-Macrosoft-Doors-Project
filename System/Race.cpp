#include "Race.h"

Race::Race()
{
    strategy = nullptr;
}
Race::Race(Car**list, int wetPitstops,string* wetArray, int wetPitstopsDegrade, string* wetArrayDeg, int veryWetPitstops,string* veryWetArray, int veryWetPitstopsDegrade, string* veryWetArrayDeg)
{

    setCarList(list);
    maxLaps = 0;
    pitstop_gap = rand()%15+10;
    pitstop_counter = 0;

    raceState = "Normal";
    repaired = false;
    degraded = false;

    this->wetPitstops = wetPitstops;
    this->wetPitstopsDegrade = wetPitstopsDegrade;
    this->wetArray = wetArray;
    this->wetArrayDeg = wetArrayDeg;


    this->veryWetPitstops = veryWetPitstops;
    this->veryWetPitstopsDegrade = veryWetPitstopsDegrade;
    this->veryWetArray = veryWetArray;
    this->veryWetArrayDeg = veryWetArrayDeg;

}

Race::~Race()
{
    delete strategy;
    delete Cars[0];
    delete Cars[1];
}



void Race::notify() {
    //iterate through observer list calling update on each
    /*vector<class FlagObserver *>::iterator it;*/

    for (int i = 0 ; i < observers.size();i++) { // for some reason observers are getting added twice, dont ask me how but i fixed it bydividing size by 2 :')
        observers[i]->update();
    }

}
void Race::beginRace(int numlaps)
{
    cout<<"Drivers, in your positions!"<<endl;
    cout<<"5..."<<endl<<"4..."<<endl<<"3..."<<endl<<"2..."<<endl<<"1..."<<endl<<"RACE!!!!!!"<<endl<<"-------------------------------"<<endl;
    maxLaps = numlaps;
    NumPitStops = strategy->getNumPitstops();
    completeNumLaps(numlaps);
}



void Race::endRace() //ends race loop, updates car array scores
{
    currentlap = maxLaps;
    updateScores();
}

void Race::updateScores() //give cars end positions
{
    int rand1 = rand() % 25 + 1;
    int rand2 = rand() % 25 + 1;
    int rand3 = rand() % 5 + 1;
    if (rand1 == rand2)
    {
        if ((rand1 - rand3) < 0)
            rand1 = rand1 + rand3;
        else if ((rand1 + rand3) > 25)
            rand1 = rand1 - rand3;
    }
    Cars[0]->setEndPosition(rand1);
    Cars[1]->setEndPosition(rand2);

    //Alex addition

    Cars[0]->setScore(PositionToScore(rand1));
    Cars[1]->setScore(PositionToScore(rand2));


}



int Race::PositionToScore(int pos)
{
    int score = 0;

    switch(pos) {
        case 1:
            score = 25;
            break;
        case 2:
            score = 18;
            break;
        case 3:
            score = 15;
            break;
        case 4:
            score = 12;
            break;
        case 5:
            score = 10;
            break;
        case 6:
            score = 8;
            break;
        case 7:
            score = 6;
            break;
        case 8:
            score = 4;
            break;
        case 9:
            score = 2;
            break;
        case 10:
            score = 1;
            break;
    }

    return score;
}

void Race::pitstop()
{
    //implement race strategy in here
    if(currentlap!=0) {
        cout << "Taking a pitstop at lap: " << currentlap << endl;
    }
    Cars[0]->changeTyres(strategy->getTyreArrayAt(pitstop_counter));
    Cars[1]->changeTyres(strategy->getTyreArrayAt(pitstop_counter));
    pitstop_counter++;
}


void Race::attach(FlagObserver* f)
{
    observers.push_back(f);
}

void Race::completeNumLaps(int numlaps)
{
    srand(time(0));
    bool anyRaised = false;
    maxLaps = numlaps;
    currentlap = 0;
    pitstopReducer = NumPitStops;

    int wetORnotwet = rand() % 10;
    int tyreDegredation = 100;
    if (wetORnotwet<=4)
    {
        if (wetOrVerywet()) {
            requestStrategy("Wet");
            strategy->setNumPitstops(wetPitstops);
            strategy->setTyresForStops(wetArray);
            displayStrategy();

            NumPitStops = wetPitstops;
            pitstopReducer = wetPitstops;
        }
        else {
            requestStrategy("VeryWet");
            strategy->setNumPitstops(veryWetPitstops);
            strategy->setTyresForStops(veryWetArray);
            displayStrategy();

            NumPitStops = veryWetPitstops;
            pitstopReducer = veryWetPitstops;

        }
        while (currentlap <= maxLaps)
        {

            int irand = rand() % 1000;
            anyRaised = false;

            if (currentlap == maxLaps)
            {
                anyRaised = true;
                setRaceState("Final Lap");
            }
            if (irand > 990 && irand <= 1000 && currentlap<maxLaps-2)
            {
                anyRaised = true;
                setRaceState("Hazardous");
            }
            if ( irand < 10 && currentlap<maxLaps-2)
            {
                /*
                anyRaised = true;
                if (repaired == false) {
                    requestStrategy("Repair"); // repair state requested
                    repaired = true;
                    displayStrategy();
                } */

                anyRaised = true;
                setRaceState("Extremely dangerous");
                if(repaired == false && currentlap > 10) {
                    requestStrategy("Repair"); // repair state requested
                    strategy->setChangeTyre(true);

                    repaired = true;
                    displayStrategy();
                }
            }
            if (anyRaised == false)
                cout <<"Lap number "<<currentlap<< " : Normal lap." << endl;

            // cout << "Normal lap." << endl; ALEX REMOVED THIS



            if ((currentlap%pitstop_gap) == 0 && pitstopReducer!=0 &&currentlap>11)
            {
                pitstop();
                pitstopReducer--;
            }
            currentlap++;

        }
    }
    else
    {
        displayStrategy();
        while (currentlap <= maxLaps)
        {

            int irand = rand() % 1000;
            anyRaised = false;
            if (currentlap == maxLaps)
            {
                anyRaised = true;
                setRaceState("Final Lap");
            }
            if (irand > 990 && irand <= 999 && currentlap < maxLaps-2)// to avoid yellow flag from raising on the last 3 laps
            {
                anyRaised = true;
                setRaceState("Hazardous");
            }
            if (irand < 10 && currentlap < maxLaps-2)
            {
                anyRaised = true;
                setRaceState("Extremely dangerous");
                if (repaired == false && currentlap > 10)
                {
                    requestStrategy("Repair"); // repair state requested
                    strategy->setChangeTyre(true);
                    repaired = true;
                    displayStrategy();
                }
            }
            if (anyRaised == false)
                cout <<"Lap number "<<currentlap<< " : Normal lap." << endl;


            if (currentlap %20 ==0 && currentlap < maxLaps/2 && currentlap > 5)
            {
                int degradation_level = rand() % 100 + 1; //change this to force degradation
                if (degradation_level > 90 && degraded == false)
                {

                    int temp = strategy->getDegrade(); //get before change
                    string* tempArr = strategy->getDegradeAdditions();
                    pitstopReducer = pitstopReducer+temp;

                    NumPitStops = temp;

                    requestStrategy("HighDeg"); //high degradation state requested
                    strategy->setDegradeLaps(temp);

                    strategy->setTyresForStops(tempArr);
                    degraded = true;
                    displayStrategy();
                }
            }

            if ((currentlap % pitstop_gap) == 0 && pitstopReducer!=0)
            {
                pitstop();
                pitstopReducer--;
            }
            currentlap++;

        }
    }

}


void Race::requestStrategy(string newStrat)
{
    cout<<newStrat<<endl;
    strategy->handleChange(this, newStrat);
    //strategy->handleChange(newStrat); //NB CHANGE TO ABOVE ONE<<<<<<<----------------

}


void Race::displayStrategy()
{
    cout << endl;
    strategy->dispConditions();
}


int Race::degradeTyre(int degradation)
{
    return 0;
}

bool Race::wetOrVerywet()
{
    int irand = rand() % 1000;
    if (irand % 3 == 0)
        return false; // very wet
    return true; //true = wet
}

//GETTERS AND SETTERS

void Race::setPitstopgap()
{
    pitstop_gap = maxLaps / NumPitStops;
    pitstop_counter = 1;
}

void Race::setStrategy(Strategy* strat)
{
   // delete this->strategy;
    this->strategy = strat;
}

Car** Race::getCarList()
{
    return Cars;
}

void Race::setCarList(Car** list)
{
    Cars = list;
}

int Race::getCurrentLap()
{
    return currentlap;
}


string Race::getRaceState()
{
    return raceState;
}

void Race::setRaceState(string rS) //acts as trigger point for observer
{
    raceState = rS;
    notify();
}

void Race::setNumberPitstops(int pitstops)
{
    NumPitStops = pitstops;
}

