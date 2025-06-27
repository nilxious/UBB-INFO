
#include "CP.h"
#include <exception>
#include <stdio.h>

using namespace std;


CP::CP(Relatie r) {
	/* de adaugat */
	this->rel = r;
	this->prim = nullptr;
}


void CP::adauga(TElem e, TPrioritate p) {
	/* de adaugat */
	Nod* nou = new Nod(make_pair(e, p));
	if (prim == nullptr || !rel(prim->e.second, p)) {
		nou->next = prim;
		prim = nou;
	} else {
		Nod* curent = prim;
		while (curent->next != nullptr && rel(curent->next->e.second, p)) {
			curent = curent->next;
		}
		nou->next = curent->next;
		curent->next = nou;
	}
}

//arunca exceptie daca coada e vida
Element CP::element() const {
	if (vida()) {
		throw std::exception();
	}
	return prim->e;
}

Element CP::sterge() {
	if (vida()) {
		throw std::exception();
	}
	Nod* temp = prim;
	Element elem = temp->e;
	prim = prim->next;
	delete temp;
	return elem;
}

bool CP::vida() const {
	return prim == nullptr;
}

void CP::imbinare(CP& cp) {
	Nod* curent = cp.prim;
	while (curent != nullptr) {
		this->adauga(curent->e.first, curent->e.second);
		curent = curent->next;
	}
}



CP::~CP() {
	while (!vida()) {
		sterge();
	}
};

