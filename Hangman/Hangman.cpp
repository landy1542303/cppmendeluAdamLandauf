//
//  Hangman.cpp
//  pripravaNaTest
//
//  Created by Adam Landauf on 19.10.2026.
//

#include "Hangman.hpp"

Hangman::Hangman(const std::string& word) {
    secretWord = word;
    liveCounts = 5;
    maskedWord = std::string(word.length(), '_');
}
bool Hangman::guess(char letter) {
    bool hit = false;

    for (size_t i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == letter) {
            maskedWord[i] = letter;
            hit = true;
        }
    }

    if (!hit) {
        liveCounts--;
    }

    return hit;
}
bool Hangman::hasWon() const {
    return maskedWord == secretWord;
}

bool Hangman::hasLost() const {
    return liveCounts <= 0;
}

int Hangman::getLivesCount() const {
    return liveCounts;
}

std::string Hangman::getMaskedWord() const {
    return maskedWord;
}
