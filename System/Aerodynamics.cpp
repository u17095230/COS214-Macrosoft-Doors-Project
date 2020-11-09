#include "Aerodynamics.h"
#include <iostream>
using namespace std;

Aerodynamics::Aerodynamics(){
    setTestPassed(false);
    setPerformance(0);
    setVersionNumber(0);
}

void Aerodynamics::makeAdjustment(){
    cout << "Making Adjustments to Aerodynamics version " << getVersionNumber() << endl;
}

void Aerodynamics::updateVersion(int v){
    cout << "Updating Aerodynamics version " << getVersionNumber()<< " to version " << v << endl;
    setVersionNumber(v);
}

void Aerodynamics::add(Component* c){
    return;
}

void Aerodynamics::remove(Component* c){
    return;
}

Component* Aerodynamics::getComponent(int i){
    return NULL;
}
