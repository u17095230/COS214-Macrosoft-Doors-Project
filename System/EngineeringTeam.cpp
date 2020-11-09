#include "EngineeringTeam.h"
#include <iostream>
using namespace std;

void EngineeringTeam::constructCar(){
    cout << "Engineering Team has started constructing the car." << endl;
    carBuilder->buildNewCar();
    // This is very off, cars can cost between $175mil and $400mil, this can be changed if needed. :D
    // Base Budget = R 1 000 000
    if (budget >= 175000000){
        carBuilder->buildAerodynamics(new Aerodynamics());
        carBuilder->buildChassis(new Chassis());
        carBuilder->buildElectronics(new Electronics());
        carBuilder->buildEngine(new Engine());
    }
    // Next tier = R 1 250 000
    if (budget >= 250000000){
        carBuilder->buildWarningSystem(new WarningSystem());
    }
    // Next tier = R 1 500 000
    if (budget >= 300000000){
        carBuilder->buildSuspension(new Suspension());
    }
    // Next tier = R 1 750 000
    if (budget >= 370000000){
        carBuilder->buildCockpitErgonomics(new CockpitErgonomics());
    }
}

EngineeringTeam::EngineeringTeam(CarBuilder* builder){
    carBuilder = builder;
    budget = 0;
}

EngineeringTeam::~EngineeringTeam(){
    delete carBuilder;
}

int EngineeringTeam::getBudget(){
    return budget;
}

void EngineeringTeam::setBudget(int b){
    budget = b;
}