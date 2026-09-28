#include "Dictionary.h"

bool Dictionary::isUsed(std::string word) {
    return history.contains(" " + word + " ");
}

/*
    Nebylo by lepsi resit vhodnou kolekci?
*/
void Dictionary::addWord(std::string word) {
    history += word + " ";
}
