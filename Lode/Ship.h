#ifndef SHIP_H
#define SHIP_H

class Ship {
private:
    int row;
    int col;
    bool hit;

public:
    Ship(int row, int col);

    int getRow() const;
    int getCol() const;
    bool isHit() const;

    bool checkHit(int targetRow, int targetCol);
};

#endif