//
// Created by Alexander Schmid on 2020/11/07.
//

#include "FormulaOneTeam.h"
#include <iostream>

#include"CarBuild.h"
#include"ConcreteCarBuilder.h"
#include"EngineeringTeam.h"
#include"Testing.h"
#include"ElectronicsTesting.h"
#include"EngineTesting.h"
#include"WindTunnelTesting.h"
#include"SuspensionTesting.h"
#include"InteriorTesting.h"
#include"Car.h"
#include"Practice.h"
#include"Qualifying.h"
#include"Race.h"
#include"RedFlag.h"
#include"Strategy.h"
#include"Track.h"
#include"YellowFlag.h"
#include"CheckeredFlag.h"
#include"Time.h"
#include"OriginalStrategy.h"
#include"Results.h"
#include"ResultConstructor.h"
#include"ResultDriver.h"


FormulaOneTeam::FormulaOneTeam()
{
    numOfSeasons = 0;
    racer1Score = 0;
    racer2Score = 0;
    totalScore = 0;
}


FormulaOneTeam::FormulaOneTeam(int numSeasons)
{
    numOfSeasons = numSeasons;
    racer1Score = 0;
    racer2Score = 0;
    totalScore = 0;
    logistics = new Logistics();

    store = new InputStorage*[22];
    storageCounter = 0;
    storageScanner = 0;
}

FormulaOneTeam::~FormulaOneTeam()
{
    delete logistics;
    delete store;
    delete car1;
    delete car2;
    delete carrArr;
}



void FormulaOneTeam::buildCarAndTest()
{

    //Build car

    ConcreteCarBuilder* builder = new ConcreteCarBuilder();
    EngineeringTeam* team1 = new EngineeringTeam(builder);
    int budget1 = 0;


    //Testing setup
    Testing* carTester = new WindTunnelTesting();
    carTester->setNext(new ElectronicsTesting);
    carTester->setNext(new EngineTesting);
    carTester->setNext(new SuspensionTesting);
    carTester->setNext(new InteriorTesting);



    //Budget
    do
    {
        cout<<endl;
        cout<<"Please enter the budget you want to assign to the team 1 (From $175000000 to $400000000)."<<endl;
        cout<<"$";
        cin>>budget1;
        cout<<endl;

        if(budget1<175000000)
        {
            cout<<"Your budget is too low, pleas try again."<<endl;
            cout<<endl;
        }
    }
    while(budget1<175000000);




    team1->setBudget(budget1);




    cout<<"First Formula 1 Car Development"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<endl;



    team1->constructCar();
    CarBuild* car1 = builder->getCar();





    //Testing
    int testingCounter =1;
    cout<<endl;
    cout<<"Testing Car 1:"<<endl;
    cout<<endl;

    bool fullPass;

    do {
        cout<<"Testing attempt: "<<testingCounter<<endl;

        carTester->testComponent(car1);

         fullPass = true;

        for(int i = 0;i<7;i++)
        {
            if(car1->getComponent(i)!=nullptr && car1->getComponent(i)->getTestPassed()==false)
            {
                fullPass = false;
            }
        }

        testingCounter++;
    }
    while(fullPass==false);



    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<"Second Formula 1 Car Development"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<endl;

    team1->constructCar();
    CarBuild* car2 = builder->getCar();
    testingCounter = 1;

    cout<<"Testing Car 2:"<<endl;
    cout<<endl;
    do {
        cout<<"Testing attempt: "<<testingCounter<<endl;

        carTester->testComponent(car2);

        fullPass = true;

        for(int i = 0;i<7;i++)
        {
            if(car2->getComponent(i)!=nullptr && car2->getComponent(i)->getTestPassed()==false)
            {
                fullPass = false;
            }
        }

        testingCounter++;
    }
    while(fullPass==false);


    cout<<endl;
    cout<<"------------------------------------------- "<<endl;
    cout<<"Engineering and Testing has been completed"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<endl;
}

