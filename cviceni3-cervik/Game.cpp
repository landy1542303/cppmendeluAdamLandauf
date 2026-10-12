//
// Created by aland on 12.10.2026.
//

#include "Game.h"

#include <iostream>

void Game::play() {
    while (true) {
        maze.drawMaze(worm.getX(), worm.getY());

        char userMove;
        std::cout << "Zadejte vas pohyb" << std::endl;
        std::cin >> userMove;
        userMove = toupper(userMove);
        int newX = worm.getX();
        int newY = worm.getY();
        if (userMove == 'W') newY -= 1;
        else if (userMove == 'S') newY += 1;
        else if (userMove == 'A') newX -= 1;
        else if (userMove == 'D') newX += 1;
        else if (userMove == 'Q') break;
        else std::cout << "Neplatna volba (zadejte bud W,A,S,D)" << std::endl;
        if (maze.checkPosition(newX, newY)) {
            worm.setPosition(newX, newY);
        }
        else {
            std::cerr << "Neplatny pohyb" << std::endl;
        }
    }
}
