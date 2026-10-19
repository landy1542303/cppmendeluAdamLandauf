#include "Dungeon.h"
#include <fstream>
#include <sstream>

void Dungeon::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::stringstream ss(line);
            std::string name, hpStr, attackStr;

            std::getline(ss, name, ',');
            std::getline(ss, hpStr, ',');
            std::getline(ss, attackStr);

            monsters.push_back(Fighter(name, std::stoi(hpStr), std::stoi(attackStr)));
        }
    }
}

bool Dungeon::hasMonsters() const {
    return !monsters.empty();
}

int Dungeon::getMonsterCount() const {
    return static_cast<int>(monsters.size());
}

Fighter Dungeon::getMonster(int index) const {
    return monsters[index];
}