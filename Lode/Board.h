#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
#include <vector>
#include <string>

class Board {
private:
    int rows;
    int cols;
    std::vector<Ship> ships;

public:
    Board(int rows, int cols);

    void loadFromFile(const std::string& filename);
    bool isLoaded() const;

    bool shoot(int targetRow, int targetCol);
    int getRemainingShips() const;
    void printBoard() const;
};

#endif