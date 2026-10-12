cmake_minimum_required(VERSION 4.2)
project(cviko3_ukol)

set(CMAKE_CXX_STANDARD 26)

add_executable(cviko3_ukol main.cpp
        Worm.cpp
        Worm.h
        Maze.cpp
        Maze.h
        Game.cpp
        Game.h)
