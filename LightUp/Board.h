#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <vector>

class Board {
private:
    std::vector<std::vector<Cell>> grid;

    void castLight(int startR, int startC, int dRow, int dCol);

public:
    Board();

    bool placeBulb(int r, int c);
    bool isAllLit() const;
    void printBoard() const;
};

#endif