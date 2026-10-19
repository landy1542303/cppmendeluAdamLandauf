#ifndef MAPTRACKER_HPP
#define MAPTRACKER_HPP

#include "Place.h"
#include <vector>
#include <string>

class MapTracker {
private:
    std::vector<Place> places;

public:
    void loadFromFile(const std::string& filename);
    int getCount() const;
    void filterArea(double minLat, double maxLat, double minLon, double maxLon) const;
    void run(); // <--- nová metoda, která obslouží celou komunikaci
};

#endif