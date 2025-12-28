#include<iostream>
#include<string>
#include<vector>

#include "Biblioteca.h"
#include "Carte.h"
#include "Fantasy.h"
#include "Romance.h"
#include "Thriller.h"
#include "StatisticiBiblioteca.h"
#include"ScienceFiction.h"

#include "BibliotecaExceptie.h"
#include "CarteExceptie.h"
#include "CititorExceptie.h"


int main() {


    try {
    Biblioteca b;


    Fantasy* f1=new Fantasy("Calea Regilor", "Brandon Sanderson", 2010, 9, "Roshar");
    Fantasy* f2=new Fantasy("Throne Of Glass", "Sarah J. Maas", 2012, 8, "Erilea" );
    Thriller* t1=new Thriller("The Naturals", "Jennifer Lynn Barnes", 2013, 9, true);
    Thriller* t2=new Thriller("The Silent Patient", "Alex Michaelides", 2019, 9, true);
    Romance* r1=new Romance ("Me Before You", "Jojo Moyes", 2012, 9, "iubire");
    Romance* r2= new Romance("The Notebook", "Nicholas Parks", 1996,8, "iertare");
    ScienceFiction* sf1=new ScienceFiction ("Dune", "Frank Herbert", 1965,9);
    ScienceFiction* sf2=new ScienceFiction ("The 100", "Kass Morgan", 2013, 7);

    b.adaugaCarte(f1);
    b.adaugaCarte(f2);
    b.adaugaCarte(t1);
    b.adaugaCarte(t2);
    b.adaugaCarte(r1);
    b.adaugaCarte(r2);
    b.adaugaCarte(sf1);
    b.adaugaCarte(sf2);

    std::cout<<"Numar total de carti: "<<Carte::getnrTotalCarti()<<std::endl;
    int scor=Biblioteca::scorStandard(5);
    std::cout<<"Scor standard pentru nivel 5:"<< scor<<std::endl;



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

    //cea mai populara carte pe  gen
    Carte* populara=b.CeaMaiPopularaPeGen("Thriller");
    if (populara!=nullptr)
        std::cout<<"Cea mai populara carte Thriller: "<<*populara<<std::endl;


    try {
        Cititor c("", -1,5);
    } catch (const CititorExceptie& e) {
        std::cout<<"Eroare cititor"<<e.what()<<std::endl;
    }

    try {
        Fantasy* f=new Fantasy ("", "Autor", 2020,5,"Lume");
    } catch (const CarteExceptie& e) {
        std::cout<<"Eroare carte: "<<e.what()<<std::endl;
    }

    delete f1;
    delete f2;
    delete t1;
    delete t2;
    delete r1;
    delete r2;
    delete sf1;
    delete sf2;
} catch (const std::exception& e) {
    std::cout<<"Exceptie: "<< e.what()<<std::endl;
}
    return 0;
}