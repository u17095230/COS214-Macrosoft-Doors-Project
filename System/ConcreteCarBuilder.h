#ifndef CONCRETECARBUILDER_H
#define CONCRETECARBUILDER_H

#include "CarBuild.h"
#include "CarBuilder.h"
#include "Engine.h"
#include "Electronics.h"
#include "Chassis.h"
#include "Aerodynamics.h"

class ConcreteCarBuilder: public CarBuilder {
private:
    CarBuild* car;
public:
    ConcreteCarBuilder();
    void buildEngine(Engine* e);
    void buildElectronics(Electronics* e);
    void buildChassis(Chassis* c);
    void buildAerodynamics(Aerodynamics* a);
    void buildSuspension(Suspension* s);
    void buildCockpitErgonomics(CockpitErgonomics* c);
    void buildWarningSystem(WarningSystem* w);
    void nullifyCar();
    void buildNewCar();
    CarBuild* getCar();
    ~ConcreteCarBuilder();
};

#endif
