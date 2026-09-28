#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>

/* 
    Kde je uchovan vlastni slovnik povolenych slov?
 */   

class Dictionary {
private:
    std::string history = " ";

public:
    bool isUsed(std::string word);
    void addWord(std::string word);
};

#endif
