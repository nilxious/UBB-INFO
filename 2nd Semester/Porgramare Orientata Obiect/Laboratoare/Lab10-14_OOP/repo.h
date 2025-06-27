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
protected:
    vector<Produs> produse;
public:
    Repo(const Repo& other) = delete;
    Repo() = default;

    virtual vector<Produs>& getAll();

    virtual void store(const Produs& produs);

    virtual void remove(const int& id);

    virtual void modify_price(const int& id, const int& price);
    virtual void modify_tip(const int& id, const string& tip);
    virtual void modify_nume(const int& id, const string& nume);
    virtual void modify_producator(const int& id, const string& producator);

    virtual const Produs& search(const int& id) const;

    virtual void update(const std::vector<Produs>::iterator it, const Produs& produs);

    virtual ~Repo() = default;
};

#endif //REPO_H
