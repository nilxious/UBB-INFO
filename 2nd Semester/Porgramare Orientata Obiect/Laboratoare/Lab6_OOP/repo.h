#ifndef REPO_H
#define REPO_H

#include <vector>
#include "produs.h"

using std::vector;

class RepoException {
    string msg;
public:
    RepoException(string m) :msg { m } {

    }

    string getMessage() const{
        return msg;
    }
};

class Repo {
private:
    vector<Produs> produse;
public:
    Repo(const Repo& other) = delete;
    Repo() = default;

    const vector<Produs>& getAll();

    void store(const Produs& produs);

    void remove(const int& id);

    void modify_price(const int& id, const int& price);
    void modify_tip(const int& id, const string& tip);
    void modify_nume(const int& id, const string& nume);
    void modify_producator(const int& id, const string& producator);

    const Produs& search(const int& id);

};

#endif //REPO_H
