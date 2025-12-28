
#include"Biblioteca.h"
#include "Romance.h"
#include "Thriller.h"
#include "Fantasy.h"
#include<algorithm>
Biblioteca::Biblioteca() {
    for (auto c: carti ) {
        delete c;
    }
}


Biblioteca::Biblioteca(const Biblioteca& o) {
    for (auto c:o.getCarti()) {
        carti.push_back(c->clone());
    }
    statistici.actualizeaza(carti);

}


Biblioteca& Biblioteca::operator=(Biblioteca o)
{
    swap(o);
    return *this;
}

Biblioteca::~Biblioteca() {
    for (auto c:carti)
        delete c;
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
    Carte* best=nullptr;
    int scorMax=-1;

    for (size_t i=0;i<carti.size();++i){
    int scor=carti[i]->scorRecomandare(cititor);
    if (scor> scorMax) {
        scorMax=scor;
        best=carti[i];
    }
}
    return best;
    }


Carte* Biblioteca::CeaMaiPopularaPeGen(const std::string& gen) const {
    Carte* best=nullptr;
    int scorMax=-1;

    for (auto c:carti) {
        if (c->getgen()==gen) { // verific daca e Thriller, Romance, sau Fantasy
            int scor=1;

            if (Thriller* t=dynamic_cast<Thriller*>(c)) // fac conversie ca sa pot face metode din Thriller
                if (t != nullptr) { //t=Thriller*
                    if (t->eSuspansRidicat(5)) {
                        scor=10;
                    }
                    else {
                        scor=5;
                    }
                }
            else if (Romance* r=dynamic_cast<Romance*>(c))
                if (r!=nullptr) {
                    if (r->temaPozitiva())
                        scor=8;
                    else
                        scor=4;
                }
            else if (Fantasy* f=dynamic_cast<Fantasy*>(c))
                if (f!=nullptr) {
                    if (f->getnivelAventura()>=7)
                        scor=9;
                    else
                        scor=6;
                }
            if (scor>scorMax) {
                scorMax=scor;
                best=c;
            }
        }

    }
    return best;
}












