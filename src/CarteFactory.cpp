#include "CarteFactory.h"
Carte* CarteFactory::createCarte
    (const std::string& gen, const std::string& titlu, const std::string& autor,
        int an, int nivel,const std::string& extra,bool extraBool)
    {
        if (gen=="Fantasy")
            return new Fantasy(titlu,autor,an,nivel,extra);
        else if (gen=="Romance")
            return new Romance(titlu,autor,an,nivel,extra);
        else if (gen=="Thriller")
            return new Thriller(titlu,autor,an,nivel,extraBool);
        else if (gen=="ScienceFiction")
            return new ScienceFiction(titlu,autor,an,nivel);
        else return nullptr;
    }
