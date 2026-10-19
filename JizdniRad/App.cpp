#include "App.h"
#include <iostream>

void App::run() {
    timetable.loadFromFile("trains.txt");

    if (timetable.getCount() == 0) {
        std::cout << "Jizdni rad je prazdny." << std::endl;
        return;
    }

    std::cout << "Jizdni rad nacten (" << timetable.getCount() << " spoju)." << std::endl;
    std::cout << "Zadej cilovou stanici (napr. Praha): ";
    std::string dest;
    std::cin >> dest;

    timetable.searchByDestination(dest);
}