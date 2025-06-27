#ifndef COSCUMPARATURI_H
#define COSCUMPARATURI_H
#include <vector>
#include "produs.h"
#include <fstream>
#include <random>

class CosCumparaturi {
private:
    std::vector<Produs> cos;

public:
    CosCumparaturi() = default;

    void golesteCos();

    void adaugaInCos(const Produs& produs);

    void genereazaCos(const std::vector<Produs>& toateProdusele, int count);

    void exportToCSV(const std::string& filename) const;

    void exportToHTML(const std::string& filename) const;

    int totalCos() const;

    const std::vector<Produs>& getProduse() const;
};



#endif //COSCUMPARATURI_H
