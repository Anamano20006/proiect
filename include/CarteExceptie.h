#include "BibliotecaExceptie.h"
#ifndef OOP_CARTEEXCEPTIE_H
#define OOP_CARTEEXCEPTIE_H
class CarteExceptie: public BibliotecaExceptie {
    public:
    CarteExceptie(const std::string& m):BibliotecaExceptie(m){}
};

#endif //OOP_CARTEEXCEPTIE_H