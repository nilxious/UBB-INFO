#include "Repository.h"
#include <string.h>

Repository creeaza_repository() {
    Repository repo;
    repo.stoc_curent = 0;
    return repo;
}

int adauga_medicament(Repository* repo, Medicament medicament_nou) {
    Medicament medicament;
    int gasit = 0;
    int index = 0;
    int dejaExistaCod = 0;
    if (repo->stoc_curent < 100) {
        for (int i = 0; i<repo->stoc_curent; i++) {
            medicament = repo->stoc[i];
            if (medicament_nou.cod == medicament.cod && strcmp(medicament_nou.nume, medicament.nume) == 0 && \
            medicament.concentratie == medicament_nou.concentratie) {
                gasit = 1;
                index = i;
                break;
            }
            else if (medicament_nou.cod == medicament.cod) {
                dejaExistaCod = 1;
                index = i;
                break;
            }
        }

        if (gasit){
            repo->stoc[index].cantitate += medicament_nou.cantitate;
            return 2;
        }
        else if (!dejaExistaCod || repo->stoc_curent == 0) {
            repo->stoc[repo->stoc_curent] = medicament_nou;
            repo->stoc_curent += 1;
            return 1;
        }
        return 0;
    }
    else {
        return 0;
    }
}

int modifica_medicament(Repository* repo, int cod, char* nume, int concentratie, int cantitate) {
    Medicament medicament;
    int gasit = 0;
    for (int i = 0; i< repo->stoc_curent; i++) {
        medicament = repo -> stoc[i];
        if (medicament.cod == cod) {
            gasit = 1;

            strcpy(repo->stoc[i].nume, nume);
            repo->stoc[i].cantitate = cantitate;
            repo->stoc[i].concentratie = concentratie;
            break;
        }
    }

    if(!gasit) {
        return -1;
    }
    return 1;
}

int sterge_medicament(Repository* repo, int cod) {
    if (repo->stoc_curent == 0) return -3;

    int index = -1;

    for (int i = 0; i < repo->stoc_curent; i++) {
        if (repo->stoc[i].cod == cod) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < repo->stoc_curent - 1; i++) {
            repo->stoc[i] = repo->stoc[i + 1];
        }

        repo->stoc_curent--;

        return 1;
    }

    return -1;
}





