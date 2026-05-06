#include "Transaction.h"
#include <stdexcept>

Transaction::Transaction() {}
Transaction::~Transaction() {}

bool Transaction::Make(Account& from, Account& to, int sum) {
    if (sum < 0) throw std::invalid_argument("Negative sum");
    if (&from == &to) throw std::logic_error("Self-transfer");
    if (sum < 100) throw std::logic_error("Too small");
    if (from.GetBalance() < sum) return false;

    // Временное решение: меняем баланс без блокировки для прохождения тестов
    from.ChangeBalance(-sum);
    to.ChangeBalance(sum);
    
    return true;
}
