#ifndef CHASSIS_H
#define CHASSIS_H

#include "Component.h"

class Chassis: public Component {
public:
    Chassis();
    void makeAdjustment();
    void add(Component* c);
    void remove(Component* c);
    Component* getComponent(int i);
    void updateVersion(int v);

};

#endif
