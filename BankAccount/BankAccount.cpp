//
// Created by Puk on 2019-05-27.
//

#include <iostream>
#include <ctime>
#include <iomanip>
#include "BankAccount.h"

void BankAccount::withdrawal(double amount) {
    if (this->balance - amount > 0) {
        std::cout << "I'm withdrawaling " << amount << "€\n";
        Operation *op;
        op = new operation_t;
        op->OperationDate = time(nullptr);
        op->typeOperation = WITHDRAWAL;
        op->amount = amount;
        this->balance -= amount;
        m_listOperation.push_back(*op);
    } else {
        throw badOperation("Operation not allowed! Insufficient Credit!\n");
    }
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        std::cout << "I'm depositing " << amount << "€\n";
        auto *op = new operation_t;
        op->OperationDate = time(nullptr);
        op->typeOperation = DEPOSIT;
        op->amount = amount;
        this->balance += amount;
        m_listOperation.push_back(*op);
    } else {
        throw badOperation("Operation not allowed! Insufficient Amount!\n");
    }
}

const void BankAccount::printBalance() {
    std::cout << "My Balance at "
             << printDate(time(nullptr))
             << " is "
             << std::setprecision(2) << std::fixed
             << float(this->balance) << "€\n";
}

const void BankAccount::printOperations(int n_ops) {

    std::vector<int>::size_type o;

    (n_ops > m_listOperation.size()) ? o = 0 : o = (m_listOperation.size()-n_ops);

    std::cout << "\nLast ";
    (o) ? std::cout << MAX_OUT_OP : std::cout << m_listOperation.size();
    std::cout << " Operations\n";
    std::cout << "----------------------------------------\n";
    for(auto i = o; i != m_listOperation.size(); i++) {
        std::cout << printDateTime(m_listOperation[i].OperationDate) << " ";
        std::cout << std::fixed << std::setw(10);
        (m_listOperation[i].typeOperation) ? std::cout << "DEPOSIT" : std::cout << "WITHDRAWAL";
        std::cout << std::setprecision(2) << " " << m_listOperation[i].amount << "€\n";
    }
}

void BankAccount::operation(e_operationType op, int amount) {
    try {
            (op) ? deposit(amount) : withdrawal(amount);
        } catch (std::exception& e) {
            std::cout<<e.what();
    }
}
std::string printDate(std::time_t tempo) {
    std::tm* date = std::localtime(&tempo);
    char buf[80];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d", date);
    return buf;
}


std::string printDateTime(std::time_t tempo) {
    std::tm* datet = std::localtime(&tempo);
    char buf[80];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d.%X", datet);
    return buf;
}
