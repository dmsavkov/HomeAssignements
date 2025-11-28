#include "weapon.h"

Weapon::Weapon(std::string name, int damage) 
    : name(name), damage(damage) {}

Weapon::~Weapon() {}

std::string Weapon::getName() const {
    return name;
}

int Weapon::getDamage() const {
    return damage;
}

void Weapon::setName(std::string n) {
    name = n;
}

void Weapon::setDamage(int d) {
    damage = d;
}

std::ostream& operator<<(std::ostream& out, const Weapon& w) {
    out << "Weapon: " << w.name << " (Damage: " << w.damage << ")";
    return out;
}