#include <iostream>
#include "BankAccount.h"

int main() {

    BankAccount *Fabio = new BankAccount("Fabio", 1000);

    Fabio->operation(DEPOSIT,500);
    Fabio->operation(DEPOSIT,500);
    Fabio->operation(DEPOSIT,200);
    Fabio->printBalance();
    Fabio->operation(WITHDRAWAL,700);
    Fabio->printBalance();
    Fabio->operation(WITHDRAWAL,700);
    Fabio->operation(WITHDRAWAL,800);
    Fabio->operation(DEPOSIT,200);
    Fabio->operation(DEPOSIT,-200);
    Fabio->operation(WITHDRAWAL,300);
    Fabio->printBalance();
    Fabio->printOperations(MAX_OUT_OP);

    Fabio->~BankAccount();
    return 0;
}