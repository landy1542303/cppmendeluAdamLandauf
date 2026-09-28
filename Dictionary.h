#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>

class Dictionary {
private:
    std::string history = " ";

public:
    bool isUsed(std::string word);
    void addWord(std::string word);
};

#endif