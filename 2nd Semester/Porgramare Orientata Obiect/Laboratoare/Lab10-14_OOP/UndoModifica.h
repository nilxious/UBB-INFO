#ifndef UNDOMODIFICA_H
#define UNDOMODIFICA_H

#include "ActiuneUndo.h"
#include "Produs.h"
#include "Repo.h"

class UndoModifica : public ActiuneUndo {
private:
    Repo& repo;
    Produs produs_original;
    Produs produs_modificat;

public:
    UndoModifica(Repo& r, Produs produs_original, Produs produs_modificat)
        : repo(r), produs_original(produs_original), produs_modificat(produs_modificat) {}

    void doUndo() override {
        auto it = std::find_if(repo.getAll().begin(), repo.getAll().end(),
                               [&](Produs& p) { return p.getId() == produs_modificat.getId(); });

        if (it != repo.getAll().end()) {
            it->setNume(produs_original.getNume());
            it->setPret(produs_original.getPret());
            it->setTip(produs_original.getTip());
            it->setProducator(produs_original.getProducator());
        }
    }
};

#endif // UNDOMODIFICA_H
