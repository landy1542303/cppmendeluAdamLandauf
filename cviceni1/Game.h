#ifndef GAME_H
#define GAME_H

#include <string>
#include "Dictionary.h"

class Game {
private:
    Dictionary dictionary;
    std::string lastWord;

public:
    bool isMatching(const std::string& current, const std::string& previous);
    void play();
};

#endif