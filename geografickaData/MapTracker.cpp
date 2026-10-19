#include "MapTracker.h"
#include <fstream>
#include <sstream>
#include <iostream>

void MapTracker::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Chyba: Soubor " << filename << " se nepodarilo otevrit!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::stringstream ss(line);
            std::string name, latStr, lonStr;

            std::getline(ss, name, ',');
            std::getline(ss, latStr, ',');
            std::getline(ss, lonStr);

            places.push_back(Place(name, std::stod(latStr), std::stod(lonStr)));
        }
    }
}

int MapTracker::getCount() const {
    return static_cast<int>(places.size());
}

void MapTracker::filterArea(double minLat, double maxLat, double minLon, double maxLon) const {
    int insideCount = 0;
    int outsideCount = 0;

    for (const auto& place : places) {
        if (place.isInside(minLat, maxLat, minLon, maxLon)) {
            insideCount++;
            std::cout << "[UVNITR] " << place.getName() << " (" << place.getLat() << ", " << place.getLon() << ")" << std::endl;
        } else {
            outsideCount++;
        }
    }

    std::cout << "\nCelkovy prehled:" << std::endl;
    std::cout << "Pocet mist uvnitr: " << insideCount << std::endl;
    std::cout << "Pocet mist vne: " << outsideCount << std::endl;
}

void MapTracker::run() {
    loadFromFile("places.txt");

    if (places.empty()) {
        std::cout << "Zadna data nebyla nactena!" << std::endl;
        return;
    }

    std::cout << "Nacteno mist: " << places.size() << std::endl;

    double minLat, maxLat, minLon, maxLon;
    std::cout << "Zadej rozsah sirky (minLat maxLat): ";
    std::cin >> minLat >> maxLat;

    std::cout << "Zadej rozsah delky (minLon maxLon): ";
    std::cin >> minLon >> maxLon;

    filterArea(minLat, maxLat, minLon, maxLon);
}