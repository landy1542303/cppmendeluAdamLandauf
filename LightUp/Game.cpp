#include "Game.h"
#include <iostream>

void Game::run() {
    std::cout << "Vitejte ve hre Light Up!" << std::endl;
    std::cout << "Vysvetlivky: # = zed, * = zarovka, + = osvetleno, . = tma" << std::endl;

    while (!board.isAllLit()) {
        board.printBoard();

        int r, c;
        std::cout << "\nZadej souradnice pro zarovku (radek a sloupec, zaporne cislo pro konec): ";
        std::cin >> r;

        if (r < 0) {
            std::cout << "Hra byla ukoncena." << std::endl;
            return;
        }

        std::cin >> c;

        if (board.placeBulb(r, c)) {
            std::cout << "-> Zarovka umistena!" << std::endl;
        } else {
            std::cout << "-> Sem zarovku nelze umistit!" << std::endl;
        }
    }

    std::cout << "\nGratulace! Cela mistnost je osvetlena!" << std::endl;
    board.printBoard();
}