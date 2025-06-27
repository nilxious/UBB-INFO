#pragma once
#include "IteratorColectie.h"

typedef int TElem;

#define NULL_TVALOARE -1

bool rel(TElem e1, TElem e2);

class IteratorColectie;


class Colectie {
    friend class IteratorColectie;

private:
    struct Node {
        TElem element;
        int left;
        int right;
    };

    Node* nodes;
    int capacity;
    int root;
    int firstEmpty;
    int size;

    void resize();
    int createNode(TElem elem);
    void deallocateNode(int pos);
    int search(TElem elem) const;
    int removeRec(int node, TElem elem, bool& removed);
    int minimum(int node) const;
    int deallocateAndReturn(int child, int node);

public:
    Colectie();

    void adauga(TElem e);

    bool sterge(TElem e);

    bool cauta(TElem elem) const;

    int nrAparitii(TElem elem) const;

    int nrAparitiiRec(int node, TElem elem) const;

    int dim() const;

    bool vida() const;



    IteratorColectie iterator() const;

    // adauga `nr` aparitii ale elementului `elem` in colectie
    // arunca exceptie daca `nr` este negativ sau 0
    void adaugaAparitiiMultiple(int nr, TElem elem);

    ~Colectie();
};
