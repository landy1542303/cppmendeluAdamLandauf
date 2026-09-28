#include "Dictionary.h"

bool Dictionary::isUsed(std::string word) {
    return history.contains(" " + word + " ");
}

void Dictionary::addWord(std::string word) {
    history += word + " ";
}