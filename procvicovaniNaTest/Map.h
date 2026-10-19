//
// Created by aland on 19.10.2026.
//

#ifndef PROCVICOVANI_MAP_H
#define PROCVICOVANI_MAP_H
#include <string>
#include <vector>

#include "Point.h"


class Map {
private:
    std::vector<Point> points;
public:
    void loadFromFile(const std::string &fileName);
    int countInRectangle(double minX, double maxX, double minY, double maxY) const;
};


#endif //PROCVICOVANI_MAP_H
