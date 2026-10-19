#ifndef DECK_H
#define DECK_H

#include "WordCard.h"
#include <vector>
#include <string>

class Deck {
private:
    std::vector<WordCard> cards;

public:
    void loadFromFile(const std::string& filename);
    int getSize() const;
    const WordCard& getCard(int index) const;
};

#endif