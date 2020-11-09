#ifndef ENGINEERINGTEAM_H
#define ENGINEERINGTEAM_H

#include "CarBuilder.h"

class EngineeringTeam {
private:
    CarBuilder* carBuilder;
    int budget;
public:
    void constructCar();
    EngineeringTeam(CarBuilder* builder);
    int getBudget();
    void setBudget(int b);
    ~EngineeringTeam();

};

#endif
