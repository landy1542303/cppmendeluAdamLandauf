#ifndef CHATBOT_H
#define CHATBOT_H

#include "Dictionary.h"
#include <string>

class Chatbot {
private:
    std::string CHAT_NAME;
    Dictionary dict;

public:
    Chatbot(std::string name, std::string filename);
    std::string reply(std::string query);
    void chat();
};

#endif