void FormulaOneTeam::handleLogistics()
{
    logistics->CheckForRaces();
}

void FormulaOneTeam::runRace()
{

     car1 = new Car("Vettel");
     car2 = new Car("Hamilton");


    carrArr = new Car*[2];

    //Create car objects

    carrArr[0] = car1;
    carrArr[1] = car2;

    int practice = 5;
    int qualifyingLaps = 50;
    int raceLaps = 78;

    cout<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"RACING: "<<endl;
    cout<<"Practice sessions:"<<endl;
    Practice* monte_carlo_practice = new Practice(carrArr);
    monte_carlo_practice->completeNumLaps(5);

    cout<<endl;

    cout<<"Qualifying sessions:"<<endl;
    cout<<endl;

    Qualifying* monte_carlo_qualifying = new Qualifying(carrArr);
    monte_carlo_qualifying->completeNumLaps(qualifyingLaps);
    cout<<endl;
    //Car ** temp = monte_carlo_qualifying->getCarList();

    InputStorage* iS = store[storageScanner];

    Race* monte_carlo_race= new Race(carrArr,iS->getNumPitstopsWet(),iS->getWetArray(),iS->getDegradeLapsWet(),iS->getDegradationWet(),iS->getNumPitstopsVeryWet(),iS->getVeryWetArray(),iS->getDegradeLapsVeryWet(),iS->getDegradationVeryWet());



    Strategy* strategy1 = new OriginalStrategy(iS->getNumPitstops(),iS->getDegradeLaps());
    strategy1->setTyresForStops(iS->getArray());

    strategy1->setDegradeLaps(iS->getDegradeLaps());
    strategy1->setDegradeAdditions(iS->getDegradation());



    monte_carlo_race->setStrategy(strategy1); //set strategy

    storageScanner++;



    //Observer pattern
    FlagObserver* yellow = new YellowFlag(monte_carlo_race);
    FlagObserver* red = new RedFlag(monte_carlo_race);
    FlagObserver* checkered = new CheckeredFlag(monte_carlo_race);

    //Attach observers

    /*
    monte_carlo_race->attach(yellow);
    monte_carlo_race->attach(red);
    monte_carlo_race->attach(checkered); */

    //Start main race
    monte_carlo_race->beginRace(raceLaps);





}

