//
// Created by aland on 12.10.2026.
//

#include "Worm.h"

Worm::Worm(int startX, int startY) {
    this->x = startX;
    this->y = startY;
}


int Worm::getX() {
    return x;
}

int Worm::getY() {
    return y;
}

void Worm::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}