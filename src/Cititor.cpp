#include<string>
#include "Cititor.h"
#include "CititorExceptie.h"
Cititor::Cititor(const std::string& gen, int suspans, int impact):preferinteGen(gen) {
    if (gen.empty())
        throw CititorExceptie("Gen preferat invalid");
    if (suspans<0 || impact<0) throw CititorExceptie("Valori negative pentru suspans si impact");
}