void FormulaOneTeam::raceStrategyInput()
{
    int tyreSetNumbers = 5;
    int tyreSetNumbersWet = 5;
    int tyreSetNumbersVeryWet = 5;

    int soft = 0;
    int softRestore = 0;
    int medium = 0;
    int mediumRestore = 0;
    int hard = 0;
    int hardRestore = 0;

    int softWet = 0;
    int mediumWet = 0;
    int hardWet = 0;

    int softVeryWet = 0;
    int mediumVeryWet = 0;
    int hardVeryWet = 0;



    int numPitstops = 0;


    string* tyreOrderArray = new string[5];

    cout<<endl;
    cout<<"TYRE ORDER:"<<endl;
    cout<<endl;


    //Input your 5 sets of tyres
    cout << "Input the tyres you want to order: " << endl;

    bool restart = true;

    do {


        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ") ";
            cin >> tyreOrderArray[i];

            if (tyreOrderArray[i] == "soft") {
                soft++;
                softWet++;
                softVeryWet++;
                softRestore++;
            } else if (tyreOrderArray[i] == "medium") {
                medium++;
                mediumWet++;
                mediumVeryWet++;
                mediumRestore++;
            } else if (tyreOrderArray[i] == "hard") {
                hard++;
                hardWet++;
                hardVeryWet++;
                hardRestore++;
            }
        }



        for(int i =0; i<5;i++)
        {
            for(int j = i; j<5; j++)
            {
                if(tyreOrderArray[i]!=tyreOrderArray[j])
                {
                    restart = false;
                }
            }
        }

        if(restart==true)
        {
            cout<<"You must have at least two different tyre sets, please try again"<<endl;
            cout<<endl;
        }

    }
    while(restart==true);







    cout<<endl;
    cout<<"ORIGINAL STRATEGY:"<<endl;
    cout<<endl;

    //Original Strategy

    do
    {
        cout << "Input the number of pitstops you want to take: " << endl;
        cin >> numPitstops;

        if(numPitstops>tyreSetNumbers)
        {
            cout<<"You may only have a maximum of 4 pitstops."<<endl;
            cout<<endl;
        }

        if(numPitstops<1)
        {
            cout<<"You must have a minimum of 1 pitstops."<<endl;
            cout<<endl;
        }
    }
    while(numPitstops>tyreSetNumbers);

    numPitstops++;

    tyreSetNumbers = tyreSetNumbers - numPitstops;

     array = new string[numPitstops];
     this->numPitstops = numPitstops;


    array = new string[2];
    degradation = new string[1];
   // degradeLaps = 1;
   // numPitstops = 2;



    bool restart2 = true;

    do {


        cout << "Enter your tyre choices for the start of the race and for each pitstop (soft, medium, hard):  "
             << endl;


        bool tryAgain = false;

        for (int i = 0; i < numPitstops; i++) {
            do {
                tryAgain = false;

                cout << i + 1 << ") ";
                cin >> array[i];


                if (array[i] == "soft") {
                    soft--;
                } else if (array[i] == "medium") {
                    medium--;
                } else if (array[i] == "hard") {
                    hard--;
                }

                if (soft < 0) {
                    cout << "You don't have any soft tyres left, choose a different tyre type" << endl;
                    soft++;
                    tryAgain = true;
                } else if (medium < 0) {
                    cout << "You don't have any medium tyres left, choose a different tyre type" << endl;
                    medium++;
                    tryAgain = true;

                } else if (hard < 0) {
                    cout << "You don't have any hard tyres left, choose a different tyre type" << endl;
                    hard++;
                    tryAgain = true;

                }
            } while (tryAgain == true);

        }

        for (int x = 0; x < numPitstops; x++)
        {

            for (int j = x; j < numPitstops; j++)
            {

                if (array[x] != array[j])
                {
                    restart2 = false;
                }
            }
        }

        if(restart2 == true) {
            cout << "You must have at least two different tyre sets in this line up, please try again"<< endl;
            soft = softRestore;
            medium = mediumRestore;
            hard = hardRestore;

            cout << endl;
        }

    }
    while(restart2==true);




    cout<<"ORIGINAL DEGRADATION"<<endl;
    cout<<endl;

    //Degradation

     degradeLaps = 0;

    do {

        cout << "Enter how many extra tyre sets you want to add in the case of high tyre degradation:" << endl;
        cin >> degradeLaps;

        if(degradeLaps>tyreSetNumbers)
        {
            cout<<"You don't have enough tyre sets remaining for that number of extra stop."<<endl;
            cout<<"You have "<<tyreSetNumbers<<" tyres remaining"<<endl;
        }

    }while(degradeLaps>tyreSetNumbers);

    tyreSetNumbers = tyreSetNumbers - degradeLaps;

     degradation = new string[degradeLaps];

    cout<<"Enter which tyre sets you want to add in the case of high tyre degradation(soft,medium,hard):"<<endl;

    bool tryAgain = false;

    for(int i = 0; i<degradeLaps;i++)
    {

        do {
            tryAgain = false;

            cout << i + 1 << ") ";
            cin >> degradation[i];


            if (degradation[i] == "soft") {
                soft--;
            } else if (degradation[i] == "medium") {
                cout<<"medium decrees"<<endl;
                medium--;
            } else if (degradation[i] == "hard") {
                hard--;
            }

            if (soft < 0) {
                cout << "You don't have any soft tyres left, choose a different tyre type" << endl;
                soft++;
                tryAgain = true;
            } else if (medium < 0) {
                cout << "You don't have any medium tyres left, choose a different tyre type" << endl;
                medium++;
                tryAgain = true;

            } else if (hard < 0) {
                cout << "You don't have any hard tyres left, choose a different tyre type" << endl;
                hard++;
                tryAgain = true;

            }
        } while (tryAgain == true);
    }

