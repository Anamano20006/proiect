#include "Romance.h"

Romance::Romance(const std::string& t, const std::string& a, int an, int iE, const std::string& tM)
: Carte(t,a,an, "Romance"), impactEmotional(iE), temaMorala(tM){}

Romance::Romance(const Romance& o):Carte(o), impactEmotional(o.impactEmotional),temaMorala(o.temaMorala){}
Romance& Romance::operator=(const Romance& o) {
    if (this!=&o) {
        Carte::operator=(o);
        impactEmotional=o.impactEmotional;
        temaMorala=o.temaMorala;
    }
    return *this;
}
Romance::~Romance(){}

bool Romance::temaPozitiva() const {
    if (temaMorala=="iertarea")
        return true;
    if (temaMorala=="prietenie")
        return true;
    if (temaMorala=="iubire")
        return true;
    return false;
}

int Romance::scorRecomandare(const Cititor&  c) const {
    int scor=0;
    if (c.preferintaGen()=="Romance")
        scor+=5;
    scor+=impactEmotional;
    return scor;

}

void Romance::Afisare(std::ostream& out) const {
    out<<"Romance |"<<titlu<<" - "<<autor<<" ("<<anAparitie<<") "<<"impact Emotional: "<<impactEmotional<<", tema Morala: "<<temaMorala;
}


Carte* Romance::clone() const {
    return new Romance(*this);
}


