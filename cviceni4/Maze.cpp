//
// Created by aland on 12.10.2026.
//

#include "Maze.h"
#include <fstream>
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

void Maze::clear() {
    for (auto& row: maze) {
        std::fill(row.begin(), row.end(), '-');
        }
    }

void Maze::placeWormOnEmptyField(Worm& worm) {
    for (int y = 0; y < mazeSize; y++) {
        auto it = std::find(maze[y].begin(), maze[y].end(), '-');
        if (it != maze[y].end()) {
            int x = it - maze[y].begin();
            worm.setPosition(x, y);
            return;
        }
    }
}

int Maze::wallsCount() {
    int count=0;
    for (auto& row: maze) {
        count += std::count(row.begin(), row.end(), '#');
    }
    return count;
}
void Maze::loadFromTextFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Soubor se neotevrel! " << filename << std::endl;
        return;
    }
    for (int y=0; y<mazeSize; y++) {
        for (int x=0; x<mazeSize; x++) {
            file >> maze[y][x];
        }
    }
}

void Maze::saveToTextFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Soubor nenalezen! " << filename << std::endl;
        return;
    }
    for (int y=0; y<mazeSize; y++) {
        for (int x=0; x<mazeSize; x++) {
            file << maze[y][x];
        }
        file << std::endl;
    }

}