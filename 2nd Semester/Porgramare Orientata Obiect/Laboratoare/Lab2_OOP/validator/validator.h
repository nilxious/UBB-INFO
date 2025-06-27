#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "C:\Users\Catalin\Documents\Lab2_OOP\domain\medicament.h"

/**
 * Structura Validator ce contine functii pentru validarea unui medicament.
 */
typedef struct {
    int (*valideaza_cod)(int);
    int (*valideaza_concentratie)(int);
    int (*valideaza_cantitate)(int);
    int (*valideaza)(Medicament);
}Validator;

/**
 * Creeaza un validator.
 * @return Un obiect de tip Validator initializat.
 */
Validator creeaza_validator();

/**
 * Verifica daca un cod de medicament este valid.
 * @param cod Codul medicamentului, tip int.
 * @return 1 daca codul este valid, 0 in caz contrar.
 */
int valideaza_cod(int cod);

/**
 * Verifica daca o concentratie de medicament este valida.
 * @param concentratie Concentratia medicamentului, tip int.
 * @return 1 daca concentratia este valida, 0 in caz contrar.
 */
int valideaza_concentratie(int concentratie);

/**
 * Verifica daca o cantitate de medicament este valida.
 * @param cantitate Cantitatea medicamentului, tip int.
 * @return 1 daca cantitatea este valida, 0 in caz contrar.
 */
int valideaza_cantitate(int cantitate);

/**
 * Valideaza un medicament verificand codul, concentratia si cantitatea acestuia.
 * @param medicament Medicamentul de validat, tip Medicament.
 * @return Numarul de erori gasite (0 daca medicamentul este valid).
 */
int valideaza(Medicament medicament);

#endif // VALIDATOR_H