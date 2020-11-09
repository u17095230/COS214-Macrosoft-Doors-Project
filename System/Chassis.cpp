#include "Chassis.h"
#include <cmath>
#include <iostream>
using namespace std;

Chassis::Chassis(){
    setTestPassed(false);
    setPerformance(0);
    setVersionNumber(0);
}

void Chassis::makeAdjustment(){
    cout << "Making Adjustments to Chassis version " << getVersionNumber() << endl;
}

void Chassis::updateVersion(int v){
    cout << "Updating Chassis version " << getVersionNumber()<< " to version " << v << endl;
    setVersionNumber(v);
}

void Chassis::add(Component* c){
    return;
}

void Chassis::remove(Component* c){
    return;
}

Component* Chassis::getComponent(int i){
    return NULL;
}
