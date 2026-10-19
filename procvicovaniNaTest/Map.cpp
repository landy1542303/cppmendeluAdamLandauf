//
// Created by aland on 19.10.2026.
//

#include "Map.h"

#include <fstream>
#include <iostream>

void Map::loadFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << fileName << std::endl;
        exit(1);
    }
    std::string name;
    double x,y;
    while (file >> name >> x >> y) {
        points.push_back(Point(name,x,y));
    }
}

int Map::countInRectangle(double minX, double maxX, double minY, double maxY) const {
    int count = 0;

    for (const auto& p : points) {
        double x = p.getX();
        double y = p.getY();

        if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
            std::cout << p.getName() << std::endl;
            count++;
        }
    }

    return count;
}