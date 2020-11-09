#ifndef CARBUILDER_H
#define CARBUILDER_H

#include "Engine.h"
#include "Electronics.h"
#include "Chassis.h"
#include "Aerodynamics.h"
#include "Suspension.h"
#include "CockpitErgonomics.h"
#include "WarningSystem.h"

class CarBuilder {
public:
    virtual ~CarBuilder();
    virtual void buildEngine(Engine* e) = 0;
    virtual void buildElectronics(Electronics* e) = 0;
    virtual void buildChassis(Chassis* c) = 0;
    virtual void buildAerodynamics(Aerodynamics* a) = 0;
    virtual void buildSuspension(Suspension* s) = 0;
    virtual void buildCockpitErgonomics(CockpitErgonomics* c) = 0;
    virtual void buildWarningSystem(WarningSystem* w) = 0;
    virtual void nullifyCar()=0;
    virtual void buildNewCar()=0;


};

#endif
