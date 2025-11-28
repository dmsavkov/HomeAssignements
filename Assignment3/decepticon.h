// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Decepticon class declaration - villainous Transformer with ruthlessness trait

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include <string>
#include "transformer.h"

class Decepticon : public Transformer {
private:
    int ruthlessness;

public:
    Decepticon(std::string name, int strength, double speed,
               std::string vehicleType, Weapon mainWeapon, Mission* curMission,
               int ruthlessness);
    Decepticon(const std::string name, int strength, double speed, int ruthlessness);
    ~Decepticon();

    int getRuthlessness();
    void setRuthlessness(int r);

    void updateRuthlessness(int amount);
    void intimidate();
};

#endif