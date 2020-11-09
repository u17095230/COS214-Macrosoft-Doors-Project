#ifndef ENGINE_H
#define ENGINE_H

#include "Component.h"

class Engine: public Component {
public:
    Engine();
    void makeAdjustment();
    void add(Component* c);
    void remove(Component* c);
    Component* getComponent(int i);
    void updateVersion(int v);

};

#endif
