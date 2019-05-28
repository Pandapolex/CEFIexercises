#include <iostream>
#include "anfora.cpp"

using namespace std;

int main() {

    auto* t1 = new Anfora(3,0);
    auto* t2 = new Anfora(5,0);

    while (t2->Livello() != 4) {

        (t2->Livello() == t2->getName()) ? t2->Svuota() : t1->Riempi();
        t1->Stato();
        t2->Stato();

        t1->Travasa(t2);
        t1->Stato();
        t2->Stato();

    }

    t1->~Anfora();
    t2->~Anfora();

    return 0;
}


