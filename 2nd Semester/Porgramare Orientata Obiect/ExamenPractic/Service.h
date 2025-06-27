#pragma once
#include "Repository.h"
#include <vector>
#include <algorithm>

class Service {
private:
    Repository& repo;

public:
    /*
     * Constructorul clasei Service
     * Parametru: referinta catre un obiect Repository
     */
    Service(Repository& repo);

    /*
     * Returneaza toate parcarile sortate crescator dupa numarul de locuri (linii*coloane)
     * Return: vector<Parcare> - lista sortata
     */
    std::vector<Parcare> getAllSortedByTotalLocuri();

    /*
     * Adauga o Parcare in repository
     * Parametru: const Parcare& m - obiectul de adaugat
     * Return: -
     */
    void add(const Parcare& m);

    /*
     * Actualizeaza un Parcare existent (cu acelasi id)
     * Parametru: const Parcare& m - obiectul cu valorile actualizate
     * Return: -
     */
    void update(const Parcare& m);


};
