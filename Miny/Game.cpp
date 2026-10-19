#include "Game.h"
#include <iostream>

Game::Game() : board(4, 4) {} // Velikost plochy 4x4

void Game::run() {
    board.loadFromFile("mines.txt");

    if (!board.isLoaded()) {
        std::cout << "Chyba: Soubor mines.txt se nepodarilo otevrit!" << std::endl;
        return;
    }

    std::cout << "Vitejte ve hre Hledani min!" << std::endl;

    bool alive = true;
    while (alive && !board.isGameWon()) {
        std::cout << "\nAktualni herni pole:" << std::endl;
        board.printBoard();

        int r, c;
        std::cout << "Zadej radek a sloupec k odhaleni (0-3): ";
        std::cin >> r >> c;

        alive = board.revealCell(r, c);

        if (!alive) {
            std::cout << "\nBUM! Slapl jsi na minu. Prohral jsi!" << std::endl;
            board.printBoard();
            return;
        }
    }

    std::cout << "\nGratulace! Odhalil jsi vsechna bezpecna policka a vyhral!" << std::endl;
    board.printBoard();
}