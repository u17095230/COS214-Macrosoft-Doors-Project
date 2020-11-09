#include "Engine.h"
#include <cmath>
#include <iostream>
using namespace std;

Engine::Engine(){
    setTestPassed(false);
    setPerformance(0);
    setVersionNumber(0);
}

void Engine::makeAdjustment(){
    cout << "Making Adjustments to Engine version " << getVersionNumber() << endl;
}

void Engine::updateVersion(int v){
    cout << "Updating Engine version " << getVersionNumber()<< " to version " << v << endl;
    setVersionNumber(v);
}

void Engine::add(Component* c){
    return;
}

void Engine::remove(Component* c){
    return;
}

Component* Engine::getComponent(int i){
    return NULL;
}