

#ifndef OOP_CITITOR_H
#define OOP_CITITOR_H
#include<string>
class Cititor {
private:
    std::string preferinteGen;

public:
    Cititor(const std::string& gen, int suspans, int impact);
    std::string preferintaGen() const {return preferinteGen;}

};

#endif //OOP_CITITOR_H