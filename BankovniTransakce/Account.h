#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Transaction.h"
#include <vector>
#include <string>

class Account {
private:
    std::vector<Transaction> transactions;

public:
    void loadFromFile(const std::string& filename);
    int getCount() const;
    double getBalance() const;
    void filterExpensesAbove(double threshold) const;
};

#endif