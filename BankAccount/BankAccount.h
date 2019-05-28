//
// Created by Puk on 2019-05-27.
//

#ifndef BANKACCOUNT_BANKACCOUNT_H
#define BANKACCOUNT_BANKACCOUNT_H

#define MAX_OUT_OP 5

#include <ctime>
#include <string>
#include <vector>
#include <exception>

typedef enum TypeOperation {
    WITHDRAWAL, DEPOSIT
} e_operationType;

typedef struct Operation {
    e_operationType typeOperation;
    std::time_t OperationDate;
    double amount;
}operation_t;

class BankAccount {
    std::string m_Account;
    double balance;
    std::vector<operation_t> m_listOperation;

public:
    BankAccount(std::string m_Account,double balance)
        : m_Account(m_Account), balance(balance) {};
    ~BankAccount() { };

    void withdrawal(double amount);
    void deposit(double amount);
    const void printBalance();
    const void printOperations(int);
    void operation(e_operationType,int);
};

std::string printDate(std::time_t);
std::string printDateTime(std::time_t);

struct badOperation : public std::exception
{
protected:
    const char *errorMsg;

public:
    badOperation (const char* str){
        errorMsg =  str;
    }
    const char * what () const throw ()
    {
        return errorMsg;
    }
};

#endif //BANKACCOUNT_BANKACCOUNT_H
