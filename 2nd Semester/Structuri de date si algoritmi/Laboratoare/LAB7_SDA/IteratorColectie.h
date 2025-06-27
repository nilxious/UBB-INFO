#pragma once
#include "Colectie.h"
#include <stack>

typedef int TElem;

class Colectie;

class IteratorColectie {
    friend class Colectie;

private:
    const Colectie& col;
    std::stack<int> stiva;
    int curent;

    // adaugă în stivă drumul spre cel mai stâng nod, pornind din nod
    void initStack(int nod);

    // constructor primit doar de Colectie
    IteratorColectie(const Colectie& c);

public:
    void prim();
    void urmator();
    bool valid() const;
    TElem element() const;
};
