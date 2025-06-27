#include "repo.h"

const vector<Produs>& Repo::getAll() {
    return produse;
}

void Repo::store(const Produs& produs_nou) {
    for (const Produs& p : produse) {
        if (p.getId() == produs_nou.getId()) {
            throw RepoException("Deja exista produs cu acest id");
        }
        else if (p.getNume() == produs_nou.getNume() && p.getProducator() == produs_nou.getProducator() && p.getPret() == produs_nou.getPret()) {
            throw RepoException("Deja exista un produs cu acelaasi nume, producator si pret");
        }
    }
    produse.push_back(produs_nou);
}

void Repo::remove(const int& id) {
    for (auto it = produse.begin(); it != produse.end(); it++) {
        if (it->getId() == id) {
            produse.erase(it);
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

void Repo::modify_price(const int& id, const int& price) {
    for (auto it = produse.begin(); it != produse.end(); ++it) {
        if (it->getId() == id) {
            it->setPret(price);
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

void Repo::modify_tip(const int& id, const string& tip) {
    for (auto it = produse.begin(); it != produse.end(); ++it) {
        if (it->getId() == id) {
            it->setTip(tip);
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

void Repo::modify_nume(const int& id, const string& nume) {
    for (auto it = produse.begin(); it != produse.end(); ++it) {
        if (it->getId() == id) {
            it->setNume(nume);
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

void Repo::modify_producator(const int& id, const string& producator) {
    for (auto it = produse.begin(); it != produse.end(); ++it) {
        if (it->getId() == id) {
            it->setProducator(producator);
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

const Produs& Repo::search(const int& id) {
    for (const auto& produs : produse) {
        if (produs.getId() == id) {
            return produs;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}
