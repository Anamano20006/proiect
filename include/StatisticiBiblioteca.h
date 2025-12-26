//
// Created by Envy on 22.12.2025.
//

#ifndef OOP_STATISTICIBIBLIOTECA_H
#define OOP_STATISTICIBIBLIOTECA_H
#include <map>
#include<string>
#include<vector>
#include "Carte.h"
class StatisticiBiblioteca {//ce face statisticiBiblioteca?
private:
    std::map<std::string, int> nrCartiPeGen;//ce face map<string,int>?
public:
    StatisticiBiblioteca();
    void actualizeaza(const std::vector<Carte*>& carti);
    void afiseazaStatistici() const;
    int getNrCartiGen(const std::string& gen) const; //de ce am int aici?de ce imi trebuie si nr de carti pt genul dat
    std::string genCelMaiReprezentat() const;
};
#endif //OOP_STATISTICIBIBLIOTECA_H