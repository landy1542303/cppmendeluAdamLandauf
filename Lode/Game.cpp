#include "Game.h"
#include <iostream>

Game::Game() : board(5, 5) {} // Hrací plocha o rozměru 5x5

void Game::run() {
    board.loadFromFile("ships.txt");

    if (!board.isLoaded()) {
        std::cout << "Chyba: Nepodarilo se nacist pozice lodi ze souboru ships.txt!" << std::endl;
        return;
    }

    std::cout << "Vitejte ve hre Lode!" << std::endl;

    while (board.getRemainingShips() > 0) {
        std::cout << "\nZbyva potopit lodi: " << board.getRemainingShips() << std::endl;
        board.printBoard();

        int r, c;
        std::cout << "Zadej souradnice vystrelu (radek sloupec 0-4): ";
        std::cin >> r >> c;

        if (board.shoot(r, c)) {
            std::cout << "-> ZASAH!" << std::endl;
        } else {
            std::cout << "-> VODA!" << std::endl;
        }
    }

    std::cout << "\nGratulace! Vsechny lode byly uspesne potopeny." << std::endl;
    board.printBoard();
}