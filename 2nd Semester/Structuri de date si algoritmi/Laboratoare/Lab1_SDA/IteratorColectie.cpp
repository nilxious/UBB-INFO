#include "IteratorColectie.h"
#include <exception>

IteratorColectie::IteratorColectie(const Colectie& c): col(c), curent(0) {}
	/* de adaugat */

TElem IteratorColectie::element() const{
	if (!valid()) throw std::exception();
	return col.elems[curent];
}

bool IteratorColectie::valid() const {
	return curent < col.n;
}

void IteratorColectie::urmator() {
	if (!valid()) throw std::exception();
	curent++;
}

void IteratorColectie::prim() {
	curent = 0;
}
