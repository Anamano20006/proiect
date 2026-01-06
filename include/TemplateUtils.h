#include<iostream>
#ifndef OOP_TEMPLATEUTILS_H
#define OOP_TEMPLATEUTILS_H
#include<vector>
template<typename T>
void afiseazaVector(const std::vector<T>& v) {
    for (const auto& x:v) {
        std::cout<<x<<std::endl;
    }
}
#endif //OOP_TEMPLATEUTILS_H