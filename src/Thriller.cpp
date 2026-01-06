//
// Created by Envy on 20.12.2025.
//
#include "Thriller.h"

Thriller::Thriller(const std::string& t, const std::string& a, int an, int nS, bool rM)
: Carte(t,a,an, "Thriller"), nivelSuspans(nS), rezolvareMister(rM){}

Thriller::Thriller(const Thriller& o):Carte(o),nivelSuspans(o.nivelSuspans),rezolvareMister(o.rezolvareMister){}

Thriller& Thriller::operator=(const Thriller& o) {
    if (this!=&o) {
        Carte::operator=(o);
        nivelSuspans=o.nivelSuspans;
        rezolvareMister=o.rezolvareMister;
    }
    return *this;

}

Thriller::~Thriller() {}


void Thriller::Afisare(std::ostream& out) const {
    out<<"Thriller |"<<titlu<<" - "<<autor<<" ("<<anAparitie<<") "<<"nivel suspans: "<<nivelSuspans<<",Rezolvare Mister: ";
    if (rezolvareMister)
        out<<"da";
    else
        out<<"nu";
}
bool Thriller::eSuspansRidicat(int prag) const {
    int scor=nivelSuspans;
    if (rezolvareMister)
        scor=scor+2;
    if (scor>=prag)
        return true;
    else
        return false;
}

int Thriller::scorRecomandare(const Cititor& c) const {
    int scor=0;
    if (c.preferintaGen()=="Thriller")
        scor+=5;
    scor+=nivelSuspans;
    if (rezolvareMister)
        scor+=2;
    return scor;
}


Carte* Thriller::clone() const {
    return new Thriller(*this);
}