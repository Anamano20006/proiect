#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<fstream>

#include "Biblioteca.h"
#include "Carte.h"
#include "Fantasy.h"
#include "Romance.h"
#include "Thriller.h"
#include "StatisticiBiblioteca.h"
#include"ScienceFiction.h"
#include "CarteFactory.h"
#include"Recomandari.h"
#include "RecomandariPointer.h"
#include "TemplateUtils.h"


#include "BibliotecaExceptie.h"
#include "CarteExceptie.h"
#include "CititorExceptie.h"


int main() {



    Biblioteca b;

    try {
        std::ifstream fin("carti.txt");
        if (!fin.is_open()) {
            throw BibliotecaExceptie("Nu s-a putut deschide carti.txt");
        }
        std::string linie;
        while (std::getline(fin,linie)) {
            std::istringstream iss(linie);
            std::string gen,titlu,autor,extra, anStr,nivelStr,temp;
            int an=0, nivel=0;
            bool extraBool=false;

            std::getline(iss,gen,';');
            std::getline(iss,titlu, ';');
            std::getline(iss,autor,';');
            std::getline(iss, anStr,';');
            std::getline(iss,nivelStr, ';');

            std::istringstream (anStr)>>an;
            std::istringstream (nivelStr)>>nivel;



            if (gen=="Fantasy" || gen=="Romance") {
                std::getline(iss,extra,';');
            }
            else if (gen=="Thriller") {
                std::getline(iss,extra,';');
                std::getline(iss,temp,';');
                extraBool=(temp=="1");
            }

            Carte* c=CarteFactory::createCarte(gen,titlu,autor,an,nivel, extra, extraBool);
            if (c)
                b.adaugaCarte(c);
        }
        fin.close();

        std::cout<<"Toate cartile au fost citite din fisier: "<<std::endl;
        b.afiseazaCarte(std::cout);
    } catch (const std::exception& e) {
        std::cout<<"A aparut o problema la citire: "<<e.what()<<std::endl;
    }



    int optiune;
    do {
        std::cout<<"===Biblioteca Interactiva==="<<std::endl;
        std::cout<<"1. Afiseaza toate cartile"<<std::endl;
        std::cout<<"2.Recomanda carte dupa gen"<<std::endl;
        std::cout<<"3.Afiseaza statistici biblioteca"<< std::endl;
        std::cout<<"4.Cea mai populara carte pe Gen"<<std::endl;

        std::cout<<"0.Iesire"<<std::endl;
        std::cin>>optiune;
        if (optiune==1) {
            b.afiseazaCarte(std::cout);
        }
        else if (optiune==2) {
            Cititor c("",0,0);
            std::cout<<"Introduceti datele cititorului: "<<std::endl;
            std::cin>>c;

            std::string genCautat=c.preferintaGen();



            std::vector<Carte*> cartiGen;
            for (auto c:b.getCarti()) {
                if (c->getgen()==genCautat)
                    cartiGen.push_back(c);
            }
            if (cartiGen.empty()) {
                std::cout<<"Nu exista carti pentru genul "<<genCautat<<std::endl;
            }else {
                std::string raspuns;
                if (genCautat=="Fantasy") {
                    std::cout<<"Vrei aventura intensa? (da/nu) ";
                    std::cin>>raspuns;
                }
                else if (genCautat=="Thriller") {
                    std::cout<<"Vrei suspans ridicat?(da/nu): ";
                    std::cin>>raspuns;
                }
                else if (genCautat=="Romance") {
                    std::cout<< "Preferi o tema pozitiva? (da/nu): ";
                    std::cin>>raspuns;
                }
                else if (genCautat=="ScienceFiction") {
                    std::cout<< "Vrei complexitate mare? (da/nu): ";
                    std::cin>>raspuns;
                }


                if (raspuns=="da")
                    std::cout<<"recomandare: "<<*cartiGen[0]<<std::endl;
                else {
                    if (cartiGen.size()>1)
                        std::cout<<"recomandare: "<<*cartiGen[1]<<std::endl;
                    else
                        std::cout<<"recomandare: "<<*cartiGen[0]<<std::endl;
                }
            }
            Cititor tempCititor(genCautat,5,5);
            Carte* recAutomata=b.recomandaCarte(tempCititor);
            if (recAutomata)
                std::cout<<"(Sistemul automat sugereaza si: "<<recAutomata->getgen()<<" - "<<")" <<std::endl;

        }
        else if (optiune==3) {
            b.afiseazaStatistici();
        }
        else if (optiune==4) {
            std::string gen;
            std::cout<<"Introdu genul pentru care vrei cea mai populara carte: ";
            std::cin>>gen;

            Carte* populara=b.CeaMaiPopularaPeGen(gen);
            if (populara!=nullptr)
                std::cout<<"Cea mai populara carte: "<<gen<<": "<<*populara<<std::endl;
            else
                std::cout<<"Nu exista carti pentru "<<gen<<std::endl;
        }
    }while (optiune!=0);


    std::cout<<"Genul cel mai reprezentat: "<<StatisticiBiblioteca::getInstance().genCelMaiReprezentat()<<std::endl;

    if (true) {
        try {
            Cititor c("", -1,5);
        } catch (const CititorExceptie& e) {
            std::cout<<"Eroare cititor"<<e.what()<<std::endl;
        }

        try {
            delete new Fantasy ("", "Autor", 2020,5,"Lume");

        } catch (const CarteExceptie& e) {
            std::cout<<"Eroare carte: "<<e.what()<<std::endl;
        }

        Fantasy* f1=new Fantasy("Calea regilor", "Brandon Sanderson",2010,9,"Roshar");
        Thriller* t1=new Thriller("The Naturals", "Jennifer Lynn Barnes", 2013,9, true);
        Romance* r1=new Romance("Me Before You", "Jojo Moyes", 2012,9, "iubire");


        Recomandari<std::string> recomandariGenuri;
        recomandariGenuri.adauga("Fantasy");
        recomandariGenuri.adauga("ScienceFiction");

        RecomandariPointer<Carte> recomandariCarti;
        recomandariCarti.adauga(f1);
        recomandariCarti.adauga(t1);

        std::cout<<"Genuri recomandate"<<std::endl;
        recomandariGenuri.afiseaza();

        std::cout<<"Carti recomandate"<<std::endl;
        recomandariCarti.afiseaza();


        std::vector<std::string> genuri={"Fantasy","Romance", "ScienceFiction"};
        std::vector<int> scoruri={5,8,10};
        std::cout<<"genuri: "<<std::endl;
        afiseazaVector(genuri);
        std::cout<<"scoruri: "<<std::endl;
        afiseazaVector(scoruri);

        if (Fantasy* f=dynamic_cast<Fantasy*>(f1))
        std::cout<< f->rezumatLume() <<std::endl;
        if (Thriller* t=dynamic_cast<Thriller*>(t1))
            if (t->eSuspansRidicat(7))
                std::cout<<"Thriller foarte intens"<<std::endl;
        if (Romance* r=dynamic_cast<Romance*>(r1))
            if (r->temaPozitiva())
                std::cout<<"Romance cu tema pozitiva"<<std::endl;
        std::cout<<"Numar total de carti: "<<Carte::getnrTotalCarti()<<std::endl;
        std::cout<<"Scor standard pentru nivel 5:"<< Biblioteca::scorStandard(5)<<std::endl;

        delete f1;
        delete t1;
        delete r1;


    }
    return 0;
}