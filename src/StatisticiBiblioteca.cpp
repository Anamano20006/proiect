//
// Created by Envy on 22.12.2025.
//
#include<iostream>
#include<map>
#include<string>
#include "StatisticiBiblioteca.h"

void StatisticiBiblioteca::actualizeaza(const std::vector<Carte*>& carti) {
    nrCartiPeGen.clear();  //ce face clear??
    for (int i=0;i<carti.size();i++) {
        std::string g=carti[i]->getgen();
        nrCartiPeGen[g]++;
    }
}

void StatisticiBiblioteca::afiseazaStatistici() const {
    std::cout<<"StatisticiBiblioteca"<<std::endl;
    for (std::map<std::string,int>::const_iterator it =nrCartiPeGen.begin();it!=nrCartiPeGen.end(); it++) {
        std::cout<<"Gen: "<<it->first<<", numar carti: "<<it->second<<std::endl;
    }
}

int StatisticiBiblioteca::getNrCartiGen(const std::string& gen) const {
    std::map<std::string,int>::const_iterator it=nrCartiPeGen.find(gen);
    if (it!=nrCartiPeGen.end())
        return it->second;
    return 0;
}


std::string StatisticiBiblioteca::genCelMaiReprezentat() const {
    std::string genMax="";
    int maxim=0;
    for (std::map<std::string,int>::const_iterator it=nrCartiPeGen.begin(); it!=nrCartiPeGen.end(); ++it) {

        if (it->second>maxim) {
            maxim=it->second;
            genMax=it->first;
        }
    }
        return genMax;
}