//-----------------------------------------------------------------------------------------------------









//----WET_STRATEGY-------------------------------------------------------------------------------------





    cout<<endl;
    cout<<"WET STRATEGY:"<<endl;
    cout<<endl;


    //Wet
     numPitstopsWet=0;

    do
    {
        cout << "Input the number of pitstops you want to take after intermediate tyres can be taken off: " << endl;
        cin >> numPitstopsWet;

        if(numPitstopsWet>tyreSetNumbersWet)
        {
            cout<<"You may only have a maximum of 5 pitstops."<<endl;
            cout<<endl;
        }

        if(numPitstopsWet<1)
        {
            cout<<"You must have a minimum of 1 pitstops."<<endl;
            cout<<endl;
        }
    }
    while(numPitstopsWet>tyreSetNumbersWet);

    //numPitstopsWet++;

    tyreSetNumbersWet = tyreSetNumbersWet - numPitstopsWet;

     wetArray = new string[numPitstopsWet];


    bool restartWet = true;



    cout << "Enter your tyre choices for a wet race after intermediate tyres come off (soft, medium, hard):  "
         << endl;


    tryAgain = false;

    for (int i = 0; i < numPitstopsWet; i++) {
        do {
            tryAgain = false;

            cout << i + 1 << ") ";
            cin >> wetArray[i];


            if (wetArray[i] == "soft") {
                softWet--;
            } else if (wetArray[i] == "medium") {
                mediumWet--;
            } else if (wetArray[i] == "hard") {
                hardWet--;
            }

            if (softWet < 0) {
                cout << "You don't have any soft tyres left, choose a different tyre type" << endl;
                softWet++;
                tryAgain = true;
            } else if (mediumWet < 0) {
                cout << "You don't have any medium tyres left, choose a different tyre type" << endl;
                mediumWet++;
                tryAgain = true;

            } else if (hardWet < 0) {
                cout << "You don't have any hard tyres left, choose a different tyre type" << endl;
                hardWet++;
                tryAgain = true;

            }
        } while (tryAgain == true);

    }







    cout<<endl;


    //-------------------------------------------------------------------------------------


    //Degradation Wet

    cout<<"WET DEGRADATION"<<endl;

     degradeLapsWet = 0;

    do {

        cout << "Enter how many extra tyre sets you want to add in the case of high tyre degradation:" << endl;
        cin >> degradeLapsWet;

        if(degradeLapsWet>tyreSetNumbersWet)
        {
            cout<<"You don't have enough tyre sets remaining for that number of extra stop."<<endl;
            cout<<"You have "<<tyreSetNumbersWet<<" tyres remaining"<<endl;
        }

    }while(degradeLapsWet>tyreSetNumbersWet);

    tyreSetNumbers = tyreSetNumbersWet - degradeLapsWet;



    //Initialise wet degradation array
     degradationWet = new string[degradeLapsWet];



    cout<<"Enter which tyre sets you want to add in the case of high tyre degradation(soft,medium,hard):"<<endl;

    for(int i = 0; i<degradeLapsWet;i++)
    {

        do {
            tryAgain = false;

            cout << i + 1 << ") ";
            cin >> degradationWet[i];


            if (degradationWet[i] == "soft") {
                softWet--;
            } else if (degradationWet[i] == "medium") {
                mediumWet--;
            } else if (degradationWet[i] == "hard") {
                hardWet--;
            }

            if (softWet < 0) {
                cout << "You don't have any soft tyres left, choose a different tyre type" << endl;
                softWet++;
                tryAgain = true;
            } else if (mediumWet < 0) {
                cout << "You don't have any medium tyres left, choose a different tyre type" << endl;
                mediumWet++;
                tryAgain = true;

            } else if (hardWet < 0) {
                cout << "You don't have any hard tyres left, choose a different tyre type" << endl;
                hardWet++;
                tryAgain = true;

            }
        } while (tryAgain == true);
    }

    //-------------------------------------------------------------------------------------------






    //VeryWet-------------------------------------------------------------------------------------


    cout<<endl;
    cout<<"VERY WET STRATEGY:"<<endl;
    cout<<endl;


    //Wet
     numPitstopsVeryWet=0;

    do
    {
        cout << "Input the number of pitstops you want to take after full wet tyres can be taken off: " << endl;
        cin >> numPitstopsVeryWet;

        if(numPitstopsVeryWet>tyreSetNumbersVeryWet)
        {
            cout<<"You may only have a maximum of 4 pitstops."<<endl;
            cout<<endl;
        }

        if(numPitstopsVeryWet<1)
        {
            cout<<"You must have a minimum of 1 pitstops."<<endl;
            cout<<endl;
        }
    }
    while(numPitstopsVeryWet>tyreSetNumbersVeryWet);

    //numPitstopsWet++;

    tyreSetNumbersVeryWet = tyreSetNumbersVeryWet - numPitstopsVeryWet;

     veryWetArray = new string[numPitstopsVeryWet];


    bool restartVeryWet = true;



    cout << "Enter your tyre choices for a wet race after full wet tyres come off (soft, medium, hard):  "
         << endl;


    tryAgain = false;

    for (int i = 0; i < numPitstopsVeryWet; i++) {
        do {
            tryAgain = false;

            cout << i + 1 << ") ";
            cin >> veryWetArray[i];


            if (veryWetArray[i] == "soft") {
                softVeryWet--;
            } else if (veryWetArray[i] == "medium") {
                mediumVeryWet--;
            } else if (veryWetArray[i] == "hard") {
                hardVeryWet--;
            }

            if (softVeryWet < 0) {
                cout << "You don't have any soft tyres left, choose a different tyre type" << endl;
                softVeryWet++;
                tryAgain = true;
            } else if (mediumVeryWet < 0) {
                cout << "You don't have any medium tyres left, choose a different tyre type" << endl;
                mediumVeryWet++;
                tryAgain = true;

            } else if (hardVeryWet < 0) {
                cout << "You don't have any hard tyres left, choose a different tyre type" << endl;
                hardVeryWet++;
                tryAgain = true;

            }
        } while (tryAgain == true);

    }



    //----------------------------------------------------------------------------------------



    //Very Wet Degradation

    cout<<"VERY WET DEGRADATION"<<endl;
    cout<<endl;

    degradeLapsVeryWet = 0;

    do {

        cout << "Enter how many extra tyre sets you want to add in the case of high tyre degradation:" << endl;
        cin >> degradeLapsVeryWet;

        if(degradeLapsVeryWet>tyreSetNumbersVeryWet)
        {
            cout<<"You don't have enough tyre sets remaining for that number of extra stop."<<endl;
            cout<<"You have "<<tyreSetNumbersVeryWet<<" tyres remaining"<<endl;
        }

    }while(degradeLapsVeryWet>tyreSetNumbersVeryWet);

    tyreSetNumbersVeryWet = tyreSetNumbersVeryWet - degradeLapsVeryWet;

     degradationVeryWet = new string[degradeLapsVeryWet];

    cout<<"Enter which tyre sets you want to add in the case of high tyre degradation(soft,medium,hard):"<<endl;

    for(int i = 0; i<degradeLapsVeryWet;i++)
    {


        do {
            tryAgain = false;

            cout << i + 1 << ") ";
            cin >> degradationVeryWet[i];


            if (degradationVeryWet[i] == "soft") {
                soft--;
            } else if (degradationVeryWet[i] == "medium") {
                medium--;
            } else if (degradationVeryWet[i] == "hard") {
                hard--;
            }

            if (softVeryWet < 0) {
                cout << "You don't have any soft tyres left, choose a different tyre type" << endl;
                softVeryWet++;
                tryAgain = true;
            } else if (mediumVeryWet < 0) {
                cout << "You don't have any medium tyres left, choose a different tyre type" << endl;
                mediumVeryWet++;
                tryAgain = true;

            } else if (hardVeryWet < 0) {
                cout << "You don't have any hard tyres left, choose a different tyre type" << endl;
                hardVeryWet++;
                tryAgain = true;

            }
        } while (tryAgain == true);
    }



    //Repairs

    string* repairs = new string[1];

    cout<<endl;
    cout<<"Enter whether the repair stop must have a tyre change or not (yes,no): "<<endl;
    cin>>repairs[0];



   // this->numPitstops = numPitstops;


    InputStorage* input = new InputStorage(numPitstops,array,degradeLaps,degradation,numPitstopsWet,wetArray,degradeLapsWet,degradationWet,numPitstopsVeryWet,veryWetArray,degradeLapsVeryWet,degradationVeryWet);


    store[storageCounter] = input;
    storageCounter++;

}

