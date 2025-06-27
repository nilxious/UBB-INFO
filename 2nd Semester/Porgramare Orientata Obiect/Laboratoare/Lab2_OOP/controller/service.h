#ifndef SERVICE_H
#define SERVICE_H

#include "C:\Users\Catalin\Documents\Lab2_OOP\repository\repository.h"
#include "C:\Users\Catalin\Documents\Lab2_OOP\validator\validator.h"

/**
 * Structura Service ce conține un repository și un validator.
 */
typedef struct {
    Repository* repo;
    Validator* validator;
}Service;

/**
 * Creeaza un nou service.
 * @param repo Repository-ul care va fi folosit de service, tip Repository*.
 * @param validator Validatorul pentru validarea medicamentelor, tip Validator*.
 * @return Un obiect de tip Service.
 */
Service creeaza_service(Repository* repo, Validator* validator);

/**
 * Adauga un medicament în repository.
 * @param service Service-ul care gestioneaza medicamentele tip Service*.
 * @param cod Codul medicamentului, tip int.
 * @param nume Numele medicamentului, tip char[20].
 * @param concentratie Concentrația medicamentului, tip int.
 * @param cantitate Cantitatea disponibilă, tip int.
 * @return 1 sau 2 dacă adăugarea a fost reușită, altfel un cod de eroare.
 */
int add_medicament(Service* service, int cod, char nume[20], int concentratie, int cantitate);

/**
 * Modifica un medicament existent in repository.
 * @param service Service-ul care gestioneaza medicamentele, tip Service*.
 * @param cod Codul medicamentului de modificat, tip int.
 * @param nume Noul nume al medicamentului, tip char[20].
 * @param concentratie Noua concentratie a medicamentului, tip int.
 * @param cantitate Noua cantitate disponibila, tip int.
 * @return 1 daca modificarea a fost reusita, altfel un cod de eroare.
 */
int modify_medicament(Service* service, int cod, char nume[20], int concentratie, int cantitate);

/**
 * Sterge un medicament din repository.
 * @param service Service-ul care gestioneaza medicamentele, tip Service*.
 * @param cod Codul medicamentului de sters, tip int.
 * @return 1 daca stergerea a fost reusita, altfel un cod de eroare.
 */
int remove_medicament(Service* service, int cod);

/**
 * Filtreaza medicamentele care au o cantitate mai mica decat cea specificata.
 * @param service Service-ul care gestioneaza medicamentele, tip Service*.
 * @param cantitate Pragul de cantitate pentru filtrare, tip int.
 * @return O lista de medicamente care indeplinesc criteriul.
 */
MedicamentList filter1(Service* service, int cantitate);

/**
 * Filtreaza medicamentele al caror nume incepe cu o anumita litera.
 * @param service Service-ul care gestioneaza medicamentele, tip Service*.
 * @param litera Litera cu care trebuie sa inceapa numele medicamentului, tip char.
 * @return O lista de medicamente care indeplinesc criteriul.
 */
MedicamentList filter2(Service* service, char litera);

/**
 * Ordoneaza medicamentele alfabetic dupa nume.
 * @param service Service-ul care gestioneaza medicamentele, tip Service*.
 * @param tip_ordonare 1 pentru ordine alfabetica crescatoare, -1 pentru descrescatoare, tip int.
 * @return Un array de medicamente ordonat conform criteriului dat.
 */
Medicament* ordered1(Service* service, int tip_ordonare);

/**
 * Ordoneaza medicamentele dupa cantitate.
 * @param service Service-ul care gestioneaza medicamentele, tip Service*.
 * @param tip_ordonare 1 pentru ordine crescatoare, -1 pentru descrescatoare, tip int.
 * @return Un array de medicamente ordonat conform criteriului dat.
 */
Medicament* ordered2(Service* service, int tip_ordonare);

#endif //SERVICE_H
