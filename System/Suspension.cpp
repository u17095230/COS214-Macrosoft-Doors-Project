#include "Suspension.h"
#include <iostream>
using namespace std;

Suspension::Suspension(){
    setTestPassed(false);
    setPerformance(0);
    setVersionNumber(0);
}

void Suspension::makeAdjustment(){
    cout << "Making Adjustments to Suspension version " << getVersionNumber() << endl;
}

void Suspension::updateVersion(int v){
    cout << "Updating Suspension version " << getVersionNumber()<< " to version " << v << endl;
    setVersionNumber(v);
}

void Suspension::add(Component* c){
    return;
}

void Suspension::remove(Component* c){
    return;
}

Component* Suspension::getComponent(int i){
    return NULL;
}
