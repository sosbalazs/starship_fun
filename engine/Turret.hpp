#ifndef TURRET_HPP
#define TURRET_HPP

#include "types.hpp"

class Turret
{
public:
    Turret();
    ~Turret();

private:
    TurretSize Size;
    TurretClass Class;
    int Ap;
    int Shots;
    int ReloadTime;
    int Accuracy;
    int BulletSpeed;
    int CrewResource;
    int EnergieResource;
};

#endif // TURRET_HPP
