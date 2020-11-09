#include "ComponentTraverser.h"
#include <iostream>
#include <list>
#include <stack>
using namespace std;

ComponentTraverser::ComponentTraverser(list<Component*> c){

    int count = 0;
    while (c.size() > 0){
        Component* comp = c.front();
        c.pop_front();
        targets.push(comp);
        indices.push(count);
        ++count;
      //  cout<<"PING"<<endl;
    }
}

bool ComponentTraverser::hasNext(){
    // gets the top index, if its smaller than the size of the stack-1, then there are still more components
    return indices.top() < indices.size() - 1;
}

void ComponentTraverser::getNext(){
    // Get top component and associated index
    int topIndex = indices.top();
    Component* topComponent = targets.top();
    // Remove them from the stack
    indices.pop();
    targets.pop();
    // Create a temporary stack that is the inverse of the current stack (top items at the bottom)
    stack<Component*> tempStack;
    stack<int> tempIndicesStack;
    while (targets.size() > 0){
        tempStack.push(targets.top());
        tempIndicesStack.push(indices.top());
        targets.pop();
        indices.pop();
    }
    // Add the old top component & index to the bottom of the stack
    indices.push(topIndex);
    targets.push(topComponent);
    // Re-add the rest of the components back in the normal order; The second item is now on top
    while (tempStack.size() > 0){
        targets.push(tempStack.top());
        indices.push(tempIndicesStack.top());
        tempStack.pop();
        tempIndicesStack.pop();
    }
}

Component* ComponentTraverser::get(){
    return targets.top();
}

Component* ComponentTraverser::get(int i){
    stack<Component*> tempStack;
    stack<int> tempIndicesStack;
    int index = -1;
    Component* comp = NULL;
   // cout<<"KARACOR: "<<targets.size()<<endl;
    while (targets.size() > 0 && (index != i || index < targets.size())){
       // cout<<"PURPLE"<<endl;
        index = indices.top();
        comp = targets.top();
        indices.pop();
        targets.pop();
        tempStack.push(comp);
        tempIndicesStack.push(index);
    }

    while (tempStack.size() > 0){
        targets.push(tempStack.top());
        indices.push(tempIndicesStack.top());
        tempStack.pop();
        tempIndicesStack.pop();
    }

    if (index == i){
        return comp;
    }

    return nullptr;     //Alex changed this
}

void ComponentTraverser::step(){
    getNext();
}
