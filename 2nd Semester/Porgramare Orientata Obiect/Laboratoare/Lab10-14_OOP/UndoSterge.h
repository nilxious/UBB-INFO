#include "ActiuneUndo.h"
#include "Repo.h"
#ifndef UNDOSTERGE_H
#define UNDOSTERGE_H

class UndoSterge : public ActiuneUndo {
private:
    Repo& repo;
    Produs produs_sters;

public:
    UndoSterge(Repo& r, const Produs& m): repo{ r }, produs_sters{ m } {}

    void doUndo() override {
        repo.store(produs_sters);
    }
};

#endif //UNDOSTERGE_H
