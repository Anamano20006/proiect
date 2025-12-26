//
// Created by Envy on 20.12.2025.
//
#include"Biblioteca.h"
#include "Romance.h"
#include "Thriller.h"
#include<algorithm>
Biblioteca::Biblioteca() {
    for (auto c: carti ) {
        delete c;
    }
}
void Biblioteca::adaugaCarte(Carte* c) {
    carti.push_back(c);
    statistici.actualizeaza(carti);
}
void Biblioteca::afiseazaStatistici() {
    statistici.afiseazaStatistici();
}
 void Biblioteca::afiseazaCarte(std::ostream& out) const {
    for (auto c: carti) {
        out<<*c<<std::endl;
    }
}
void Biblioteca::sorteazaTitlu() {
    std::sort(carti.begin(), carti.end(),[](Carte* a, Carte* b) {
        return *a<*b;
    });
    }
Carte* Biblioteca::recomandaCarte(const Cititor& cititor) const {
    for (int i=0;i<carti.size();i++)
        if (carti[i]->getgen()==cititor.getGenPreferat())
            return carti[i];
    return nullptr;
    }
Carte* Biblioteca::CeaMaiPopularaPeGen(const std::string& gen) const {
    Carte* best=NULL;
    int scorMax=-1;

    for (int i =0;i<carti.size();i++) {
        if (carti[i]->getgen()==gen) { // verific daca e Thriller, Romance, sau Fantasy
            int scor=1;
            Thriller* t=dynamic_cast<Thriller*>(carti[i]); // fac conversie ca sa pot face metode din Thriller
            if (t != NULL) { //t=Thriller*
                if (t->eSuspansRidicat(5)) {
                    scor=10;
                }
                else {
                    scor=5;
                }
            }
            Romance* r=dynamic_cast<Romance*>(carti[i]);
            if (r!=NULL) {
                if (r->temaPozitiva())
                    scor=8;
                else
                    scor=4;
            }
            if (scor>scorMax) {
                scorMax=scor;
                best=carti[i];
            }
        }

    }
    return best;
}













