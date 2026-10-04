cmake_minimum_required(VERSION 4.2)
project(cviko2_chatbot)

set(CMAKE_CXX_STANDARD 26)

add_executable(cviko2_chatbot main.cpp
        Chatbot.cpp
        Chatbot.h
        Dictionary.cpp
        Dictionary.h)
