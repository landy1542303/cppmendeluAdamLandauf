#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string description;
    double amount;

public:
    Transaction(const std::string& description, double amount);

    std::string getDescription() const;
    double getAmount() const;
    bool isExpense() const;
};

#endif