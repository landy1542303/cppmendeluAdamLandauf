//
// Created by aland on 12.10.2026.
//

#ifndef CVIKO3_UKOL_GAME_H
#define CVIKO3_UKOL_GAME_H
#include "Maze.h"
#include "Worm.h"


class Game {
private:
    Maze maze;
    Worm worm;

public:
    void play();
};


#endif //CVIKO3_UKOL_GAME_H
