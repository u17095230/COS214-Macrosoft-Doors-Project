#ifndef ITERATOR_H
#define ITERATOR_H

#include "Component.h"

class Traverser {
public:
    virtual bool hasNext() = 0;
    virtual void getNext() = 0;
    virtual Component* get() = 0;

};

#endif 