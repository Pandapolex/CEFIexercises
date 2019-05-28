//
// Created by Puk on 2019-05-23.
//

#ifndef ANFORE_ANFORA_H
#define ANFORE_ANFORA_H

#include <iostream>

class Anfora {
private:
    int nome;
    int volume;
public:
    int getName() {
        return nome;
    };

    void Riempi() {
        std::cout << "Sto riempiedo la tanica da " << getName() << " galloni\n";
    //    printf("Sto riempiedo la tanica da %d galloni\n",getName());
        volume += getName();
    };

    void Svuota() {
        std::cout << "Sto svuotando la tanica da " << getName() << " galloni\n";
        volume -= getName();
    };

    void Riempi(int g) {
        volume += g;
    };

    void Svuota(int g) {
        volume -= g;
    };

    int Livello() {
        return volume;
    };

    void Stato() {
        if (getName() == Livello()) {
            std::cout << "La tanica da " << getName() << " galloni è piena\n";
        } else if (Livello() == 0) {
            std::cout << "La tanica da " << getName() << " galloni è vuota\n";
        } else std::cout << "La tanica da " << getName() << " galloni ne contiene " << Livello() << "\n";
    }


    Anfora() {
        nome = 0;
        volume = 0;
    };

    Anfora(int n, int v) {
        nome = n;
        volume = v;
    };

    ~Anfora();

    void Travasa(Anfora* t) {

        int volumeDaTravasare = this->Livello();
        int gallone = 0;
        for (int i = 0; i < volumeDaTravasare ; i++) {
            this->Svuota(1);
            t->Riempi(1);
            gallone++;
            if (t->Livello() == t->getName()) {
                break;
            }
        }
        std::cout << "Sto travasando " << gallone << " gallon";
        (gallone == 1) ? std::cout << "e" : std::cout << "i";
        std::cout << " dalla tanica da " << t->getName() << " galloni a quella da "
        << t->getName() << " galloni" << std::endl;
    }
};



#endif //ANFORE_ANFORA_H
