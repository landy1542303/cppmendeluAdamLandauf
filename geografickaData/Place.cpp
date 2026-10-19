#include "Place.h"

Place::Place(const std::string& name, double lat, double lon)
    : name(name), lat(lat), lon(lon) {}

std::string Place::getName() const {
    return name;
}

double Place::getLat() const {
    return lat;
}

double Place::getLon() const {
    return lon;
}

bool Place::isInside(double minLat, double maxLat, double minLon, double maxLon) const {
    return (lat >= minLat && lat <= maxLat && lon >= minLon && lon <= maxLon);
}