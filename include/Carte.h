//
// Created by Envy on 20.12.2025.
//

#ifndef OOP_CARTE_H
#define OOP_CARTE_H
#include<string>
#include<iostream>
class Carte {
protected:
    std::string titlu;
    std::string autor;
    int anAparitie;
    std::string gen;
public:
    Carte();
    Carte(const  std::string&t, const std::string& a, int an, const std::string& g);
    Carte(const Carte& o);


    Carte& operator=(const Carte& o);
    virtual ~Carte();

    std::string getgen() const;

    virtual void Afisare(std::ostream& out) const=0;
    bool operator<(const Carte& o) const;
};
std::ostream& operator<<(std::ostream& out, const Carte& c);


#endif //OOP_CARTE_H
