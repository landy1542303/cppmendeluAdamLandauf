#include "CinemaHall.h"
#include <fstream>
#include <iostream>

void CinemaHall::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::vector<Seat> row;
            for (char ch : line) {
                row.push_back(Seat(ch == 'X'));
            }
            layout.push_back(row);
        }
    }
}

bool CinemaHall::isLoaded() const {
    return !layout.empty();
}

void CinemaHall::display() const {
    std::cout << "\n  ";
    if (!layout.empty()) {
        for (size_t c = 0; c < layout[0].size(); c++) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    for (size_t r = 0; r < layout.size(); r++) {
        std::cout << r << " ";
        for (const auto& seat : layout[r]) {
            std::cout << seat.getSymbol() << " ";
        }
        std::cout << std::endl;
    }
}

int CinemaHall::getFreeSeatsCount() const {
    int freeCount = 0;
    for (const auto& row : layout) {
        for (const auto& seat : row) {
            if (!seat.isOccupied()) {
                freeCount++;
            }
        }
    }
    return freeCount;
}

bool CinemaHall::reserveSeat(int row, int col) {
    if (row < 0 || row >= static_cast<int>(layout.size())) return false;
    if (col < 0 || col >= static_cast<int>(layout[row].size())) return false;

    return layout[row][col].reserve();
}