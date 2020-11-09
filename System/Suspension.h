#ifndef SUSPENSION_H
#define SUSPENSION_H

#include "Component.h"

class Suspension: public Component {
public:
    Suspension();
    void makeAdjustment();
    void add(Component* c);
    void remove(Component* c);
    Component* getComponent(int i);
    void updateVersion(int v);

};

#endif
