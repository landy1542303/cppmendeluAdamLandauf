#include "Election.h"
#include <fstream>
#include <iostream>

int Election::findCandidateIndex(const std::string& name) const {
    for (size_t i = 0; i < candidates.size(); i++) {
        if (candidates[i].getName() == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void Election::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string name;
    while (file >> name) {
        if (!name.empty()) {
            int idx = findCandidateIndex(name);
            if (idx != -1) {
                candidates[idx].addVote();
            } else {
                Candidate newCand(name);
                newCand.addVote();
                candidates.push_back(newCand);
            }
        }
    }
}

bool Election::hasVotes() const {
    return !candidates.empty();
}

void Election::printResults() const {
    std::cout << "\nVysledky hlasovani:" << std::endl;
    for (const auto& c : candidates) {
        std::cout << "- " << c.getName() << ": " << c.getVotes() << " hlasu" << std::endl;
    }
}

Candidate Election::getWinner() const {
    Candidate winner = candidates[0];
    for (const auto& c : candidates) {
        if (c.getVotes() > winner.getVotes()) {
            winner = c;
        }
    }
    return winner;
}