void FormulaOneTeam::runChampionships()
{
    Time& t = Time::getInstance();

    for(int i = 0; i<numOfSeasons;i++)
    {
        t.setCurrentDate(1,1);
        //New year begins
        //buildCarAndTest();

        if(i==0)
        {
            buildCarAndTest();
        }
        else    //Not first Year
        {
            cout<<"The current date: "<<t.getCurrentDate()->getDay()<<"-"<<t.getCurrentDate()->getMonth()<<endl;
            cout<<endl;
            cout<<"Development of next season cars has begun."<<endl;
            cout<<endl;

            //Races of the year
            for(int i = 0; i<52; i++)    //Use the time class for this ?
            {

               handleLogistics();  //Handle the race logistics (Three months prior)

               OrderTyres(); //Hand the tyre orders (One month prior)


                if(RaceThisWeek() == true)
                {
                    runRace();


                    logistics->TransportBackToFactory();

                    cout<<endl;

                    Results* showResults1 = new ResultConstructor(carrArr[0],carrArr[1]);
                    showResults1->displayResults();


                    cout<<endl;

                    Results* showResults2 = new ResultDriver(carrArr[0],carrArr[1]);
                    showResults2->displayResults();

                    totalScore = totalScore + showResults1->returnTotalScore();
                    racer1Score = racer1Score + showResults2->getD1Score();
                    racer2Score = racer2Score + showResults2->getD2Score();

                    cout<<endl;

                }


                string progress;

                do {
                    cout<<endl<<"Would you like to advance to the next week: (y)"<<endl;
                    cin>>progress;
                }
                while(progress!="y"&&progress!="Y");




                t.ProgressTime();


            }

            if(i!=numOfSeasons-1)  //Not final season
            {
                //Engineering for next years car.
                buildCarAndTest();
            }

        }

        if(i!=0) {
            cout<<"Beginning Score:"<<endl;
        }
            cout << endl;
            cout << "------------------------------" << endl;
            cout << "Driver's Championship:" << endl;
            cout << "Hamilton: " << racer1Score << endl;
            cout << "Vettel: " << racer2Score << endl;
            cout << "------------------------------" << endl;
            cout << "Constructor's Championship:" << endl;
            cout << "Macrosoft Doors: " << totalScore << endl;

        cout<<endl;

    }
}


