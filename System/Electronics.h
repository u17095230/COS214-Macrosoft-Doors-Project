#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include "Component.h"

class Electronics: public Component {
public:
    Electronics();
    void makeAdjustment();
    void add(Component* c);
    void remove(Component* c);
    Component* getComponent(int i);
    void updateVersion(int v);

};

#endif
