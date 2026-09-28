#include "Game.h"
#include <iostream>

bool Game::isMatching(const std::string& current, const std::string& previous) {
    if (previous.empty()) {
        return true;
    }
    return current.starts_with(previous.back());
}

void Game::play() {
    std::cout << "SLOVNI FOTBAL\n";

    while (true) {
        std::cout << "Zadej slovo: ";
        std::string word;
        std::cin >> word;

        if (word == "konec") {
            break;
        }

        if (!isMatching(word, lastWord)) {
            std::cout << "Spatne pismeno! Prohral jsi.\n";
            break;
        }
        if (dictionary.isUsed(word)) {
            std::cout << "Slovo uz bylo! Prohral jsi.\n";
            break;
        }

        dictionary.addWord(word);
        lastWord = word;
    }
}