#include "CarBuild.h"
#include <iostream>
using namespace std;

CarBuild::CarBuild(){
    cout << "Creating car build." << endl;
    driverSatisfaction = 0;
    chanceMultiplier = 1;
    iterator = nullptr;
    //iterator = new ComponentTraverser(components); Alex did this
}

CarBuild::~CarBuild(){
  //  cout << "Destroying car build." << endl;
    components.clear();
}

void CarBuild::beginTesting(){
    cout << "Beginning test" << endl;
}

void CarBuild::add(Component* c){

    components.push_back(c);
    iterator = new ComponentTraverser(components);  //Alex place this here;

    cout << "Component added." << endl;
}

void CarBuild::remove(Component* c){
    components.remove(c);
    delete c;
    cout << "Component removed." << endl;
}

Component* CarBuild::getComponent(int i){
    return iterator->get(i);
}

int CarBuild::runSimulations(){
    cout << "Running Simulations." << endl;
    driverSatisfaction = rand()%10*chanceMultiplier;

    if (driverSatisfaction > 5){
        cout << "Driver satisfied." << endl;
    } else {
        cout << "Driver not satisfied." << endl;
    }
    chanceMultiplier = chanceMultiplier+1.3;

    return driverSatisfaction;
}

Traverser* CarBuild::getIterator(){
    return iterator;
}

void CarBuild::makeAdjustment(){
    return;
}
