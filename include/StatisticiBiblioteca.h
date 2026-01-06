//
// Created by Envy on 22.12.2025.
//

#ifndef OOP_STATISTICIBIBLIOTECA_H
#define OOP_STATISTICIBIBLIOTECA_H
#include <map>
#include<string>
#include<vector>
#include "Carte.h"
class StatisticiBiblioteca {
private:
    std::map<std::string, int> nrCartiPeGen;
    StatisticiBiblioteca(){}
public:
    StatisticiBiblioteca(const StatisticiBiblioteca&)=delete;
    StatisticiBiblioteca& operator=(const StatisticiBiblioteca&)=delete;
    static StatisticiBiblioteca& getInstance() {
        static StatisticiBiblioteca instance;
        return instance;
    }



    void actualizeaza(const std::vector<Carte*>& carti);
    void afiseazaStatistici() const;
    int getNrCartiGen(const std::string& gen) const;
    std::string genCelMaiReprezentat() const;
};
#endif //OOP_STATISTICIBIBLIOTECA_H