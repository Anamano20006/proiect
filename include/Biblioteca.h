

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
    Biblioteca (const Biblioteca& o); //constr de copiere
    ~Biblioteca();
    std::vector<Carte*> getCarti() const{return carti;}
    const StatisticiBiblioteca& getStatistici() const{return statistici;}

    void adaugaCarte(Carte* c);
    void afiseazaCarte(std::ostream& out) const;
    void sorteazaTitlu();
    Carte* recomandaCarte(const Cititor& cititor) const;

    Carte* CeaMaiPopularaPeGen(const std::string& gen) const;

    void afiseazaStatistici();

    Biblioteca& operator=(Biblioteca o);

    void swap (Biblioteca& o) noexcept {
        using std::swap;
        swap(carti, o.carti);
        swap(statistici, o.statistici);

    }
    static int scorStandard(int nivel) {
        return nivel*2;
    }

};

#endif //OOP_BIBLIOTECA_H