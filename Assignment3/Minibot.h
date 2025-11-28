#ifndef MINIBOT_H
#define MINIBOT_H

#include <string>
#include "transformer.h"

class Minibot : public Transformer {
private:
    double agility;

public:
    Minibot(std::string name, int strength, double speed,
            std::string vehicleType, Weapon mainWeapon, Mission* curMission,
            double agility);
    ~Minibot();

    double getAgility();
    void setAgility(double a);

    void performRecon();
    void scout();
};

#endif