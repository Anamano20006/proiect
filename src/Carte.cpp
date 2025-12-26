#include "Carte.h"
#include<stdexcept>
Carte::Carte(): titlu(""), autor(""), anAparitie(0), gen(""){}
Carte::Carte(const std::string& t, const std:: string& a,int an, const std::string& g):
    titlu(t),autor(a),anAparitie(an), gen(g) {
    if (titlu.empty())
        throw CarteException("Titlu invalid");
    if (an< 1450)
        throw CarteException("An de aparitie invalid");
}
Carte::Carte(const Carte& o): titlu(o.titlu), autor(o.autor),anAparitie(o.anAparitie), gen(o.gen) {}
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
Carte::~Carte()=default;

bool Carte::operator<(const Carte& o) const {
    return titlu<o.titlu;
}
std::ostream& operator<<(std::ostream& out, const Carte& c) {
    c.Afisare(out);
    return out;
}