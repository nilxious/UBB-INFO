#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "C:\Users\Catalin\Documents\Lab2_OOP\domain\medicament.h"

/**
 * Structura Repository care contine stocul de medicamente si numarul curent de medicamente.
 */
typedef struct {
    Medicament stoc[100];
    int stoc_curent;
}Repository;

/**
 * Creeaza un nou repository.
 * @return Un obiect de tip Repository initializat.
 */
Repository creeaza_repository();

/**
 * Adauga un medicament in repository.
 * @param repo Repository-ul in care se va adauga medicamentul, tip Repository*.
 * @param medicament_nou Medicamentul care va fi adaugat, tip Medicament.
 * @return 1 daca medicamentul a fost adaugat, 2 daca s-a marit cantitatea unui medicament existent, 0 daca adaugarea a esuat.
 */
int adauga_medicament(Repository* repo, Medicament medicament_nou);

/**
 * Modifica un medicament existent in repository.
 * @param repo Repository-ul in care se face modificarea, tip Repository*.
 * @param cod Codul medicamentului de modificat, tip int.
 * @param nume Noul nume al medicamentului, tip char[20].
 * @param concentratie Noua concentratie a medicamentului, tip int.
 * @param cantitate Noua cantitate disponibila, tip int.
 * @return 1 daca modificarea a fost realizata cu succes, -1 daca medicamentul nu a fost gasit.
 */
int modifica_medicament(Repository* repo, int cod, char nume[20], int concentratie, int cantitate);

/**
 * Sterge un medicament din repository.
 * @param repo Repository-ul din care se va sterge medicamentul, tip Repository*.
 * @param cod Codul medicamentului de sters, tip int.
 * @return 1 daca stergerea a fost reusita, -1 daca medicamentul nu a fost gasit, -3 daca repository-ul este gol.
 */
int sterge_medicament(Repository* repo, int cod);

#endif //REPOSITORY_H
