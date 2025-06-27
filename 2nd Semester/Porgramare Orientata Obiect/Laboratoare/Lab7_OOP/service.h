#ifndef SERVICE_H
#define SERVICE_H

#include "repo.h"
#include "validator.h"

class Service {
private:
    Repo& repo;
    const Validator& validator;
public:
    Service(const Service& ot) = delete;
    Service() = default;

    Service(Repo& rep, const Validator& val) : repo{ rep }, validator{ val } { }

    void add(const string& nume, const int& pret, const string& tip, const string& producator, const int& id);
    void remove(const int& id);

    void modify_price(const int& id, const int& price);
    void modify_tip(const int& id, const string& tip);
    void modify_nume(const int& id, const string& nume);
    void modify_producator(const int& id, const string& producator);

    const Produs& search(const int& id);

    const VectorDinamic<Produs>& getAll();

    VectorDinamic<Produs> filterByPret(const int& pret1, const int& pret2);
    VectorDinamic<Produs> filterByNume(const string& nume);
    VectorDinamic<Produs> filterByProducator(const string& producator);

    VectorDinamic<Produs> sortByNume(bool ascending);
    VectorDinamic<Produs> sortByPret(bool ascending);
    VectorDinamic<Produs> sortByNumeSiTip(bool ascending);


};

#endif //SERVICE_H
