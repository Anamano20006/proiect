//
// Created by Envy on 20.12.2025.
//

#ifndef OOP_THRILLER_H
#define OOP_THRILLER_H
#include "Carte.h"

class Thriller:public Carte {
private:
    int nivelSuspans;
    bool rezolvareMister;
public:

    Thriller(const std::string& t, const std::string& a, int an, int nS,bool rM );
    Thriller(const Thriller& o);
    ~Thriller();
    Thriller& operator=(const Thriller& o);
    void Afisare(std::ostream& out) const;
    int CalculSuspans() const;
    bool eSuspansRidicat(int prag) const;
    int scorRecomandare(const Cititor& c) const;
    Carte* clone() const;
};


#endif //OOP_THRILLER_H