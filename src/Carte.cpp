#include "Carte.h"
#include"CarteExceptie.h"
#include<stdexcept>
int Carte::nrTotalCarti=0;
Carte::Carte(): titlu(""), autor(""), anAparitie(0), gen(""){ nrTotalCarti++;}
Carte::Carte(const std::string& t, const std:: string& a,int an, const std::string& g):
    titlu(t),autor(a),anAparitie(an), gen(g) {
    nrTotalCarti++;
    if (titlu.empty())
        throw CarteExceptie("Titlu invalid");
    if (an< 1450)
        throw CarteExceptie("An de aparitie invalid");

}
Carte::Carte(const Carte& o): titlu(o.titlu), autor(o.autor),anAparitie(o.anAparitie), gen(o.gen) {
}
Carte& Carte::operator=(const Carte& o) {
    if (this != &o) {
        titlu=o.titlu;
        autor=o.autor;
        anAparitie=o.anAparitie;
        gen=o.gen;
    }
    return *this;
}
std::string Carte::getgen()const {
    return gen;
}
Carte::~Carte() {
    nrTotalCarti--;
}

bool Carte::operator<(const Carte& o) const {
    return titlu<o.titlu;
}
std::ostream& operator<<(std::ostream& out, const Carte& c) {
    c.Afisare(out);
    return out;
}