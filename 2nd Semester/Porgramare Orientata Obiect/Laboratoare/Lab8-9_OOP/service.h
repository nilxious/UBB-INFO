#ifndef SERVICE_H
#define SERVICE_H

#include "repo.h"
#include "validator.h"
#include "ActiuneUndo.h"
#include "CosCumparaturi.h"
#include <memory>
#include <map>
#include "obiecftDTO.h"

class Service {
private:
    Repo& repo;
    const Validator& validator;
    CosCumparaturi& cos;
    std::vector<std::unique_ptr<ActiuneUndo>> actiuni_undo;
public:
    Service(const Service& ot) = delete;
    Service() = default;

    Service(Repo& rep, const Validator& val, CosCumparaturi& cos) : repo{ rep }, validator{ val }, cos { cos } { }

    void add(const string& nume, const int& pret, const string& tip, const string& producator, const int& id);
    void remove(const int& id);

    void modify_price(const int& id, const int& price);
    void modify_tip(const int& id, const string& tip);
    void modify_nume(const int& id, const string& nume);
    void modify_producator(const int& id, const string& producator);

    const Produs& search(const int& id);

    const vector<Produs>& getAll();

    vector<Produs> filterByPret(const int& pret1, const int& pret2);
    vector<Produs> filterByNume(const string& nume);
    vector<Produs> filterByProducator(const string& producator);

    vector<Produs> sortByNume(bool ascending);
    vector<Produs> sortByPret(bool ascending);
    vector<Produs> sortByNumeSiTip(bool ascending);

    void cosGoleste();

    void cosAdauga(const string& nume);

    void cosGenereaza(int count);

    void cosExport(const string& filename, bool html = false) const;

    int cosTotal() const;

    const vector<Produs>& cosGetProduse() const;

    std::map<string, DTO> getTypeCountMap() const;

    void undo();
};

#endif //SERVICE_H
