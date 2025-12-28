

#ifndef OOP_SCIENCEFICTION_H
#define OOP_SCIENCEFICTION_H

#include "Carte.h"
#include "Cititor.h"
#include<iostream>

class ScienceFiction: public Carte {
private:
    int nivelTehnologie;
public:
    ScienceFiction (const std::string& titlu, const std::string& autor, int an, int nivelTehnologie);
    ScienceFiction(const ScienceFiction& o);
    ScienceFiction& operator=(const ScienceFiction& o);
    ~ScienceFiction();

    Carte* clone() const;
    int scorRecomandare(const Cititor& c) const;
    void Afisare(std::ostream& out) const;
};

#endif //OOP_SCIENCEFICTION_H