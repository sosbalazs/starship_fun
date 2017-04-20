#ifndef SHIP_H
#define SHIP_H

#include <vector>

#include "types.h"
#include "Turret.h"
#include "Utility.h"

class Ship
{
public:
    Ship();
    ~Ship();

private:
    int MaxBigTurrets;
    int MaxSmallTurrets;
    int MaxUtilityBay;
    ShipClass::Value Class;
    vector<Turret> BigTurrets;
    vector<Turret> SmallTurrets;
    vector<Utility> UtilityBays;
};

#endif // SHIP_H
