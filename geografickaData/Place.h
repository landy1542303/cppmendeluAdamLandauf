#ifndef PLACE_HPP
#define PLACE_HPP

#include <string>

class Place {
private:
    std::string name;
    double lat;
    double lon;

public:
    Place(const std::string& name, double lat, double lon);

    std::string getName() const;
    double getLat() const;
    double getLon() const;
    bool isInside(double minLat, double maxLat, double minLon, double maxLon) const;
};

#endif