#ifndef COMPONENT_H
#define COMPONENT_H

class Component {

private:
    int performance;
    bool testPassed;
    int versionNumber;
public:
    Component();
    virtual ~Component();
    virtual void add(Component* c) = 0;
    virtual void remove(Component* c) = 0;
    virtual Component* getComponent(int i) = 0;
    virtual void makeAdjustment() = 0;
    void setPerformance(int p);
    int getPerformance();
    void setTestPassed(bool t);
    bool getTestPassed();
    int getVersionNumber();
    void setVersionNumber(int v);
 //   virtual void updateVersion(int v) = 0;
};

#endif
