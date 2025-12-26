#include "Fantasy.h"

Fantasy::Fantasy(const std::string& t, const std::string& a, int an, int nivel, const std::string& lume):
    Carte(t,a,an,"Fantasy"),nivelAventura(nivel), lumeFictiva(lume){}
Fantasy::Fantasy(const Fantasy& o):Carte(o), nivelAventura(o.nivelAventura),lumeFictiva(o.lumeFictiva){}
Fantasy& Fantasy::operator=(const Fantasy& o) {
    if (this!=&o) {
        Carte::operator=(o);
        nivelAventura=o.nivelAventura;
        lumeFictiva=o.lumeFictiva;
    }
    return *this;
}
Fantasy::~Fantasy() {}

std::string Fantasy::rezumatLume() const {
    std::string text="In cartea ";
    text=text+titlu;
    text=text+", aventura se desfasoara in lumea ";
    text=text+lumeFictiva;
    text=text+" cu un nivel de aventura ";
    text=text+std::to_string(nivelAventura);
    return text;
}

void Fantasy::Afisare(std::ostream& out) const {
    out<<"Fantasy |"<<titlu<<" - "<<autor<<" ("<<anAparitie<<") "<<"Aventura: "<<nivelAventura<<", lume: "<<lumeFictiva;
}
