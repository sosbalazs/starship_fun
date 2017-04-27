#ifndef TURRET_H
#define TURRET_H

class Turret
{
public:
    Turret();
    ~Turret();

private:
    TurretSize::Value Size;
    TurretClass::Value Class;
    int Ap;
    int Shots;
    int ReloadTime;
    int Accuracy;
    int BulletSpeed;
    int CrewResource;
    int EnergieResource;
};

#endif // TURRET_H
