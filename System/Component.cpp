#include "Component.h"
#include <iostream>
#include <cmath>
using namespace std;

Component::Component(){

}

Component::~Component()
{

}

void Component::setPerformance(int p){
    performance = p;
}

int Component::getPerformance(){
    return performance;
}

void Component::setTestPassed(bool t){
    testPassed = t;
}

bool Component::getTestPassed(){
    return testPassed;
}

int Component::getVersionNumber(){
    return versionNumber;
}

void Component::setVersionNumber(int v){
    versionNumber = v;
}