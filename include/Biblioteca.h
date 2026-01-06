

#ifndef OOP_BIBLIOTECA_H
#define OOP_BIBLIOTECA_H

#include<vector>
#include<iostream>
#include<algorithm>
#include "Carte.h"
#include "Cititor.h"
#include  "StatisticiBiblioteca.h"
class Biblioteca {
private:
    std::vector<Carte*> carti;

public:
    Biblioteca();
    ~Biblioteca();
    std::vector<Carte*> getCarti() const{return carti;}

    void adaugaCarte(Carte* c);
    void afiseazaStatistici();
    void afiseazaCarte(std::ostream& out) const;
    void sorteazaTitlu();
    Carte* recomandaCarte(const Cititor& cititor) const;
    Carte* CeaMaiPopularaPeGen(const std::string& gen) const;


    void swap (Biblioteca& o);
    static int scorStandard(int nivel) {
        return nivel*2;
    }

};

#endif //OOP_BIBLIOTECA_H