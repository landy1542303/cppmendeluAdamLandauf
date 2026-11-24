#ifndef COMPLETE_CONCRETE_H
#define COMPLETE_CONCRETE_H

#include <iostream>
#include "Soil.h"

struct Concrete {
    float m_weight;

    const float m_density = 0.2f;
    const float m_loss_factor = 0.3f;

    Concrete(const Soil& soil) {
        m_weight = soil.m_weight * m_density * (1 - m_loss_factor);
        std::cout << "[LOG] Concrete constructor (" << m_weight << " kg)" << std::endl;
    }

    Concrete(const Concrete& other) : m_weight(other.m_weight) {
        std::cout << "[LOG] Concrete copy constructor (" << m_weight << " kg)" << std::endl;
    }

    Concrete(Concrete&& other) noexcept : m_weight(other.m_weight) {
        std::cout << "[LOG] Concrete move constructor (" << m_weight << " kg)" << std::endl;
    }

    ~Concrete() {
        std::cout << "[LOG] Concrete destructor (" << m_weight << " kg)" << std::endl;
    }

    void printInfo() const {
        std::cout << "This is Concrete with weight " << m_weight << " kg." << std::endl;
    }
};

#endif //COMPLETE_CONCRETE_H
