#ifndef CARBUILD_H
#define CARBUILD_H

#include <list>
#include "Component.h"
#include "Traverser.h"
#include "ComponentTraverser.h"

using namespace std;

class CarBuild: public Component {
private:
    list<Component*> components;
    ComponentTraverser* iterator;
    int driverSatisfaction;
    double chanceMultiplier;
public:
    CarBuild();
    ~CarBuild();
    void beginTesting();
    void add(Component* c);
    void remove(Component* c);
    Component* getComponent(int i);
    int runSimulations();
    Traverser* getIterator();
    void makeAdjustment();
    //void updateVersion(int v);

};

#endif
