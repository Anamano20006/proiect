//
// Created by Envy on 20.12.2025.
//

#ifndef OOP_CARTE_H
#define OOP_CARTE_H
#include<string>
#include<iostream>
#include "Cititor.h"
class Carte {
protected:
    std::string titlu;
    std::string autor;
    int anAparitie;
    std::string gen;
    int rating;
    static int nrTotalCarti;
public:
    Carte();
    Carte(const  std::string&t, const std::string& a, int an, const std::string& g);
    Carte(const Carte& o);


    Carte& operator=(const Carte& o);
    virtual ~Carte();

    virtual Carte* clone() const=0;


    std::string getgen() const;
    static int getnrTotalCarti() {return nrTotalCarti;}


    virtual void Afisare(std::ostream& out) const=0;
    bool operator<(const Carte& o) const;
    virtual int scorRecomandare(const Cititor& c) const=0;

};
std::ostream& operator<<(std::ostream& out, const Carte& c);


#endif //OOP_CARTE_H
