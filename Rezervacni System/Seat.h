#ifndef SEAT_H
#define SEAT_H

class Seat {
private:
    bool occupied;

public:
    Seat();
    explicit Seat(bool isOccupied);

    bool isOccupied() const;
    bool reserve();
    char getSymbol() const;
};

#endif