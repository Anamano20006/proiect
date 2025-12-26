//
// Created by Envy on 20.12.2025.
//

#ifndef OOP_BIBLIOTECA_H
#define OOP_BIBLIOTECA_H

#include<vector>
#include<iostream>
#include "Carte.h"
#include "Cititor.h"
#include  "StatisticiBiblioteca.h"
class Biblioteca {
private:
    std::vector<Carte*> carti;
    StatisticiBiblioteca statistici;
public:
    Biblioteca();
    ~Biblioteca();

    void adaugaCarte(Carte* c);
    void afiseazaCarte(std::ostream& out) const;
    void sorteazaTitlu();
    Carte* recomandaCarte(const Cititor& cititor) const;

    Carte* CeaMaiPopularaPeGen(const std::string& gen) const;

    void afiseazaStatistici();

};

#endif //OOP_BIBLIOTECA_H