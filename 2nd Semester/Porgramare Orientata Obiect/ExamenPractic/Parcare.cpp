#include "Parcare.h"

Parcare::Parcare(string adresa, int linii, int coloane, string stare)
    : adresa { adresa }, linii { linii }, coloane { coloane }, stare { stare } {}

string Parcare::getAdresa() const {
    return adresa;
} 

int Parcare::getLinii() const {
    return linii;
} 

int Parcare::getColoane() const {
    return coloane;
} 

string Parcare::getStare() const {
    return stare;
} 

void Parcare::setColoane(int nou) {
    coloane = nou;
} 

void Parcare::setLinii(int nou) {
    linii = nou;
} 

void Parcare::setStarea(string nou) {
    stare = nou;
} 
