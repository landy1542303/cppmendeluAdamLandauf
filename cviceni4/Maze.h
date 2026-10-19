//
// Created by aland on 12.10.2026.
//

#ifndef CVIKO3_UKOL_MAZE_H
#define CVIKO3_UKOL_MAZE_H
#include <array>
#include <algorithm>
#include <string>

#include "Worm.h"
const int mazeSize = 5;

class Maze {
private:
    std::array<std::array<char, mazeSize>, mazeSize> maze;
public:
    Maze();
    bool checkPosition(int x, int y);
    void drawMaze(int wormX, int wormY);
    void clear();
    void placeWormOnEmptyField(Worm& worm);
    int wallsCount();
    void loadFromTextFile(const std::string& filename);
    void saveToTextFile(const std::string& filename);
};


#endif //CVIKO3_UKOL_MAZE_H
