// Author: Савков Дмитрий 25.Б81-мм
// Contact: st140851@student.spbu.ru
// Description: Minibot class declaration - small agile Transformer for reconnaissance missions

#ifndef MINIBOT_H
#define MINIBOT_H

#include <string>

class Mission {
private:
    std::string description;
    int difficulty;

public:
    Mission(std::string description, int difficulty);
    ~Mission();

    std::string getDescription();
    int getDifficulty();

    void setDescription(std::string d);
    void setDifficulty(int d);
};

#endif