#include "Cell.h"

Cell::Cell() : wall(false), bulb(false), illuminated(false) {}

Cell::Cell(bool isWall) : wall(isWall), bulb(false), illuminated(false) {}

bool Cell::isWall() const {
    return wall;
}

bool Cell::isBulb() const {
    return bulb;
}

bool Cell::isIlluminated() const {
    return illuminated;
}

void Cell::setBulb() {
    bulb = true;
    illuminated = true;
}

void Cell::setIlluminated() {
    illuminated = true;
}

char Cell::getSymbol() const {
    if (wall) return '#';
    if (bulb) return '*';
    if (illuminated) return '+';
    return '.';
}