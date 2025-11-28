// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Main entry point for Assignment 3 - Transformer demonstration

#include <iostream>
#include "autobot.h"
#include "decepticon.h"
#include "minibot.h"
#include "transformer.h"
#include "weapon.h"
#include "mission.h"
#include <array>

int main() {
    Autobot optimus("Optimus Prime", 100, 50.0, "car", 
                    Weapon("Plasma Cannon", 30), nullptr, 100);
    
    Decepticon megatron("Megatron", 120, 60.0, "tank", 
                        Weapon("Fusion Cannon", 40), nullptr, 120);
    
    Minibot bumblebee("Bumblebee", 80, 40.0, "car", 
                      Weapon("Stinger Blaster", 20), nullptr, 80);

    std::array<Transformer*, 3> transformers = {&optimus, &megatron, &bumblebee};

    std::cout << "Transformers: " << std::endl;
    for (auto& transformer : transformers) {
        std::cout << *transformer;
    }

    return 0;
}

