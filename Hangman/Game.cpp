//
//  Game.cpp
//  pripravaNaTest
//
//  Created by Adam Landauf on 19.10.2026.
//
#include <iostream>
#include "Game.hpp"
#include "Hangman.hpp"
#include "Dictionary.hpp"
void Game::run() {
    dictionary.loadFromFile("/Users/landy/pripravaNaTest/words.txt");
    
    if (dictionary.getCount() == 0) {
        std::cout << "Chyba: Slovnik je prazdny nebo se nenasel soubor words!" << std::endl;
        return;
    }
    
    std::cout << "Hra zacina!" << std::endl;
    std::cout << "Zadejte index: ";
    int index;
    std::cin >> index;
    
    std::string selectedWord = dictionary.getWord(index);
    Hangman hra(selectedWord);
    
    // Smyčka pouze řídí hádání
    while (!hra.hasLost() && !hra.hasWon()) {
        std::cout << "\nPocet zivotu: " << hra.getLivesCount() << std::endl;
        std::cout << "Slovo: " << hra.getMaskedWord() << std::endl;
        std::cout << "Zadej pismeno: ";
        
        char letter;
        std::cin >> letter;
        hra.guess(letter);
    }
    
    if (hra.hasWon()) {
        std::cout << "\nVyhral jsi! Slovo bylo: " << hra.getMaskedWord() << std::endl;
    } else {
        std::cout << "\nProhral jsi! Dosly ti zivoty." << std::endl;
    }
}
