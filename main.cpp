#include<iostream>
#include<string>
#include<vector>

#include "Biblioteca.h"
#include "Carte.h"
#include "Fantasy.h"
#include "Romance.h"
#include "Thriller.h"
#include "StatisticiBiblioteca.h"


int main(){
    Biblioteca b;

    Fantasy* f1=new Fantasy("Calea Regilor", "Brandon Sanderson", 2010, 9, "Roshar");
    Fantasy* f2=new Fantasy("Throne Of Glass", "Sarah J. Maas", 2012, 8, "Erilea" );
    Thriller* t1=new Thriller("The Naturals", "Jennifer Lynn Barnes", 2013, 9, true);
    Thriller* t2=new Thriller("The Silent Patient", "Alex Michaelides", 2019, 9, true);
    Romance* r1=new Romance ("Me Before You", "Jojo Moyes", 2012, 9, "iubire");
    Romance* r2= new Romance("The Notebook", "Nicholas Parks", 1996,8, "iertare");

    b.adaugaCarte(f1);
    b.adaugaCarte(f2);
    b.adaugaCarte(t1);
    b.adaugaCarte(t2);
    b.adaugaCarte(r1);
    b.adaugaCarte(r2);

    StatisticiBiblioteca sb;
    sb.actualizeaza(b.getCarti());
    //recomand carte dupa gen
    std::string genCautat;
    std::cout<<"Introdu genul de carte preferat: ";
    std::cin>>genCautat;

    Carte* recomandata = b.recomandaCarte(Cititor(genCautat,0,0)); //creez cartea recomandata bazata pe preferinta cititorului
    //returneaza un pointer la prima carte pe genul resp sau nullptr daca nu exista

    if (recomandata!=nullptr)
        std::cout<<"Recomandare: "<< *recomandata<< std::endl;
    else
        std::cout<<"Nu avem carti pentru genul "<<genCautat<<std::endl;



    sb.afiseazaStatistici();
    std::cout<<"cel mai reprezentat Gen: "<<sb.genCelMaiReprezentat()<<std::endl;


    std::cout<< f1->rezumatLume() <<std::endl;
    if (t1->eSuspansRidicat(7))
        std::cout<<"Thriller foarte intens"<<std::endl;
    if (r1->temaPozitiva())
        std::cout<<"Romance cu tema pozitiva"<<std::endl;

    Carte* populara=b.CeaMaiPopularaPeGen("Thriller");
    if (populara!=nullptr)
        std::cout<<"Cea mai populara carte Thriller: "<<*populara<<std::endl;

    b.afiseazaStatistici();

    delete f1;
    delete f2;
    delete t1;
    delete t2;
    delete r1;
    delete r2;
}