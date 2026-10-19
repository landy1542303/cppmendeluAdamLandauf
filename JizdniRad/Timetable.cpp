#include "Timetable.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Timetable::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::stringstream ss(line);
            std::string code, origin, destination, time;

            std::getline(ss, code, ',');
            std::getline(ss, origin, ',');
            std::getline(ss, destination, ',');
            std::getline(ss, time);

            trains.push_back(Train(code, origin, destination, time));
        }
    }
}

int Timetable::getCount() const {
    return static_cast<int>(trains.size());
}

void Timetable::searchByDestination(const std::string& targetDest) const {
    int foundCount = 0;
    std::cout << "\nNalezene spoje do stanice " << targetDest << ":" << std::endl;

    for (const auto& train : trains) {
        if (train.getDestination() == targetDest) {
            std::cout << "- Vlak " << train.getCode() << " | Z: " << train.getOrigin() 
                      << " | Odjezd: " << train.getDepartureTime() << std::endl;
            foundCount++;
        }
    }

    if (foundCount == 0) {
        std::cout << "Zadny spoj do této stanice nebyl nalezen." << std::endl;
    } else {
        std::cout << "Celkem nalezeno spoju: " << foundCount << std::endl;
    }
}