#include "App.h"
#include <iostream>

void App::run() {
    hall.loadFromFile("cinema.txt");

    if (!hall.isLoaded()) {
        std::cout << "Chyba: Nepodarilo se nacist data kinosalu!" << std::endl;
        return;
    }

    std::cout << "Vitejte v rezervacnim systemu kina." << std::endl;

    while (true) {
        hall.display();
        std::cout << "Pocet volnych mist: " << hall.getFreeSeatsCount() << std::endl;

        int row, col;
        std::cout << "\nZadej radu a sedadlo (zaporne cislo pro ukonceni): ";
        std::cin >> row;

        if (row < 0) {
            std::cout << "Rezervace ukoncena." << std::endl;
            break;
        }

        std::cin >> col;

        if (hall.reserveSeat(row, col)) {
            std::cout << "-> Rezervace uspesna!" << std::endl;
        } else {
            std::cout << "-> Sedadlo je jiz obsazene nebo neexistuje!" << std::endl;
        }
    }
}