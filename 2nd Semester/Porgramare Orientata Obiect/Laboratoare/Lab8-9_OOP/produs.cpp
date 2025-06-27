#include "produs.h"

string Produs::getNume() const {
    return nume;
}

int Produs::getPret() const {
    return pret;
}

string Produs::getTip() const {
    return tip;
}

string Produs::getProducator() const {
    return producator;
}

int Produs::getId() const {
    return id;
}

void Produs::setNume(const string& nume_nou) {
    nume = nume_nou;
}

void Produs::setTip(const string& tip_nou) {
    tip = tip_nou;
}

void Produs::setPret(const int& pret_nou) {
    pret = pret_nou;
}

void Produs::setProducator(const string& producator_nou) {
    producator = producator_nou;
}

bool Produs::operator==(const Produs& ot) const {
    return id == ot.id;;
}
