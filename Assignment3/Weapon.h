// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Weapon class declaration - represents a Transformer's weapon with name and damage

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
private:
    std::string name;
    int damage;

public:
    Weapon(std::string name, int damage);
    ~Weapon();

    std::string getName() const;
    int getDamage() const;

    void setName(std::string n);
    void setDamage(int d);
};

#endif 