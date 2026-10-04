#include "Dictionary.h"
#include <fstream>
#include <regex>

Dictionary::Dictionary(std::string filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        size_t spacePos = line.find(' ');

        if (spacePos != std::string::npos) {
            std::string keyword = line.substr(0, spacePos);
            std::string response = line.substr(spacePos + 1);
            dictionary[keyword] = response;
        }
    }
}

std::string Dictionary::findResponse(std::string query) {
    for (auto item : dictionary) {
        std::string keyword = item.first;
        std::string response = item.second;

        std::regex reg(keyword, std::regex_constants::icase);
        if (std::regex_search(query, reg)) {
            return response;
        }
    }

    return "Nerozumim, zkuste se prosim zeptat jinak.";
}