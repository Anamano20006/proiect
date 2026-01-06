//
// Created by Envy on 27.12.2025.
//

#ifndef OOP_BIBLIOTECAEXCEPTIE_H
#define OOP_BIBLIOTECAEXCEPTIE_H



#include<exception>
#include<string>
class BibliotecaExceptie: public std::exception {
protected:
    std::string mesaj;
public:
    BibliotecaExceptie (const std::string& m):mesaj(m){}
    virtual const char* what() const noexcept {return mesaj.c_str();}
};


#endif //OOP_BIBLIOTECAEXCEPTIE_H