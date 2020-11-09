#ifndef AERODYNAMICS_H
#define AERODYNAMICS_H

#include "Component.h"

class Aerodynamics: public Component {
public:
    Aerodynamics();
    void makeAdjustment();
    void add(Component* c);
    void remove(Component* c);
    Component* getComponent(int i);
    void updateVersion(int v);
};

#endif
