#ifndef COSCUMPARATURI_H
#define COSCUMPARATURI_H
#include <vector>
#include "produs.h"
#include <fstream>
#include <random>
#include "observer.h"
#include <algorithm>

class CosCumparaturi {
private:
    std::vector<Produs> cos;

    std::vector<Observer*> observers;

    void notifyAll() {
        for (auto obs : observers) {
            obs->update();
        }
    }

public:
    CosCumparaturi() = default;


    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void removeObserver(Observer* obs) {
        observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void golesteCos();

    void adaugaInCos(const Produs& produs);

    void genereazaCos(const std::vector<Produs>& toateProdusele, int count);

    void exportToCSV(const std::string& filename) const;

    void exportToHTML(const std::string& filename) const;

    int totalCos() const;

    const std::vector<Produs>& getProduse() const;
};



#endif //COSCUMPARATURI_H
