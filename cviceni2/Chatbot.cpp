#include "Chatbot.h"
#include <iostream>

Chatbot::Chatbot(std::string name, std::string filename)
    : CHAT_NAME(name), dict(filename) {
}

std::string Chatbot::reply(std::string query) {
    return dict.findResponse(query);
}

void Chatbot::chat() {
    std::string input;

    while (true) {
        std::cout << "U: ";
        std::getline(std::cin, input);

        if (input == "konec") {
            break;
        }

        std::cout << CHAT_NAME << ": " << reply(input) << "\n";
    }
}