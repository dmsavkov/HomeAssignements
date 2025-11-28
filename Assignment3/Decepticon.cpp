#include "decepticon.h"
#include <iostream>

Decepticon::Decepticon(std::string name, int strength, double speed,
                       std::string vehicleType, Weapon mainWeapon, Mission* curMission,
                       int ruthlessness)
    : Transformer(name, strength, speed, vehicleType, mainWeapon, curMission),
      ruthlessness(ruthlessness) {}

Decepticon::Decepticon(std::string name, int strength, double speed, int ruthlessness)
    : Transformer(name, strength, speed), 
      ruthlessness(ruthlessness) {}

Decepticon::~Decepticon() {}

int Decepticon::getRuthlessness() {
    return ruthlessness;
}

void Decepticon::setRuthlessness(int r) {
    ruthlessness = r;
}

void Decepticon::updateRuthlessness(int amount) {
    ruthlessness += amount;
}

void Decepticon::intimidate() {
    std::cout << getName() << " is intimidating the enemy with ruthlessness " 
              << ruthlessness << "!" << std::endl;
}

void Decepticon::attack() {
    std::cout << "Decepticon " + getName() + " attacking!" << std::endl;
}

void Decepticon::specialAbility() {
    std::cout << "Decepticon " + getName() + " uses special ability: Ruthless Strike!" << std::endl;
}