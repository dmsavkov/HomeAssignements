#include "mission.h"

Mission::Mission(std::string description, int difficulty) 
    : description(description), difficulty(difficulty) {}

Mission::~Mission() {}

std::string Mission::getDescription() {
    return description;
}

int Mission::getDifficulty() {
    return difficulty;
}

void Mission::setDescription(std::string d) {
    description = d;
}

void Mission::setDifficulty(int d) {
    difficulty = d;
}

std::ostream& operator<<(std::ostream& out, const Mission& m) {
    out << "Mission: " << m.description << " (Difficulty: " << m.difficulty << ")";
    return out;
}