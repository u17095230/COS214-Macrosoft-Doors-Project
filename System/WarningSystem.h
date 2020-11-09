#ifndef WARNINGSYSTEM_H
#define WARNINGSYSTEM_H

#include "Component.h"

class WarningSystem: public Component {
public:
    WarningSystem();
    void makeAdjustment();
    void add(Component* c);
    void remove(Component* c);
    Component* getComponent(int i);
    void updateVersion(int v);

};

#endif
