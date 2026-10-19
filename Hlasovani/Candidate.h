#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>

class Candidate {
private:
    std::string name;
    int votes;

public:
    Candidate(const std::string& name);

    std::string getName() const;
    int getVotes() const;
    void addVote();
};

#endif