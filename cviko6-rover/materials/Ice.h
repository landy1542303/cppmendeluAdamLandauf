#ifndef COMPLETE_ICE_H
#define COMPLETE_ICE_H

#include <iostream>

struct Ice {
    float m_weight;
    float m_temperature;

    Ice(float weight, float temperature) : m_weight(weight), m_temperature(temperature) {
        std::cout << "[LOG] Ice constructor (" << m_weight << " kg)" << std::endl;
    }

    Ice(const Ice& other) : m_weight(other.m_weight), m_temperature(other.m_temperature) {
        std::cout << "[LOG] Ice copy constructor (" << m_weight << " kg)" << std::endl;
    }

    Ice(Ice&& other) noexcept : m_weight(other.m_weight), m_temperature(other.m_temperature) {
        std::cout << "[LOG] Ice move constructor (" << m_weight << " kg)" << std::endl;
    }

    ~Ice() {
        std::cout << "[LOG] Ice destructor (" << m_weight << " kg)" << std::endl;
    }

    void printInfo() const {
        std::cout << "This is Ice with weight " << m_weight << " kg and temperature " << m_temperature << " deg C." << std::endl;
    }
};

#endif //COMPLETE_ICE_H
