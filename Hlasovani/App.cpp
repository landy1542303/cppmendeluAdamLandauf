#include "App.h"
#include <iostream>

void App::run() {
    election.loadFromFile("votes.txt");

    if (!election.hasVotes()) {
        std::cout << "Zadna hlasovaci data nebyla nalezena." << std::endl;
        return;
    }

    election.printResults();

    Candidate winner = election.getWinner();
    std::cout << "\nVitezem voleb se stava: " << winner.getName() 
              << " s celkem " << winner.getVotes() << " hlasy!" << std::endl;
}