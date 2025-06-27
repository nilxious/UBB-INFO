#include "IteratorColectie.h"
#include "Colectie.h"
#include <stdexcept>

IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
    prim();
}

void IteratorColectie::prim() {
    poz = 0;
    frecventaCurenta = 0;

    while (poz < col.m && col.hashTable[poz] == -1) {
        poz++;
    }

    if (poz < col.m) {
        curent = col.hashTable[poz];
        frecventaCurenta = 1;
    } else {
        curent = -1;
    }
}

void IteratorColectie::urmator() {
    if (!valid()) {
        throw std::out_of_range("Iterator invalid");
    }

    if (frecventaCurenta < col.e[curent].frecventa) {
        frecventaCurenta++;
        return;
    }

    int urmatorNode = col.urm[curent];
    if (urmatorNode != -1) {
        curent = urmatorNode;
        frecventaCurenta = 1;
        return;
    }

    poz++;
    while (poz < col.m && col.hashTable[poz] == -1) {
        poz++;
    }

    if (poz < col.m) {
        curent = col.hashTable[poz];
        frecventaCurenta = 1;
    } else {
        curent = -1;
    }
}


bool IteratorColectie::valid() const {
    return curent != -1;
}

TElem IteratorColectie::element() const {
    if (!valid()) {
        throw std::out_of_range("Iterator invalid");
    }
    return col.e[curent].element;
}