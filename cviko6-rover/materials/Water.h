#ifndef COMPLETE_WATER_H
#define COMPLETE_WATER_H

#include <iostream>
#include "Ice.h"

struct Water {
    float m_volume;

    const float m_density = 1.0f;
    const float m_loss_factor = 0.1f;

    Water(const Ice& ice) {
        m_volume = ice.m_weight * m_density * (1 - m_loss_factor);
        std::cout << "[LOG] Water constructor (" << m_volume << " l)" << std::endl;
    }

    Water(const Water& other) : m_volume(other.m_volume) {
        std::cout << "[LOG] Water copy constructor (" << m_volume << " l)" << std::endl;
    }

    Water(Water&& other) noexcept : m_volume(other.m_volume) {
        std::cout << "[LOG] Water move constructor (" << m_volume << " l)" << std::endl;
    }

    ~Water() {
        std::cout << "[LOG] Water destructor (" << m_volume << " l)" << std::endl;
    }

    void printInfo() const {
        std::cout << "This is Water with volume " << m_volume << " litres." << std::endl;
    }
};

#endif //COMPLETE_WATER_H
