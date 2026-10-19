#include "Board.h"
#include <iostream>
#include <string>

Board::Board() {
    // Definice herni plochy primo v kodu bez souboru
    std::vector<std::string> templateGrid = {
        "..#..",
        ".....",
        "#...#",
        ".....",
        "..#.."
    };

    for (const auto& line : templateGrid) {
        std::vector<Cell> row;
        for (char ch : line) {
            row.push_back(Cell(ch == '#'));
        }
        grid.push_back(row);
    }
}

void Board::castLight(int startR, int startC, int dRow, int dCol) {
    int r = startR + dRow;
    int c = startC + dCol;

    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());

    while (r >= 0 && r < rows && c >= 0 && c < cols) {
        if (grid[r][c].isWall()) {
            break;
        }
        grid[r][c].setIlluminated();
        r += dRow;
        c += dCol;
    }
}

bool Board::placeBulb(int r, int c) {
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());

    if (r < 0 || r >= rows || c < 0 || c >= cols) return false;
    if (grid[r][c].isWall() || grid[r][c].isBulb()) return false;

    grid[r][c].setBulb();

    castLight(r, c, -1, 0); // Nahoru
    castLight(r, c, 1, 0);  // Dolu
    castLight(r, c, 0, -1); // Vlevo
    castLight(r, c, 0, 1);  // Vpravo

    return true;
}

bool Board::isAllLit() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (!cell.isWall() && !cell.isIlluminated()) {
                return false;
            }
        }
    }
    return true;
}

void Board::printBoard() const {
    std::cout << "\n  ";
    if (!grid.empty()) {
        for (size_t c = 0; c < grid[0].size(); c++) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    for (size_t r = 0; r < grid.size(); r++) {
        std::cout << r << " ";
        for (const auto& cell : grid[r]) {
            std::cout << cell.getSymbol() << " ";
        }
        std::cout << std::endl;
    }
}