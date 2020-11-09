#include "WarningSystem.h"
#include <iostream>
using namespace std;

WarningSystem::WarningSystem(){
    setTestPassed(false);
    setPerformance(0);
    setVersionNumber(0);
}

void WarningSystem::makeAdjustment(){
    cout << "Making Adjustments to WarningSystem version " << getVersionNumber() << endl;
}

void WarningSystem::updateVersion(int v){
    cout << "Updating WarningSystem version " << getVersionNumber()<< " to version " << v << endl;
    setVersionNumber(v);
}

void WarningSystem::add(Component* c){
    return;
}

void WarningSystem::remove(Component* c){
    return;
}

Component* WarningSystem::getComponent(int i){
    return NULL;
}