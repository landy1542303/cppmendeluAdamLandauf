#include "Cell.h"

Cell::Cell() : mine(false), revealed(false) {}

void Cell::setMine() {
    mine = true;
}

bool Cell::isMine() const {
    return mine;
}

void Cell::reveal() {
    revealed = true;
}

bool Cell::isRevealed() const {
    return revealed;
}