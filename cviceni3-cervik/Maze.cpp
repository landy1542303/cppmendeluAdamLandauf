//
// Created by aland on 12.10.2026.
//

#include "Maze.h"

#include <iostream>

Maze::Maze() {
    for (auto& row : maze) {
        for (auto& cell : row) {
            cell = '-';
        }
    }
}

bool Maze::checkPosition(int x, int y) {
    if (x >= 0 && x < mazeSize && y >= 0 && y < mazeSize) {
        return true;
    }
    return false;
}

void Maze::drawMaze(int wormX, int wormY) {
    for (int y = 0; y < mazeSize; y++) {
        for (int x = 0; x < mazeSize; x++) {
            if (x == wormX && y == wormY) {
                std::cout << "@";
            }
            else {
                std::cout << maze[y][x];
            }
        }
        std::cout << std::endl;
    }
}