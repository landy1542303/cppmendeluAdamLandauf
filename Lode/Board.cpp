#include "Board.h"
#include <fstream>
#include <iostream>

Board::Board(int rows, int cols) : rows(rows), cols(cols) {}

void Board::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    int r, c;
    while (file >> r >> c) {
        ships.push_back(Ship(r, c));
    }
}

bool Board::isLoaded() const {
    return !ships.empty();
}

bool Board::shoot(int targetRow, int targetCol) {
    for (auto& ship : ships) {
        if (ship.checkHit(targetRow, targetCol)) {
            return true;
        }
    }
    return false;
}

int Board::getRemainingShips() const {
    int remaining = 0;
    for (const auto& ship : ships) {
        if (!ship.isHit()) {
            remaining++;
        }
    }
    return remaining;
}

void Board::printBoard() const {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            char symbol = '~'; // Voda

            for (const auto& ship : ships) {
                if (ship.getRow() == r && ship.getCol() == c && ship.isHit()) {
                    symbol = 'X'; // Zasažená loď
                }
            }

            std::cout << symbol << " ";
        }
        std::cout << std::endl;
    }
}