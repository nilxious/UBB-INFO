#include "ActiuneUndo.h"
#include "Produs.h"
#include "repo.h"
#ifndef UNDOADAUGA_H
#define UNDOADAUGA_H

class UndoAdauga : public ActiuneUndo {
    Repo& repository;
    Produs produsAdaugat;
public:
    UndoAdauga(Repo& repository, const Produs& produs) : repository(repository), produsAdaugat(produs) {};

    void doUndo() override {
        auto& produse = repository.getAll();
        auto it = std::find(produse.begin(), produse.end(), produsAdaugat);

        if (it != produse.end()) {
            repository.remove(it->getId());
        }
    }
};

#endif //UNDOADAUGA_H
