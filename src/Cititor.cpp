#include<string>
#include<iostream>
#include "Cititor.h"
#include "CititorExceptie.h"
Cititor::Cititor(const std::string& gen, int suspans, int impact):preferinteGen(gen), suspansDorit(suspans), impactEmotionalDorit(impact) {
    if (gen.empty())
        throw CititorExceptie("Gen preferat invalid");
    if (suspans<0 || impact<0) throw CititorExceptie("Valori negative pentru suspans si impact");
}
std::istream& operator>>(std::istream& in,Cititor& c) {
    std::cout<<"Gen Preferat: ";
    in>>c.preferinteGen;
    std::cout<<"Nivel Suspans(1-10): ";
    in>>c.suspansDorit;
    std::cout<<"Impact emotional(1-10): ";
    in>>c.impactEmotionalDorit;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Cititor& c) {
    out<<"Cititorul prefera: "<<c.preferinteGen<<"(Suspans: "<<c.suspansDorit<<", Impact: "<<c.impactEmotionalDorit<<")";
    return out;
}
