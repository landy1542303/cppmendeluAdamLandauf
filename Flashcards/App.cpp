#include "App.h"
#include <iostream>

void App::run() {
    deck.loadFromFile("words.txt");

    if (deck.getSize() == 0) {
        std::cout << "Slovnik je prazdny nebo soubor nebyl nalezen." << std::endl;
        return;
    }

    std::cout << "Spoustim zkouseni ze slovicek (celkem " << deck.getSize() << "):" << std::endl;
    int correctCount = 0;

    for (int i = 0; i < deck.getSize(); i++) {
        const WordCard& card = deck.getCard(i);
        std::cout << "\nPreloz slovo: " << card.getForeign() << std::endl;
        std::cout << "Cesky: ";

        std::string answer;
        std::cin >> answer;

        if (card.checkAnswer(answer)) {
            std::cout << "-> Spravne!" << std::endl;
            correctCount++;
        } else {
            std::cout << "-> Spatne! Spravna odpoved byla: " << card.getTranslation() << std::endl;
        }
    }

    std::cout << "\nTest dokoncen! Tvoje skore: " << correctCount << " / " << deck.getSize() << std::endl;
}