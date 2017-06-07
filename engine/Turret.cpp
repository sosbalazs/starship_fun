#include "Turret.hpp"
#include "types.hpp"

Turret::Turret()
{
    Size = TurretSize::UNDEFINED;
    Class = TurretClass::UNDEFINED;
    Ap = 1;
    Shots = 1;
    ReloadTime = 1;
    Accuracy = 1;
    BulletSpeed = 1;
    CrewResource = 1;
    EnergieResource = 1;
}

Turret::~Turret(){}
