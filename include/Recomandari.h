//
// Created by Envy on 28.12.2025.
//

#ifndef OOP_RECOMANDARI_H
#define OOP_RECOMANDARI_H
#include<vector>
#include<iostream>

template<typename T>
class Recomandari {
    private: std::vector<T> elemente;
public:
    void adauga(const T& elem) {
        elemente.push_back(elem);
    }
    void afiseaza() const {
        for ( auto e :elemente)
            std::cout<<e<<std::endl;
    }
};

#endif //OOP_RECOMANDARI_H