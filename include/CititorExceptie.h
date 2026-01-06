#include "BibliotecaExceptie.h"
#ifndef OOP_CITITOREXCEPTIE_H
#define OOP_CITITOREXCEPTIE_H
class CititorExceptie: public BibliotecaExceptie {
public:
    CititorExceptie(const std::string& m):BibliotecaExceptie(m){}
};


#endif //OOP_CITITOREXCEPTIE_H