#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <vector>
#include <string>

class Board {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> grid;

public:
    Board(int rows, int cols);

    void loadFromFile(const std::string& filename);
    bool isLoaded() const;

    bool revealCell(int r, int c);
    bool isGameWon() const;
    void printBoard() const;
};

#endif