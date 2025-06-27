#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Produs {
private:
    string nume;
    string tip;
    int pret;
    string producator;
    int id;
public:
    Produs() = default;
    string getNume() const;
    string getTip() const;
    int getPret() const;
    string getProducator() const;
    int getId() const;

    void setNume(const string& nume_nou);
    void setTip(const string& tip_nou);
    void setPret(const int& pret_nou);
    void setProducator(const string& producator_nou);

    Produs(string nume, int pret, string tip, string producator, int id) : nume{ nume }, pret { pret }, tip { tip }, producator { producator }, id { id } {

    }

    //copie
    Produs(const Produs& other) : nume { other.nume }, pret { other.pret }, tip { other.tip }, producator { other.producator }, id { other.id } {
    }

    //destructor
    ~Produs() {}

    bool operator==(const Produs& ot) const;
};

#endif //PRODUS_H
