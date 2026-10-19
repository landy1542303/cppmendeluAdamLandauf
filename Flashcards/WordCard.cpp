#include "WordCard.h"

WordCard::WordCard(const std::string& foreign, const std::string& translation)
    : foreign(foreign), translation(translation) {}

std::string WordCard::getForeign() const {
    return foreign;
}

std::string WordCard::getTranslation() const {
    return translation;
}

bool WordCard::checkAnswer(const std::string& answer) const {
    return translation == answer;
}