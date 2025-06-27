#include "service.h"
#include <iostream>
#include <algorithm> // for sort
using std::cout;

void Service::add(const string& nume, const int& pret, const string& tip, const string& producator, const int& id) {
    Produs produs{nume, pret, tip, producator, id};
    try {
        validator.valideaza(produs);
    } catch (const ValidationException& e) {
        throw e;
    }
    repo.store(produs);
}

void Service::remove(const int& id) {
    Produs produs{"ceva",444,"cevdfgdfa","ceva434",id};
    try {
        validator.valideaza(produs);
    } catch (const ValidationException& e) {
        throw e;
    }
    repo.remove(id);
}

void Service::modify_price(const int& id, const int& price) {
    try {
        repo.modify_price(id, price);
    } catch (const RepoException& e) {
        throw e;
    }
}

void Service::modify_tip(const int& id, const string& tip) {
    try {
        repo.modify_tip(id, tip);
    } catch (const RepoException& e) {
        throw e;
    }
}

void Service::modify_nume(const int& id, const string& nume) {
    try {
        repo.modify_nume(id, nume);
    } catch (const RepoException& e) {
        throw e;
    }
}

void Service::modify_producator(const int& id, const string& producator) {
    try {
        repo.modify_producator(id, producator);
    } catch (const RepoException& e) {
        throw e;
    }
}

const Produs& Service::search(const int& id) {
    try {
        return repo.search(id);
    } catch (const RepoException& e) {
        throw e;
    }
}

const VectorDinamic<Produs>& Service::getAll() {
    return repo.getAll();
}

VectorDinamic<Produs> Service::filterByPret(const int& pret1, const int& pret2) {
    VectorDinamic<Produs> filtered;
    for (int i = 0; i < repo.getAll().size(); i++) {
        const Produs& produs = repo.getAll()[i];
        if (produs.getPret() > pret1 && produs.getPret() < pret2) {
            filtered.adauga(produs);
        }
    }

    if (filtered.size() == 0) {
        throw RepoException("Nu sunt produse intre aceste preturi");
    }

    return filtered;
}

VectorDinamic<Produs> Service::filterByNume(const string& nume) {
    VectorDinamic<Produs> filtered;
    for (int i = 0; i < repo.getAll().size(); i++) {
        const Produs& produs = repo.getAll()[i];
        if (produs.getNume() == nume) {
            filtered.adauga(produs);
        }
    }

    if (filtered.size() == 0) {
        throw RepoException("Nu sunt produse cu acest nume");
    }

    return filtered;
}

VectorDinamic<Produs> Service::filterByProducator(const string& producator) {
    VectorDinamic<Produs> filtered;
    for (int i = 0; i < repo.getAll().size(); i++) {
        const Produs& produs = repo.getAll()[i];
        if (produs.getProducator() == producator) {
            filtered.adauga(produs);
        }
    }

    if (filtered.size() == 0) {
        throw RepoException("Nu sunt produse cu acest producator");
    }

    return filtered;
}

VectorDinamic<Produs> Service::sortByNume(bool ascending) {
    VectorDinamic<Produs> sortedProduse = repo.getAll();
    if (sortedProduse.size() == 0) {
        throw RepoException("Nu este nimic de sortat");
    }

    VectorDinamic<Produs> sorted;
    for (int i = 0; i < sortedProduse.size(); i++) {
        for (int j = i + 1; j < sortedProduse.size(); j++) {
            if ((ascending && sortedProduse[i].getNume() > sortedProduse[j].getNume()) ||
                (!ascending && sortedProduse[i].getNume() < sortedProduse[j].getNume())) {
                std::swap(sortedProduse[i], sortedProduse[j]);
            }
        }
        sorted.adauga(sortedProduse[i]);
    }

    return sorted;
}

VectorDinamic<Produs> Service::sortByPret(bool ascending) {
    VectorDinamic<Produs> sortedProduse = repo.getAll();
    if (sortedProduse.size() == 0) {
        throw RepoException("Nu este nimic de sortat");
    }

    VectorDinamic<Produs> sorted;
    for (int i = 0; i < sortedProduse.size(); i++) {
        for (int j = i + 1; j < sortedProduse.size(); j++) {
            if ((ascending && sortedProduse[i].getPret() > sortedProduse[j].getPret()) ||
                (!ascending && sortedProduse[i].getPret() < sortedProduse[j].getPret())) {
                std::swap(sortedProduse[i], sortedProduse[j]);
            }
        }
        sorted.adauga(sortedProduse[i]);
    }

    return sorted;
}

VectorDinamic<Produs> Service::sortByNumeSiTip(bool ascending) {
    VectorDinamic<Produs> sortedProduse = repo.getAll();
    if (sortedProduse.size() == 0) {
        throw RepoException("Nu este nimic de sortat");
    }

    for (int i = 0; i < sortedProduse.size() - 1; i++) {
        for (int j = i + 1; j < sortedProduse.size(); j++) {
            bool shouldSwap = false;
            if (ascending) {
                shouldSwap = (sortedProduse[i].getNume() > sortedProduse[j].getNume()) ||
                            (sortedProduse[i].getNume() == sortedProduse[j].getNume() &&
                             sortedProduse[i].getTip() > sortedProduse[j].getTip());
            } else {
                shouldSwap = (sortedProduse[i].getNume() < sortedProduse[j].getNume()) ||
                            (sortedProduse[i].getNume() == sortedProduse[j].getNume() &&
                             sortedProduse[i].getTip() < sortedProduse[j].getTip());
            }

            if (shouldSwap) {
                std::swap(sortedProduse[i], sortedProduse[j]);
            }
        }
    }

    return sortedProduse;
}

