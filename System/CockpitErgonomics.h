#ifndef COCKPITERGNOMICS_H
#define COCKPITERGNOMICS_H

#include "Component.h"

class CockpitErgonomics: public Component {
public:
    CockpitErgonomics();
    void makeAdjustment();
    void add(Component* c);
    void remove(Component* c);
    Component* getComponent(int i);
    void updateVersion(int v);

};

#endif
