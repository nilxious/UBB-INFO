#ifndef SERVICE_H
#define SERVICE_H

#include "Repository.h"

class Service {
private:
    Repository& repository;
public:

    /*
     * Metoda care creeaza service-ul
     */
    Service(Repository& repo): repository(repo) {}

    /*
     * Metoda care returneaza lista de imbracaminte
     * return: vector<Imbracaminte>
     */
    vector<Imbracaminte>& getAll();

    /*
     * Metoda care returneaza o lista filtrata de imbracaminte care au un anumit brand
     * return: vector<imbracaminte>
     */
    vector<Imbracaminte> filtrareBrand(string brand);


    /*
     * Metoda care sorteaza hainele dupa marime
     * return: vector<Imbracaminte>
     */
    vector<Imbracaminte> sortareMarime();

    /*
     * Metoda care reseteaza lista de imbracaminte
     * return: -
     */
    void reset();
};



#endif //SERVICE_H
