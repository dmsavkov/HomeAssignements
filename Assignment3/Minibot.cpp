#include "minibot.h"
#include <iostream>

Minibot::Minibot(std::string name, int strength, double speed,
                 std::string vehicleType, Weapon mainWeapon, Mission* curMission,
                 double agility)
    : Transformer(name, strength, speed, vehicleType, mainWeapon, curMission),
      agility(agility) {}

Minibot::Minibot(std::string name, int strength, double speed, double agility)
    : Transformer(name, strength, speed), 
      agility(agility) {}

Minibot::~Minibot() {}

double Minibot::getAgility() {
    return agility;
}

void Minibot::setAgility(double a) {
    agility = a;
}

void Minibot::performRecon() {
    std::cout << getName() << " is performing a reconnaissance mission with agility " 
              << agility << "!" << std::endl;
}

void Minibot::scout() {
    std::cout << getName() << " is scouting the area!" << std::endl;
}