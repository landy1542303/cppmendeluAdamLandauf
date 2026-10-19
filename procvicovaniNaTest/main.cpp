#include <iostream>

#include "Map.h"

int main() {
    Map mapa;
    mapa.loadFromFile("mesta.txt");
    double minX = -1, maxX = -1, minY = -1, maxY = -1;
    std::cout << "Zadejte meze" << std::endl;
    std::cin >> minX >> maxX >> minY >> maxY;
    int pocet = mapa.countInRectangle(minX, maxX, minY, maxY);
    std::cout << pocet << std::endl;
    return 0;
}
