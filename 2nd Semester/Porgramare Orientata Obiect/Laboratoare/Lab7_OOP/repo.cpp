#include "repo.h"

const VectorDinamic<Produs>& Repo::getAll() {
    return produse;
}

void Repo::store(const Produs& produs_nou) {
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].getId() == produs_nou.getId()) {
            throw RepoException("Deja exista produs cu acest id");
        }
        else if (produse[i].getNume() == produs_nou.getNume() && produse[i].getProducator() == produs_nou.getProducator() && produse[i].getPret() == produs_nou.getPret()) {
            throw RepoException("Deja exista un produs cu acelaasi nume, producator si pret");
        }
    }
    produse.push_back(produs_nou);
}

void Repo::remove(const int& id) {
    for (int i = 0; i < produse.size(); i++) {
        if (produse[i].getId() == id) {
            produse.pop_back();
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

void Repo::modify_price(const int& id, const int& price) {
    for (int i = 0; i < produse.size(); ++i) {
        if (produse[i].getId() == id) {
            produse[i].setPret(price);
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

void Repo::modify_tip(const int& id, const string& tip) {
    for (int i = 0; i < produse.size(); ++i) {
        if (produse[i].getId() == id) {
            produse[i].setTip(tip);
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

void Repo::modify_nume(const int& id, const string& nume) {
    for (int i = 0; i < produse.size(); ++i) {
        if (produse[i].getId() == id) {
            produse[i].setNume(nume);
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

void Repo::modify_producator(const int& id, const string& producator) {
    for (int i = 0; i < produse.size(); ++i) {
        if (produse[i].getId() == id) {
            produse[i].setProducator(producator);
            return;
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}

const Produs& Repo::search(const int& id) {
    for (int i = 0; i < produse.size(); ++i) {
        if (produse[i].getId() == id) {
            return produse[i];
        }
    }
    throw RepoException("Nu s-a gasit un produs cu acest id");
}
