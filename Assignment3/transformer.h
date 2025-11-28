// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Base Transformer class declaration - represents a transforming robot with weapon and mission

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>

#include "weapon.h"
#include "mission.h"
#include <iostream>


class Transformer {
    private:
        std::string name;
        int strength;
        double speed;
        std::string vehicleType;
        bool transformed;
        Weapon mainWeapon;
        Mission* curMission;

    public:
        Transformer(const std::string& name, int strength, double speed,
                const std::string& vehicleType, const Weapon& weapon, Mission* mission);
        virtual ~Transformer();

        Transformer(const std::string& name, int strength, double speed);
        Transformer(const std::string& name, int strength, int speed,
                const std::string& vehicleType, const Weapon& weapon, Mission* mission);

        // Preferably friend cuz getters for public API and << is more internal. 
        // Without friend t isn't needed: internal "this" exists.
        friend std::ostream& operator<<(std::ostream& out, const Transformer& t);

        void transform();
        bool isTransformed() const;
        void battleCry();
        void displayStatus();

        std::string getName() const;
        int getStrength() const;
        double getSpeed() const;
        std::string getVehicleType() const;
        Weapon getMainWeapon() const;
        Mission* getCurrentMission() const;
        
        // Setters
        void setName(const std::string& name);
        void setStrength(int strength);
        void setSpeed(double speed);
        void setVehicleType(const std::string& vehicleType);
        void setMainWeapon(const Weapon& weapon);
        void setCurrentMission(Mission* mission);

        virtual void specialAbility() = 0;
        virtual void attack(); 
};

#endif