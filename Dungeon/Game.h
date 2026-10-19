#ifndef GAME_H
#define GAME_H

#include "Dungeon.h"
#include "Fighter.h"

class Game {
private:
    Dungeon dungeon;
    Fighter hero;

    bool fightMonster(Fighter monster);

public:
    Game();
    void run();
};

#endif