#include "CockpitErgonomics.h"
#include <iostream>
using namespace std;

CockpitErgonomics::CockpitErgonomics(){
    setTestPassed(false);
    setPerformance(0);
    setVersionNumber(0);
}

void CockpitErgonomics::makeAdjustment(){
    cout << "Making Adjustments to CockpitErgnomics version " << getVersionNumber() << endl;
}

void CockpitErgonomics::updateVersion(int v){
    cout << "Updating CockpitErgnomics version " << getVersionNumber()<< " to version " << v << endl;
    setVersionNumber(v);
}

void CockpitErgonomics::add(Component* c){
    return;
}

void CockpitErgonomics::remove(Component* c){
    return;
}

Component* CockpitErgonomics::getComponent(int i){
    return NULL;
}
