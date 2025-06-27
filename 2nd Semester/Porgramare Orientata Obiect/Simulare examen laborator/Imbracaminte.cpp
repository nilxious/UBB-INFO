//
// Created by Catalin on 5/23/2025.
//

#include "Imbracaminte.h"

Imbracaminte::Imbracaminte(int cod, const string& categorie, const string& brand, const string& marime): cod(cod), categorie(categorie), brand(brand), marime(marime) {}

int Imbracaminte::getCod() const {
    return cod;
}

const string& Imbracaminte::getCategorie() const {
    return categorie;
}

const string& Imbracaminte::getBrand() const {
    return brand;
}

const string& Imbracaminte::getMarime() const {
    return marime;
}

bool Imbracaminte::operator==(const Imbracaminte &ot) const {
    return cod == ot.cod && categorie==ot.categorie && brand == ot.brand && marime == ot.marime;
}