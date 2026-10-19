#include "Game.h"
#include <iostream>

Game::Game() : hero("Hrdina", 100, 15) {}

bool Game::fightMonster(Fighter monster) {
    std::cout << "\n=== Souboj s: " << monster.getName() 
              << " (HP: " << monster.getHp() << ", Utok: " << monster.getAttackPower() << ") ===" << std::endl;

    while (hero.isAlive() && monster.isAlive()) {
        std::cout << "\nTvoje HP: " << hero.getHp() 
                  << " | HP soupere: " << monster.getHp() << std::endl;
        std::cout << "Vyber akci (1 = Utok, 2 = Leceni): ";
        
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            monster.takeDamage(hero.getAttackPower());
            std::cout << "Zasadil jsi souperi uder za " << hero.getAttackPower() << " HP." << std::endl;
        } else {
            hero.heal(15);
            std::cout << "Vylecil ses o 15 HP." << std::endl;
        }

        // Pokud monstrum prezilo, vraci uder
        if (monster.isAlive()) {
            hero.takeDamage(monster.getAttackPower());
            std::cout << monster.getName() << " ti ubral " << monster.getAttackPower() << " HP!" << std::endl;
        }
    }

    return hero.isAlive();
}

void Game::run() {
    dungeon.loadFromFile("monsters.txt");

    if (!dungeon.hasMonsters()) {
        std::cout << "Chyba: Z dungeonu se nepodarilo nacist zadna monstra!" << std::endl;
        return;
    }

    std::cout << "Vstupujes do temneho podzemi..." << std::endl;

    for (int i = 0; i < dungeon.getMonsterCount(); i++) {
        Fighter currentMonster = dungeon.getMonster(i);
        bool survived = fightMonster(currentMonster);

        if (!survived) {
            std::cout << "\nPadl jsi v boji... Hra skoncila." << std::endl;
            return;
        }

        std::cout << "-> Porazil jsi " << currentMonster.getName() << "!" << std::endl;
    }

    std::cout << "\nGratulace! Vycistil jsi cele podzemi a prezil jsi!" << std::endl;
}