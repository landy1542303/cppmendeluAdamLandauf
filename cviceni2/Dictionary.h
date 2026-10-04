#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <map>

class Dictionary {
private:
    std::map<std::string, std::string> dictionary;

public:
    Dictionary(std::string filename);
    std::string findResponse(std::string query);
};

#endif