//
// Created by Envy on 29.12.2025.
//

#ifndef OOP_RECOMANDARIPOINTER_H
#define OOP_RECOMANDARIPOINTER_H

template<typename T>
class RecomandariPointer {
private: std::vector<T*> elemente;
public:
    void adauga( T* elem) {
        elemente.push_back(elem);
    }
    void afiseaza() const {
        for ( auto e :elemente)
            std::cout<<*e<<std::endl;
    }
};
#endif //OOP_RECOMANDARIPOINTER_H