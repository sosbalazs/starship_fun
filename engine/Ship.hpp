#ifndef SHIP_HPP
#define SHIP_HPP

#include <vector>
#include "types.hpp"

class Turret;
class Utility;

class Ship
{
public:
    Ship();
    ~Ship();

private:
    int MaxBigTurrets;
    int MaxSmallTurrets;
    int MaxUtilityBay;
    ShipClass Class;
    std::vector<Turret> BigTurrets;
    std::vector<Turret> SmallTurrets;
    std::vector<Utility> UtilityBays;
};

#endif // SHIP_HPP
