#include "Electronics.h"
#include <cmath>
#include <iostream>
using namespace std;

Electronics::Electronics(){
    setTestPassed(false);
    setPerformance(0);
    setVersionNumber(0);
}

void Electronics::makeAdjustment(){
    cout << "Making Adjustments to Electronics version " << getVersionNumber() << endl;
}

void Electronics::updateVersion(int v){
    cout << "Updating Electronics version " << getVersionNumber()<< " to version " << v << endl;
    setVersionNumber(v);
}

void Electronics::add(Component* c){
    return;
}

void Electronics::remove(Component* c){
    return;
}

Component* Electronics::getComponent(int i){
    return NULL;
}