//
// Created by Envy on 20.12.2025.
//

#ifndef OOP_FANTASY_H
#define OOP_FANTASY_H
#include "Carte.h"
#include "Cititor.h"
class Fantasy: public Carte {
private:
    int nivelAventura;
    std::string lumeFictiva;
public:
    Fantasy(const std::string& t, const std::string& a, int an, int nivel, const std::string& lume);
    Fantasy(const Fantasy& o);

    Fantasy& operator=(const Fantasy& o);
    ~Fantasy();

    Carte* clone() const;
    int getnivelAventura() const {return nivelAventura; }

    std::string rezumatLume() const;
    int scorRecomandare (const Cititor& c) const;

    void Afisare(std::ostream& out) const;

};

#endif //OOP_FANTASY_H