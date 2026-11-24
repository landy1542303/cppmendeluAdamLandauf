cmake_minimum_required(VERSION 3.23)
project(complete)

set(CMAKE_CXX_STANDARD 14)

add_executable(complete
        tests/TestSuite/Suite.cpp tests/TestSuite/Test.cpp tests/RoverTest.cpp main.cpp)
