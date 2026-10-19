#include "Transaction.h"

Transaction::Transaction(const std::string& description, double amount)
    : description(description), amount(amount) {}

std::string Transaction::getDescription() const {
    return description;
}

double Transaction::getAmount() const {
    return amount;
}

bool Transaction::isExpense() const {
    return amount < 0;
}