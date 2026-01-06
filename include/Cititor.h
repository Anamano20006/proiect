

#ifndef OOP_CITITOR_H
#define OOP_CITITOR_H
#include<string>
class Cititor {
private:
    std::string preferinteGen;
    int suspansDorit;
    int impactEmotionalDorit;

public:
    Cititor(const std::string& gen, int suspans, int impact);
    std::string preferintaGen() const {return preferinteGen;}

    friend std::istream& operator>>(std::istream& in, Cititor& c);

    friend std::ostream& operator<<(std::ostream& out, const Cititor& c);

};

#endif //OOP_CITITOR_H