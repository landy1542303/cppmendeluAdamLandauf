#ifndef CINEMAHALL_H
#define CINEMAHALL_H

#include "Seat.h"
#include <vector>
#include <string>

class CinemaHall {
private:
    std::vector<std::vector<Seat>> layout;

public:
    void loadFromFile(const std::string& filename);
    bool isLoaded() const;

    void display() const;
    int getFreeSeatsCount() const;
    bool reserveSeat(int row, int col);
};

#endif