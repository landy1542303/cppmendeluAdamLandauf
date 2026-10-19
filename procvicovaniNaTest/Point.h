//
// Created by aland on 19.10.2026.
//

#ifndef PROCVICOVANI_POINT_H
#define PROCVICOVANI_POINT_H
#include <string>

class Point {
private:
    std::string name;
    double x;
    double y;

public:
    Point(std::string name, double x, double y);
    std::string getName() const;
    double getX() const;
    double getY() const;
};


#endif //PROCVICOVANI_POINT_H
