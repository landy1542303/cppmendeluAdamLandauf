#ifndef WORDCARD_H
#define WORDCARD_H

#include <string>

class WordCard {
private:
    std::string foreign;
    std::string translation;

public:
    WordCard(const std::string& foreign, const std::string& translation);

    std::string getForeign() const;
    std::string getTranslation() const;
    bool checkAnswer(const std::string& answer) const;
};

#endif