bool FormulaOneTeam::RaceThisWeek()
{
    Time& t = Time::getInstance();  //get singleton instance
    vector<Date*> vecDates(t.getRaceDates());
    vector<Location*> vecLocations(t.getRaceLocations()); //create new vectors = to time vectors

    int cDay6 = t.getCurrentDate()->getDay() + 6; // this should be the day of the race specified in the time object raceDates vector if it is this week
    int cMonthOverflow =  t.getCurrentDate()->getMonth();


    if (cDay6 > 28)
    {
        //cout << "month overflow" << endl;
        switch (cMonthOverflow) //this should make the cDay and cDay equivalent to rDay rMonday if the race takes place within a week
        {
            case 1:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 2:
                if (cDay6 > 29)
                {
                    cDay6 = cDay6 - 28;
                    cMonthOverflow++;
                };
                break;
            case 3:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 4:
                if (cDay6 > 30)
                {
                    cDay6 = cDay6 - 30;
                    cMonthOverflow++;
                };
                break;
            case 5:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 6:
                if (cDay6 > 30)
                {
                    cDay6 = cDay6 - 30;
                    cMonthOverflow++;
                };
                break;
            case 7:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 8:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 9:
                if (cDay6 > 30)
                {
                    cDay6 = cDay6 - 30;
                    cMonthOverflow++;
                };
                break;
            case 10:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow++;
                };
                break;
            case 11:
                if (cDay6 > 30)
                {
                    cDay6 = cDay6 - 30;
                    cMonthOverflow++;
                };
                break;
            case 12:
                if (cDay6 > 31)
                {
                    cDay6 = cDay6 - 31;
                    cMonthOverflow = 1;
                };
                break;
            default :
                cout << "month is too large" << endl;
        }
    }

    for(int i = 0; i < 21; i++) //loop for every race in vector
    {
        int rDay = vecDates[i]->getDay(); //getting raceday
        int rMonth = vecDates[i]->getMonth();//getting race month

        //compare with race dates
        if(cDay6 == rDay && cMonthOverflow == rMonth) //this should be true is there is a race within the week
        {
            return true;
        }

        if ((cMonthOverflow + 1) < rMonth )//break out the loop if we are checking more than 3 months ahead of current date
        {
            break;
        }
    }
    return false;
}

