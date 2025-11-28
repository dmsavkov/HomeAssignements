#include "transformer.h"
#include <iostream>

Transformer::Transformer(const std::string& name, int strength, double speed,
                         const std::string& vehicleType, const Weapon& weapon, Mission* mission)
    : name(name),
      strength(strength),
      speed(speed),
      vehicleType(vehicleType),
      transformed(false),
      mainWeapon(weapon),
      curMission(mission) {}

// Overloading constructor - the same: simply rewrite.
// Delegating initialization for the default constructor. 
Transformer::Transformer(const std::string& name, int strength, double speed) : 
    Transformer(name, strength, speed, "Default Vehicle", Weapon("Default Blaster", 10), nullptr) {}
        
// Example with a different type for speed.
Transformer::Transformer(const std::string& name, int strength, int speed,
        const std::string& vehicleType, const Weapon& weapon, Mission* mission) : 
    Transformer(name, strength, static_cast<double>(speed), vehicleType, weapon, mission) {}

Transformer::~Transformer() {}

void Transformer::transform() {
    transformed = !transformed;
}

bool Transformer::isTransformed() const {
    return transformed;
}

void Transformer::battleCry() {
    if (transformed) {
        std::cout << name << " shouts: For Cybertron!" << std::endl;
    } else {
        std::cout << name << " shouts: Roll out!" << std::endl;
    }
}

void Transformer::displayStatus() {
    std::string mode = transformed ? "Robot Mode" : "Vehicle Mode";
    std::cout << "Transformer: " << name << ". Mode: " << mode << std::endl;
    if (curMission) {
        std::cout << "Current Mission: " << curMission->getDescription() 
                  << " (Difficulty: " << curMission->getDifficulty() << ")\n";
    } else {
        std::cout << "No current mission assigned.\n";
    }
}

std::string Transformer::getName() const {
    return name;
}

int Transformer::getStrength() const {
    return strength;
}

double Transformer::getSpeed() const {
    return speed;
}

std::string Transformer::getVehicleType() const {
    return vehicleType;
}

Weapon Transformer::getMainWeapon() const {
    return mainWeapon;
}

Mission* Transformer::getCurrentMission() const {
    return curMission;
}

void Transformer::setName(const std::string& n) {
    name = n;
}

void Transformer::setStrength(int s) {
    strength = s;
}

void Transformer::setSpeed(double sp) {
    speed = sp;
}

void Transformer::setVehicleType(const std::string& vt) {
    vehicleType = vt;
}

void Transformer::setMainWeapon(const Weapon& w) {
    mainWeapon = w;
}

void Transformer::setCurrentMission(Mission* m) {
    curMission = m;
}

std::ostream &operator << (std::ostream &out, const Transformer &t) {
    out << "I'm " << t.name << "!" << "\n";
    return out;
}

// Pure virtual shouldn't be implemented.

void Transformer::attack() {
    std::cout << "Transformer " + name + " attacking!";
}
