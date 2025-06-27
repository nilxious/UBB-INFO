#include "IteratorColectie.h"
#include <exception>

IteratorColectie::IteratorColectie(const Colectie& c) : col(c), curent(-1) {
    prim();
}

// Best Case: Θ(1)
// Worst Case: Θ(h)
// Overall Complexity: O(h)
void IteratorColectie::initStack(int nod) {
    while (nod != -1) {
        stiva.push(nod);
        nod = col.nodes[nod].left;
    }
}

// Best Case: Θ(1)
// Worst Case: Θ(h)
// Overall Complexity: O(h)
void IteratorColectie::prim() {
    while (!stiva.empty()) stiva.pop();
    initStack(col.root);
    if (!stiva.empty())
        curent = stiva.top();
    else
        curent = -1;
}

// Best Case: Θ(1)
// Worst Case: Θ(h)
// Overall Complexity: O(h)
void IteratorColectie::urmator() {
    if (stiva.empty()) {
        curent = -1;
        return;
    }

    int nodCurent = stiva.top();
    stiva.pop();

    int dreapta = col.nodes[nodCurent].right;
    initStack(dreapta);

    if (!stiva.empty())
        curent = stiva.top();
    else
        curent = -1;
}

// Best Case: Θ(1)
// Worst Case: Θ(1)
// Overall Complexity: Θ(1)
bool IteratorColectie::valid() const {
    return curent != -1;
}

// Best Case: Θ(1)
// Worst Case: Θ(1)
// Overall Complexity: Θ(1)
TElem IteratorColectie::element() const {
    if (!valid())
        throw std::exception();
    return col.nodes[curent].element;
}
