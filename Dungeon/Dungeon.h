#ifndef DUNGEON_H
#define DUNGEON_H

#include "Fighter.h"
#include <vector>
#include <string>

class Dungeon {
private:
    std::vector<Fighter> monsters;

public:
    void loadFromFile(const std::string& filename);
    bool hasMonsters() const;
    int getMonsterCount() const;
    Fighter getMonster(int index) const;
};

#endif