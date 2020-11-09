#ifndef COMPONENTITERATOR_H
#define COMPONENTITERATOR_H

#include "Traverser.h"
#include "Component.h"
#include <stack>
#include <list>

using namespace std;
class ComponentTraverser: public Traverser {
private:
    stack<Component*> targets;
    stack<int> indices;
public:
    ComponentTraverser(list<Component*> c);
    bool hasNext();
    void getNext();
    Component* get();
    Component* get(int i);
    void step();
};

#endif
