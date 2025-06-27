#include "C:\Users\Catalin\Documents\Lab2_OOP\domain\medicament.h"
#include "Validator.h"

int valideaza_cod(int cod) {
    return (cod >= 100 && cod <= 999);
}

int valideaza_concentratie(int concentratie) {
    return (concentratie>0);
}

int valideaza_cantitate(int cantitate) {
    return (cantitate>0);
}

int valideaza(Medicament medicament) {
    int nrErori = 0;

    int cod_de_validat, concentratie_de_validat, cantitate_de_validat;

    cod_de_validat = medicament.cod;
    concentratie_de_validat = medicament.concentratie;
    cantitate_de_validat = medicament.cantitate;

    if (!valideaza_cod(cod_de_validat)) nrErori++;
    if (!valideaza_concentratie(concentratie_de_validat)) nrErori++;
    if (!valideaza_cantitate(cantitate_de_validat)) nrErori++;

    return nrErori;
}

Validator creeaza_validator() {
    Validator validator;
    validator.valideaza_cod = &valideaza_cod;
    validator.valideaza_concentratie = &valideaza_concentratie;
    validator.valideaza_cantitate = &valideaza_cantitate;
    validator.valideaza = &valideaza;
    return validator;
}