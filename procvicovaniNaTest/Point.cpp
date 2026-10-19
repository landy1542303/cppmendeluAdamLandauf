//
// Created by aland on 19.10.2026.
//

#include "Point.h"

Point::Point(std::string name, double x, double y)
    : name(name), x(x), y(y) {}

std::string Point::getName() const {
    return name;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}