#include"ScienceFiction.h"
#include "Cititor.h"
#include "CarteExceptie.h"
#include<iostream>

ScienceFiction::ScienceFiction(const std::string& titlu, const std::string& autor, int an, int nivelTehnologie)
: Carte(titlu,autor,an,"ScienceFiction"),nivelTehnologie(nivelTehnologie) {}
ScienceFiction::ScienceFiction(const ScienceFiction& o):Carte(o), nivelTehnologie(o.nivelTehnologie){}
ScienceFiction& ScienceFiction::operator=(const ScienceFiction& o){
    if (this != &o) {
        Carte::operator=(o);
        nivelTehnologie=o.nivelTehnologie;
    }
    return *this;
}
ScienceFiction::~ScienceFiction() {}


Carte* ScienceFiction::clone() const {
    return new ScienceFiction(*this);
}

int ScienceFiction::scorRecomandare(const Cititor& c) const {
    int scor=0;
    if (c.preferintaGen()=="ScienceFiction")
        scor+=10;
    scor+=nivelTehnologie;
    return scor;
}

void ScienceFiction::Afisare(std::ostream& out) const {
    out<<"ScienceFiction | "<<titlu<<" - "<<autor<<" ("<<anAparitie<<") "<<"Nivel tehnologie: "<<nivelTehnologie;
}



