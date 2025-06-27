#include "service.h"
#include <iostream>
#include <algorithm> // for sort
#include "UndoAdauga.h"
#include "UndoSterge.h"
#include "UndoModifica.h"


using std::cout;

void Service::add(const string& nume, const int& pret, const string& tip, const string& producator, const int& id) {
    Produs produs{nume, pret, tip, producator, id};
    try {
        validator.valideaza(produs);
    } catch (const ValidationException& e) {
        throw e;
    }
    repo.store(produs);
    actiuni_undo.push_back(std::make_unique<UndoAdauga>( repo, produs));
}

void Service::remove(const int& id) {
    Produs produs = repo.search(id);
    repo.remove(id);
    actiuni_undo.push_back(std::make_unique<UndoSterge>(repo, produs));
}

void Service::modify_price(const int& id, const int& price) {
    try {
        Produs produs_original = repo.search(id);
        repo.modify_price(id, price);
        actiuni_undo.push_back(std::make_unique<UndoModifica>(repo, produs_original, Produs(produs_original.getNume(), price, produs_original.getTip(), produs_original.getProducator(), produs_original.getId())));
    } catch (const RepoException& e) {
        throw e;
    }
}

void Service::modify_tip(const int& id, const string& tip) {
    try {
        Produs produs_original = repo.search(id);
        repo.modify_tip(id, tip);

        actiuni_undo.push_back(std::make_unique<UndoModifica>(repo, produs_original, Produs(produs_original.getNume(), produs_original.getPret(), tip, produs_original.getProducator(), produs_original.getId())));
    } catch (const RepoException& e) {
        throw e;
    }
}

void Service::modify_nume(const int& id, const string& nume) {
    try {
        Produs produs_original = repo.search(id);
        repo.modify_nume(id, nume);

        actiuni_undo.push_back(std::make_unique<UndoModifica>(repo, produs_original, Produs(nume, produs_original.getPret(), produs_original.getTip(), produs_original.getProducator(), produs_original.getId())));
    } catch (const RepoException& e) {
        throw e;
    }
}

void Service::modify_producator(const int& id, const string& producator) {
    try {
        Produs produs_original = repo.search(id);
        repo.modify_producator(id, producator);

        actiuni_undo.push_back(std::make_unique<UndoModifica>(repo, produs_original, Produs(produs_original.getNume(), produs_original.getPret(), produs_original.getTip(), producator, produs_original.getId())));
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
    const auto& all = repo.getAll();
    std::copy_if(all.begin(), all.end(), std::back_inserter(filtered),
                 [pret1, pret2](const Produs& p) {
                     return p.getPret() > pret1 && p.getPret() < pret2;
                 });

    if (filtered.empty()) {
        throw RepoException("Nu sunt produse intre aceste preturi");
    }

    return filtered;
}

vector<Produs> Service::filterByNume(const string& nume) {
    vector<Produs> filtered;
    const auto& all = repo.getAll();
    std::copy_if(all.begin(), all.end(), std::back_inserter(filtered),
                 [&nume](const Produs& p) {
                     return p.getNume() == nume;
                 });

    if (filtered.empty()) {
        throw RepoException("Nu sunt produse cu acest nume");
    }

    return filtered;
}

vector<Produs> Service::filterByProducator(const string& producator) {
    vector<Produs> filtered;
    const auto& all = repo.getAll();
    std::copy_if(all.begin(), all.end(), std::back_inserter(filtered),
                 [&producator](const Produs& p) {
                     return p.getProducator() == producator;
                 });

    if (filtered.empty()) {
        throw RepoException("Nu sunt produse cu acest producator");
    }

    return filtered;
}

vector<Produs> Service::sortByNume(bool ascending) {
    auto sorted = repo.getAll();
    if (sorted.empty()) {
        throw RepoException("Nu este nimic de sortat");
    }

    std::sort(sorted.begin(), sorted.end(), [ascending](const Produs& a, const Produs& b) {
        return ascending ? a.getNume() < b.getNume() : a.getNume() > b.getNume();
    });

    return sorted;
}

vector<Produs> Service::sortByPret(bool ascending) {
    auto sorted = repo.getAll();
    if (sorted.empty()) {
        throw RepoException("Nu este nimic de sortat");
    }

    std::sort(sorted.begin(), sorted.end(), [ascending](const Produs& a, const Produs& b) {
        return ascending ? a.getPret() < b.getPret() : a.getPret() > b.getPret();
    });

    return sorted;
}

vector<Produs> Service::sortByNumeSiTip(bool ascending) {
    auto sorted = repo.getAll();
    if (sorted.empty()) {
        throw RepoException("Nu este nimic de sortat");
    }

    std::sort(sorted.begin(), sorted.end(), [ascending](const Produs& a, const Produs& b) {
        if (a.getNume() != b.getNume())
            return ascending ? a.getNume() < b.getNume() : a.getNume() > b.getNume();
        return ascending ? a.getTip() < b.getTip() : a.getTip() > b.getTip();
    });

    return sorted;
}

void Service::cosGoleste() {
    cos.golesteCos();
}

void Service::cosAdauga(const string& nume) {
    const auto& produse = repo.getAll();
    auto it = std::find_if(produse.begin(), produse.end(), [&](const Produs& p) {
        return p.getNume() == nume;
    });
    if (it == produse.end()) {
        throw RepoException("Nu exista produs cu acest nume");
    }
    cos.adaugaInCos(*it);
}

void Service::cosGenereaza(int count) {
    cos.genereazaCos(repo.getAll(), count);
}

void Service::cosExport(const string& filename, bool html) const {
    if (html)
        cos.exportToHTML(filename);
    else
        cos.exportToCSV(filename);
}

int Service::cosTotal() const {
    return cos.totalCos();
}

const vector<Produs>& Service::cosGetProduse() const {
    return cos.getProduse();
}

void Service::undo() {
    if (actiuni_undo.empty()) {
        throw RepoException("Nu au fost realizate modificari!\n");
    }

    actiuni_undo.back()->doUndo();
    actiuni_undo.pop_back();
}

std::map<string, DTO> Service::getTypeCountMap() const {
    std::map<std::string, DTO> result;
    for (const auto& produs : repo.getAll()) {
        const std::string& type = produs.getTip();
        if (result.find(type) == result.end()) {
            result[type] = DTO(type, 1);
        } else {
            result[type].increment();
        }
    }
    return result;
}



