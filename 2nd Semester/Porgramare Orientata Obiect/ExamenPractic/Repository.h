#pragma once
#include "Parcare.h"
#include <vector>
#include <string>

class Repository {
private:
    std::vector<Parcare> parcari;
    std::string filename;

    /*
     * Incarca parcarile din fisier
     * Return: -
     */
    void loadFromFile();

    /*
     * Scrie parcarile in fisier
     * Return: -
     */
    void writeToFile();

public:
    /*
     * Constructorul clasei Repository
     * Parametru: numele fisierului pentru stocare
     * Return: -
     */
    Repository(std::string filename);

    /*
     * Returneaza referinta catre lista de parcari
     * Return: vector<Parcare>&
     */
    std::vector<Parcare>& getAll();

    /*
     * Adauga un Parcare nou
     * Parametru: const Parcare& m - parcarea de adaugat
     * Return: -
     */
    void add(const Parcare& m);

    /*
     * Actualizeaza o Parcare existenta (dupa id)
     * Parametru: const Parcare& m - Parcarea cu noile valori
     * Return: -
     */
    void update(const Parcare& m);

};
