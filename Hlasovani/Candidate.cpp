#include "Candidate.h"

Candidate::Candidate(const std::string& name) : name(name), votes(0) {}

std::string Candidate::getName() const {
    return name;
}

int Candidate::getVotes() const {
    return votes;
}

void Candidate::addVote() {
    votes++;
}