

#ifndef OOP_CARTEFACTORY_H
#define OOP_CARTEFACTORY_H
#include "Carte.h"
#include "Fantasy.h"
#include "Romance.h"
#include "Thriller.h"
#include "ScienceFiction.h"
#include<string>

class CarteFactory {
public:
    static Carte* createCarte
    (const std::string& gen, const std::string& titlu, const std::string& autor,
        int an, int nivel,const std::string& extra="",bool extraBool = false);
};

#endif //OOP_CARTEFACTORY_H