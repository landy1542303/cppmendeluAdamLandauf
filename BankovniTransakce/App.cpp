#include "App.h"
#include <iostream>

void App::run() {
    account.loadFromFile("transactions.txt");

    if (account.getCount() == 0) {
        std::cout << "Nebyly nacteny zadne transakce." << std::endl;
        return;
    }

    std::cout << "Nacteno transakci: " << account.getCount() << std::endl;
    std::cout << "Aktualni zustatek na uctu: " << account.getBalance() << " Kc" << std::endl;

    double limit;
    std::cout << "\nZadej minimalni vysi hledaneho vydaje (napr. 500): ";
    std::cin >> limit;

    account.filterExpensesAbove(limit);
}