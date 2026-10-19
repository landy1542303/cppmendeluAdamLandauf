#ifndef ELECTION_H
#define ELECTION_H

#include "Candidate.h"
#include <vector>
#include <string>

class Election {
private:
    std::vector<Candidate> candidates;

    int findCandidateIndex(const std::string& name) const;

public:
    void loadFromFile(const std::string& filename);
    bool hasVotes() const;
    void printResults() const;
    Candidate getWinner() const;
};

#endif