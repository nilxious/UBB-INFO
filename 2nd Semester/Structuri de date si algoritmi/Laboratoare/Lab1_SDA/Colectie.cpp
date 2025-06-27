#include "IteratorColectie.h"
#include <iostream>
#include <vector>

using namespace std;

bool rel(TElem e1, TElem e2) {
	/* de adaugat */
	return e1 <= e2;
}

Colectie::Colectie() {
	cap = 10;
	n = 0;
	elems = new TElem[cap];
}

void Colectie::redimensioneaza() {
	cap *= 2;
	TElem* newElems = new TElem[cap];
	for (int i = 0; i < n; i++) {
		newElems[i] = elems[i];
	}
	delete[] elems;
	elems = newElems;
}

//Complexitate best case = worst case = theta(n)
void Colectie::adauga(TElem e) {
	if (n == cap) {
		redimensioneaza();
	}
	int i = 0;
	while (i < n && rel(elems[i], e)) {
		i++;
	}
	for (int j = n; j > i; j--) {
		elems[j] = elems[j - 1];
	}
	elems[i] = e;
	n++;
}

//Complexitate best case = worst case = theta(n)
bool Colectie::sterge(TElem e) {
	int i = 0;
	while (i < n && elems[i] != e) {
		i++;
	}
	if (i == n) return false;
	for (int j = i; j < n - 1; j++) {
		elems[j] = elems[j + 1];
	}
	n--;
	return true;
}

bool Colectie::cauta(TElem elem) const {
	for (int i = 0; i < n; i++) {
		if (elems[i] == elem) return true;
	}
	return false;
}


int Colectie::nrAparitii(TElem elem) const {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (elems[i] == elem) count++;
	}
	return count;
}

int Colectie::dim() const {
	return n;
}


bool Colectie::vida() const {
	return n == 0;
}

void Colectie::adaugaAparitiiMultiple(int nr, TElem elem) {
	if ( nr < 0 ) {
		throw std::exception();
	}

	for(int i=0 ; i < nr; i++) {
		adauga(elem);
	}
}

IteratorColectie Colectie::iterator() const {
	return IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
	delete[] elems;
}
