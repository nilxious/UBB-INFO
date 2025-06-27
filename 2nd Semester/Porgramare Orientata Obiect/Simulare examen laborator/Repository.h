//
// Created by Catalin on 5/23/2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include "Imbracaminte.h"

using std::vector;

class Repository {
private:
    vector<Imbracaminte> haine;
    string path;
public:
    Repository(string path);

    /*
     * Metoda care citeste datele din fisier
     * return: -
     */
    void citesteFisier();

    /*
     * Metoda care scrie datele in fisier
     * return: -
     */
    void scrieFisier();

    /*
     * Metoda care returneaza lista de imbracaminte
     * return: vector<Imbracaminte>
     */
    vector<Imbracaminte>& getAll();

    /*
     * Metoda care reseteaza lista de imbracaminte
     * return: -
     */
    void reset();
};



#endif //REPOSITORY_H
