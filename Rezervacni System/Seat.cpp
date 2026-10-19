#include "Seat.h"

Seat::Seat() : occupied(false) {}

Seat::Seat(bool isOccupied) : occupied(isOccupied) {}

bool Seat::isOccupied() const {
    return occupied;
}

bool Seat::reserve() {
    if (!occupied) {
        occupied = true;
        return true;
    }
    return false;
}

char Seat::getSymbol() const {
    return occupied ? 'X' : '.';
}