void FormulaOneTeam::OrderTyres()
{
    Time& t = Time::getInstance();  //get singleton instance
    vector<Date*> vecDates(t.getRaceDates());
    vector<Location*> vecLocations(t.getRaceLocations()); //create new vectors = to time vectors

    int cDay28 =  t.getCurrentDate()->getDay() + 28; // checking for 1 months ahead
    int cMonth28 =  t.getCurrentDate()->getMonth();

    cDay28 = cDay28 + 6;
    if (cDay28 > 28)
    {
        switch (cMonth28) //this should make the cDay and cDay equivalent to rDay rMonday if the race takes place within a week
        {
            case 1:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 2:
                if (cDay28 > 29) {
                    cDay28 = cDay28 - 28;
                    cMonth28++;
                };
                break;
            case 3:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 4:
                if (cDay28 > 30) {
                    cDay28 = cDay28 - 30;
                    cMonth28++;
                };
                break;
            case 5:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 6:
                if (cDay28 > 30) {
                    cDay28 = cDay28 - 30;
                    cMonth28++;
                };
                break;
            case 7:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 8:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 9:
                if (cDay28 > 30) {
                    cDay28 = cDay28 - 30;
                    cMonth28++;
                };
                break;
            case 10:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28++;
                };
                break;
            case 11:
                if (cDay28 > 30) {
                    cDay28 = cDay28 - 30;
                    cMonth28++;
                };
                break;
            case 12:
                if (cDay28 > 31) {
                    cDay28 = cDay28 - 31;
                    cMonth28 = 1;
                };
                break;
            default :
                cout << "month is too large" << endl;
        }
    }

    for(int i = 0; i < 21; i++) //loop for every race in vector
    {
        int rDay = vecDates[i]->getDay(); //getting raceday
        int rMonth = vecDates[i]->getMonth();//getting race month

        //compare with race dates
        if(cDay28 == rDay && cMonth28 == rMonth) //this should be true is there is a race within the week
        {
            cout<<"Enter tyre orders for race on "<<rDay<<"-"<<rMonth<<" at "<<vecLocations[i]->getCountry()<<", "<<vecLocations[i]->getRaceway()<<endl<<endl;

            raceStrategyInput();
        }

        if ((cMonth28 + 2) < rMonth )//break out the loop if we are checking more than 3 months ahead of current date
        {
            break;
        }
    }
}






