//
//  Hangman.hpp
//  pripravaNaTest
//
//  Created by Adam Landauf on 19.10.2026.
//

#ifndef Hangman_hpp
#define Hangman_hpp
#include<iostream>
#include <stdio.h>

class Hangman{
private:
    std::string secretWord;
    std::string maskedWord;
    int liveCounts;
public:
    Hangman(const std::string &slovo);
    bool guess(char letter);
    int getLivesCount() const;
    std::string getMaskedWord() const;
    bool hasWon() const;
    bool hasLost() const;
};

#endif /* Hangman_hpp */
