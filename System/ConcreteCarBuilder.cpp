#include "ConcreteCarBuilder.h"
#include <iostream>
using namespace std;

ConcreteCarBuilder::ConcreteCarBuilder(){
    car = new CarBuild();
}

void ConcreteCarBuilder::buildEngine(Engine* e){
    cout << "Car Builder building Engine." << endl;
    car->add(e);
}

void ConcreteCarBuilder::buildElectronics(Electronics* e){
    cout << "Car Builder building Electronics." << endl;
    car->add(e);
}

void ConcreteCarBuilder::buildChassis(Chassis* c){
    cout << "Car Builder building Chassis." << endl;
    car->add(c);
}

void ConcreteCarBuilder::buildAerodynamics(Aerodynamics* a){
    cout << "Car Builder building Aerodynamics." << endl;
    car->add(a);
}

void ConcreteCarBuilder::buildSuspension(Suspension* s){
    cout << "Car Builder building Suspension." << endl;
    car->add(s);
}

void ConcreteCarBuilder::buildCockpitErgonomics(CockpitErgonomics* c){
    cout << "Car Builder building CockpitErgonomics." << endl;
    car->add(c);
}

void ConcreteCarBuilder::buildWarningSystem(WarningSystem* w){
    cout << "Car Builder building WarningSystem." << endl;
    car->add(w);
}


CarBuild* ConcreteCarBuilder::getCar(){

    return car;
}

void ConcreteCarBuilder::nullifyCar(){
     car = nullptr;
     car = new CarBuild();
}

ConcreteCarBuilder::~ConcreteCarBuilder(){
    cout << "Car Builder destroying car." << endl;
    delete car;
}

void ConcreteCarBuilder::buildNewCar()
{
    if(car!=NULL)
    {
        delete car;
    }
    car = new CarBuild();
}
