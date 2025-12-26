//
// Created by Envy on 20.12.2025.
//
#include<string>
#ifndef OOP_CARTEEXCEPTION_H
#define OOP_CARTEEXCEPTION_H
class CarteException {
private:
    std::string mesaj;
public:
    CarteException(const std::string& m): mesaj(m){}
    std::string getMesaj() const {return mesaj;}
};
#endif //OOP_CARTEEXCEPTION_H