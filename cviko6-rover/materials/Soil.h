#ifndef COMPLETE_SOIL_H
#define COMPLETE_SOIL_H

#include <iostream>
#include <string>

struct Soil {
    float m_weight;
    std::string m_composition;

    Soil(float weight, std::string composition) : m_weight(weight), m_composition(std::move(composition)) {
        std::cout << "[LOG] Soil constructor (" << m_weight << " kg)" << std::endl;
    }

    Soil(const Soil& other) : m_weight(other.m_weight), m_composition(other.m_composition) {
        std::cout << "[LOG] Soil copy constructor (" << m_weight << " kg)" << std::endl;
    }

    Soil(Soil&& other) noexcept : m_weight(other.m_weight), m_composition(std::move(other.m_composition)) {
        std::cout << "[LOG] Soil move constructor (" << m_weight << " kg)" << std::endl;
    }

    ~Soil() {
        std::cout << "[LOG] Soil destructor (" << m_weight << " kg)" << std::endl;
    }

    void printInfo() const {
        std::cout << "This is Soil with weight " << m_weight << " kg and composition made of " << m_composition << "." << std::endl;
    }
};

#endif //COMPLETE_SOIL_H
