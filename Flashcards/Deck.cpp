#include "Deck.h"
#include <fstream>
#include <sstream>

void Deck::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::stringstream ss(line);
            std::string foreign, translation;

            std::getline(ss, foreign, ',');
            std::getline(ss, translation);

            cards.push_back(WordCard(foreign, translation));
        }
    }
}

int Deck::getSize() const {
    return static_cast<int>(cards.size());
}

const WordCard& Deck::getCard(int index) const {
    return cards[index];
}