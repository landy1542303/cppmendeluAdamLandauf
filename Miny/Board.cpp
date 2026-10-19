#include "Board.h"
#include <fstream>
#include <iostream>

Board::Board(int rows, int cols) : rows(rows), cols(cols) {
    grid.resize(rows, std::vector<Cell>(cols));
}

void Board::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    int r, c;
    while (file >> r >> c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            grid[r][c].setMine();
        }
    }
}

bool Board::isLoaded() const {
    return !grid.empty();
}

bool Board::revealCell(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) return true;

    grid[r][c].reveal();
    // Vrací false, pokud hráč šlápl na minu (konec hry)
    return !grid[r][c].isMine();
}

bool Board::isGameWon() const {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            // Pokud bezpečné políčko ještě není odhalené, hráč ještě nevyhrál
            if (!grid[r][c].isMine() && !grid[r][c].isRevealed()) {
                return false;
            }
        }
    }
    return true;
}

void Board::printBoard() const {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (!grid[r][c].isRevealed()) {
                std::cout << ". "; // Skryté políčko
            } else if (grid[r][c].isMine()) {
                std::cout << "* "; // Mina
            } else {
                std::cout << "O "; // Bezpečné odhalené políčko
            }
        }
        std::cout << std::endl;
    }
}