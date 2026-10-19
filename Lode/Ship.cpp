#include "Ship.h"

Ship::Ship(int row, int col) : row(row), col(col), hit(false) {}

int Ship::getRow() const {
    return row;
}

int Ship::getCol() const {
    return col;
}

bool Ship::isHit() const {
    return hit;
}

bool Ship::checkHit(int targetRow, int targetCol) {
    if (!hit && row == targetRow && col == targetCol) {
        hit = true;
        return true;
    }
    return false;
}