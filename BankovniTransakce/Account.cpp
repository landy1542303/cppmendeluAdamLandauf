#include "Account.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Account::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::stringstream ss(line);
            std::string desc, amountStr;

            std::getline(ss, desc, ',');
            std::getline(ss, amountStr);

            transactions.push_back(Transaction(desc, std::stod(amountStr)));
        }
    }
}

int Account::getCount() const {
    return static_cast<int>(transactions.size());
}

double Account::getBalance() const {
    double total = 0.0;
    for (const auto& t : transactions) {
        total += t.getAmount();
    }
    return total;
}

void Account::filterExpensesAbove(double threshold) const {
    std::cout << "\nVydaje vetsi nez " << threshold << " Kc:" << std::endl;
    int count = 0;

    for (const auto& t : transactions) {
        if (t.isExpense()) {
            double expenseValue = -t.getAmount(); // převod na kladnou hodnotu pro porovnání
            if (expenseValue >= threshold) {
                std::cout << "- " << t.getDescription() << ": " << t.getAmount() << " Kc" << std::endl;
                count++;
            }
        }
    }

    if (count == 0) {
        std::cout << "Zadny takovy vydaj nebyl nalezen." << std::endl;
    }
}