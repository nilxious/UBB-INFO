#include "repo.h"
#include <algorithm>

vector<Produs>& Repo::getAll() {
    return produse;
}

void Repo::store(const Produs& produs_nou) {
    auto existsById = std::find_if(produse.begin(), produse.end(), [&](const Produs& p) {
        return p.getId() == produs_nou.getId();
    });

    if (existsById != produse.end()) {
        throw RepoException("Deja exista produs cu acest id");
    }

    produse.push_back(produs_nou);
}

void Repo::remove(const int& id) {
    auto it = std::find_if(produse.begin(), produse.end(), [&](const Produs& p) {
        return p.getId() == id;
    });

    if (it != produse.end()) {
        produse.erase(it);
    } else {
        throw RepoException("Nu s-a gasit un produs cu acest id");
    }
}

void Repo::modify_price(const int& id, const int& price) {
    auto it = std::find_if(produse.begin(), produse.end(), [&](const Produs& p) {
        return p.getId() == id;
    });

    if (it != produse.end()) {
        it->setPret(price);
    } else {
        throw RepoException("Nu s-a gasit un produs cu acest id");
    }
}

void Repo::modify_tip(const int& id, const string& tip) {
    auto it = std::find_if(produse.begin(), produse.end(), [&](const Produs& p) {
        return p.getId() == id;
    });

    if (it != produse.end()) {
        it->setTip(tip);
    } else {
        throw RepoException("Nu s-a gasit un produs cu acest id");
    }
}

void Repo::modify_nume(const int& id, const string& nume) {
    auto it = std::find_if(produse.begin(), produse.end(), [&](const Produs& p) {
        return p.getId() == id;
    });

    if (it != produse.end()) {
        it->setNume(nume);
    } else {
        throw RepoException("Nu s-a gasit un produs cu acest id");
    }
}

void Repo::modify_producator(const int& id, const string& producator) {
    auto it = std::find_if(produse.begin(), produse.end(), [&](const Produs& p) {
        return p.getId() == id;
    });

    if (it != produse.end()) {
        it->setProducator(producator);
    } else {
        throw RepoException("Nu s-a gasit un produs cu acest id");
    }
}

const Produs& Repo::search(const int& id) const{
    auto it = std::find_if(produse.begin(), produse.end(), [&](const Produs& p) {
        return p.getId() == id;
    });

    if (it != produse.end()) {
        return *it;
    } else {
        throw RepoException("Nu s-a gasit un produs cu acest id");
    }
}

void Repo::update(const std::vector<Produs>::iterator it, const Produs& produs) {
    *it = produs;
}
