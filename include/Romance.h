//
// Created by Envy on 20.12.2025.
//

#ifndef OOP_ROMANCE_H
#define OOP_ROMANCE_H
#include "Carte.h"
#include "Cititor.h"
class Romance: public Carte {
private:
    int impactEmotional;
    std::string temaMorala;
public:
    Romance(const std::string& t, const std::string& a, int an, int iE, const std::string& tM );
    Romance(const Romance& o);
    ~Romance();
    Romance& operator=(const Romance& o);

    bool temaPozitiva() const;
    int scorRecomandare (const Cititor& c) const;
    void Afisare(std::ostream& out) const;

    Carte* clone() const;
};

#endif //OOP_ROMANCE_H