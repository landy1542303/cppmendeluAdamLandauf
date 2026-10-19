#ifndef TIMETABLE_H
#define TIMETABLE_H

#include "Train.h"
#include <vector>
#include <string>

class Timetable {
private:
    std::vector<Train> trains;

public:
    void loadFromFile(const std::string& filename);
    int getCount() const;
    void searchByDestination(const std::string& targetDest) const;
};

#endif