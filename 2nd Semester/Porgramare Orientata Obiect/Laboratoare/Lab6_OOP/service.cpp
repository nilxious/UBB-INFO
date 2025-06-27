#include "service.h"
#include <iostream>
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

const vector<Produs>& Service::getAll() {
    return repo.getAll();
}

vector<Produs> Service::filterByPret(const int& pret1, const int& pret2) {
    vector<Produs> filtered;
    for (const auto& produs : repo.getAll()) {
        if (produs.getPret() > pret1 && produs.getPret() < pret2) {
            filtered.push_back(produs);
        }
    }

    if (filtered.empty()) {
        throw RepoException("Nu sunt produse intre aceste preturi");
    }

    return filtered;
}

vector<Produs> Service::filterByNume(const string& nume) {
    vector<Produs> filtered;
    for (const auto& produs : repo.getAll()) {
        if (produs.getNume() == nume) {
            filtered.push_back(produs);
        }
    }

    if (filtered.empty()) {
        throw RepoException("Nu sunt produse cu acest nume");
    }

    return filtered;
}

vector<Produs> Service::filterByProducator(const string& producator) {
    vector<Produs> filtered;
    for (const auto& produs : repo.getAll()) {
        if (produs.getProducator() == producator) {
            filtered.push_back(produs);
        }
    }

    if (filtered.empty()) {
        throw RepoException("Nu sunt produse cu acest producator");
    }

    return filtered;
}

vector<Produs> Service::sortByNume(bool ascending) {
    vector<Produs> sortedProduse = repo.getAll();
    if (sortedProduse.empty()) {
        throw RepoException("Nu este nimic de sortat");
    }

    if (ascending) {
        sort(sortedProduse.begin(), sortedProduse.end(), [](const Produs& a, const Produs& b) {
            return a.getNume() < b.getNume();
        });
    } else {
        sort(sortedProduse.begin(), sortedProduse.end(), [](const Produs& a, const Produs& b) {
            return a.getNume() > b.getNume();
        });
    }
    return sortedProduse;
}

vector<Produs> Service::sortByPret(bool ascending) {
    vector<Produs> sortedProduse = repo.getAll();
    if (sortedProduse.empty()) {
        throw RepoException("Nu este nimic de sortat");
    }

    if (ascending) {
        sort(sortedProduse.begin(), sortedProduse.end(), [](const Produs& a, const Produs& b) {
            return a.getPret() < b.getPret();
        });
    } else {
        sort(sortedProduse.begin(), sortedProduse.end(), [](const Produs& a, const Produs& b) {
            return a.getPret() > b.getPret();
        });
    }
    return sortedProduse;
}

vector<Produs> Service::sortByNumeSiTip(bool ascending) {
    vector<Produs> sortedProduse = repo.getAll();
    if (sortedProduse.empty()) {
        throw RepoException("Nu este nimic de sortat");
    }

    if (ascending) {
        sort(sortedProduse.begin(), sortedProduse.end(), [](const Produs& a, const Produs& b) {
            if (a.getNume() == b.getNume()) {
                return a.getTip() < b.getTip();
            }
            return a.getNume() < b.getNume();
        });
    } else {
        sort(sortedProduse.begin(), sortedProduse.end(), [](const Produs& a, const Produs& b) {
            if (a.getNume() == b.getNume()) {
                return a.getTip() > b.getTip();
            }
            return a.getNume() > b.getNume();
        });
    }
    return sortedProduse;
}



