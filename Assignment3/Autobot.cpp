#include "autobot.h"
#include <iostream>

Autobot::Autobot(std::string name, int strength, double speed,
                 std::string vehicleType, Weapon mainWeapon, Mission* curMission,
                 int loyalty)
    : Transformer(name, strength, speed, vehicleType, mainWeapon, curMission),
      loyalty(loyalty) {}

Autobot::Autobot(std::string name, int strength, double speed, int loyalty)
    : Transformer(name, strength, speed), 
      loyalty(loyalty) {}

Autobot::~Autobot() {}

int Autobot::getLoyalty() const {
    return loyalty;
}

void Autobot::setLoyalty(int l) {
    loyalty = l;
}

void Autobot::updateLoyalty(int amount) {
    loyalty += amount;
}

void Autobot::shieldAlly() {
    std::cout << getName() << " is shielding an ally!" << std::endl;
}

void Autobot::attack() {
    std::cout << "Autobot " + getName() + " attacking!" << std::endl;
}

void Autobot::specialAbility() {
    std::cout << "Autobot " + getName() + " uses special ability: Courage Boost!" << std::endl;
}