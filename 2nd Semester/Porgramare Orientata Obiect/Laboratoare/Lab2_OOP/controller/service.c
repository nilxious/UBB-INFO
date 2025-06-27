#include "C:\Users\Catalin\Documents\Lab2_OOP\domain\medicament.h"
#include "Service.h"
#include <string.h>

Service creeaza_service(Repository* repo, Validator* validator) {
    Service service;

    service.repo = repo;
    service.validator = validator;

    return service;
}

int add_medicament(Service* service, int cod, char nume[20], int concentratie, int cantitate) {
    Medicament medicament_fictiv = creeazaMedicament(cod, nume, concentratie, cantitate);

    if (service->validator->valideaza(medicament_fictiv) != 0) {
        return -7;
    }

    int eroare = adauga_medicament(service->repo, medicament_fictiv);

    return eroare;
}

int modify_medicament(Service* service, int cod, char* nume, int concentratie, int cantitate) {
    Medicament medicament_fictiv = creeazaMedicament(cod, nume, concentratie, cantitate);

    if (service->validator->valideaza(medicament_fictiv) != 0) {
        return -7;
    }

    int eroare = modifica_medicament(service->repo, cod, nume, concentratie, cantitate);

    return eroare;

}

int remove_medicament(Service* service, int cod) {
    Medicament medicament_fictiv = creeazaMedicament(cod, "Ceva", 1, 1);

    if (service->validator->valideaza(medicament_fictiv) != 0) {
        return -7;
    }

    int eroare = sterge_medicament(service->repo, cod);

    return eroare;
}

MedicamentList filter1(Service* service, int cantitate) {
    Medicament medicamente[100];
    int size = 0;

    for (int i = 0; i < service->repo->stoc_curent; i++) {
        if (service->repo->stoc[i].cantitate < cantitate) {
            medicamente[size] = service->repo->stoc[i];
            size++;
        }
    }

    MedicamentList result;
    result.size = size;
    for (int i = 0; i < size; i++) {
        result.medicamente[i] = medicamente[i];
    }

    return result;
}

MedicamentList filter2(Service* service, char litera) {
    Medicament medicamente[100];
    int size = 0;

    for (int i = 0; i < service->repo->stoc_curent; i++) {
        if (service->repo->stoc[i].nume[0] == litera) {
            medicamente[size] = service->repo->stoc[i];
            size++;
        }
    }

    MedicamentList result;
    result.size = size;
    for (int i = 0; i < size; i++) {
        result.medicamente[i] = medicamente[i];
    }

    return result;
}

Medicament* ordered1(Service* service, int tip_ordonare) {
    static Medicament medicamente_ordonate[100];
    for (int i=0; i<service->repo->stoc_curent; i++) {
        medicamente_ordonate[i] = service->repo->stoc[i];
    }

    for (int i = 0; i<service->repo->stoc_curent-1; i++) {
        for(int j = i+1; j<service->repo->stoc_curent; j++) {
            if ((tip_ordonare == 1 && strcmp(medicamente_ordonate[i].nume, medicamente_ordonate[j].nume) > 0) ||
            (tip_ordonare == -1 && strcmp(medicamente_ordonate[i].nume, medicamente_ordonate[j].nume) < 0))
            {
                Medicament temp = medicamente_ordonate[i];
                medicamente_ordonate[i] = medicamente_ordonate[j];
                medicamente_ordonate[j] = temp;
            }
        }
    }

    return medicamente_ordonate;
}

Medicament* ordered2(Service* service, int tip_ordonare) {
    static Medicament medicamente_ordonate[100];
    for (int i=0; i<service->repo->stoc_curent; i++) {
        medicamente_ordonate[i] = service->repo->stoc[i];
    }

    for (int i = 0; i<service->repo->stoc_curent-1; i++) {
        for(int j = i+1; j<service->repo->stoc_curent; j++) {
            if (medicamente_ordonate[i].cantitate * tip_ordonare > medicamente_ordonate[j].cantitate * tip_ordonare) {
                Medicament temp = medicamente_ordonate[i];
                medicamente_ordonate[i] = medicamente_ordonate[j];
                medicamente_ordonate[j] = temp;
            }
        }
    }

    return medicamente_ordonate;
}