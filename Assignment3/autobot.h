// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Autobot class declaration - heroic Transformer with loyalty trait

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "transformer.h"
#include <string>

class Autobot : public Transformer {
private:
    int loyalty;

public:
    Autobot(std::string name, int strength, double speed,
            std::string vehicleType, Weapon mainWeapon, Mission* curMission,
            int loyalty);
    Autobot(const std::string name, int strength, double speed, int loyalty);
    ~Autobot();

    int getLoyalty() const;
    void setLoyalty(int l);

    void updateLoyalty(int amount);

    void shieldAlly();

    void attack() override;
    void specialAbility() override;
};

#endif