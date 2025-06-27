
#include <exception>

#include "IteratorLP.h"
#include "Lista.h"

#include <iostream>

Lista::Lista() {
	capacitate = 10;
	dimensiune = 0;

	elems = new TElem[capacitate];
	urm = new int[capacitate];
	prec = new int[capacitate];

	primIndex = -1;
	ultim = -1;
	primLiber = 0;

	for (int i = 0; i < capacitate - 1; ++i)
		urm[i] = i + 1;
	urm[capacitate - 1] = -1;
}


/*
Best Case: Θ(1) – cand exista pozitii libere in lista
Worst Case: Θ(n) – cand se apeleaza alocaSpatiu (copierea elementelor)
Overall Complexity: O(n) – in caz de realocare, altfel Θ(1)
*/
int Lista::aloca() {
	if (primLiber == -1)
		alocaSpatiu();

	int i = primLiber;
	primLiber = urm[primLiber];
	return i;
}

/*
Best Case = Worst Case: Θ(1) – modificari simple de pointeri
Overall Complexity: Θ(1)
*/
void Lista::dealoca(int i) {
	urm[i] = primLiber;
	primLiber = i;
}

/*
Best Case = Worst Case: Θ(n) – alocare si copiere elemente in vectori de dimensiune dublata
Overall Complexity: Θ(n), unde n este capacitatea veche
*/
void Lista::alocaSpatiu() {
	int newCap = capacitate * 2;

	TElem* newElems = new TElem[newCap];
	int* newUrm = new int[newCap];
	int* newPrec = new int[newCap];

	for (int i = 0; i < capacitate; i++) {
		newElems[i] = elems[i];
		newUrm[i] = urm[i];
		newPrec[i] = prec[i];
	}
	for (int i = capacitate; i < newCap - 1; i++)
		newUrm[i] = i + 1;
	newUrm[newCap - 1] = -1;

	delete[] elems;
	delete[] urm;
	delete[] prec;

	elems = newElems;
	urm = newUrm;
	prec = newPrec;

	primLiber = capacitate;
	capacitate = newCap;
}

/*
Best Case = Worst Case: Θ(1) – returnare valoare
Overall Complexity: Θ(1)
*/
int Lista::dim() const {
	return dimensiune;
}

/*
Best Case = Worst Case: Θ(1) – verificare simpla
Overall Complexity: Θ(1)
*/
bool Lista::vida() const {
	return dimensiune == 0;
}

/*
Best Case = Worst Case: Θ(1) – construire iterator pe primul element
Overall Complexity: Θ(1)
*/
IteratorLP Lista::prim() const {
	/* de adaugat */
    return IteratorLP(*this);
}

/*
Best Case = Worst Case: Θ(1) – acces la vector prin index
Overall Complexity: Θ(1)
*/
TElem Lista::element(IteratorLP poz) const {
	if (!poz.valid())
		throw std::exception();
	return elems[poz.curent];
}

/*
Best Case = Worst Case: Θ(1) – modificare directa in vector, sau pozitie invalida
Overall Complexity: Θ(1)
*/
TElem Lista::sterge(IteratorLP& poz) {
	if (!poz.valid())
		throw std::exception();

	int i = poz.curent;
	TElem e = elems[i];

	if (prec[i] != -1)
		urm[prec[i]] = urm[i];
	else
		primIndex = urm[i];

	if (urm[i] != -1)
		prec[urm[i]] = prec[i];
	else
		ultim = prec[i];

	poz.curent = urm[i];
	dealoca(i);
	dimensiune--;

	return e;
}

/*
Best Case: Θ(1) – elementul se afla pe prima pozitie
Worst Case: Θ(n) – elementul nu exista sau este ultimul
Overall Complexity: O(n)
*/
IteratorLP Lista::cauta(TElem e) const{
    int p = primIndex;
    while (p != -1) {
        if (elems[p] == e) {
            IteratorLP it(*this);
            it.curent = p;
            return it;
        }
        p = urm[p];
    }
    // not found
    IteratorLP it(*this);
    it.curent = -1;
    return it;
}

/*
Best Case = Worst Case: Θ(1) – modificare directa in vector
Overall Complexity: Θ(1)
*/
TElem Lista::modifica(IteratorLP poz, TElem e) {
	if (!poz.valid())
		throw std::exception();
	TElem vechi = elems[poz.curent];
	elems[poz.curent] = e;
	return vechi;
}

/*
Best Case: Θ(1) – inserare in lista cu spatiu liber
Worst Case: Θ(n) – daca se apeleaza alocaSpatiu
Overall Complexity: O(n)
*/
void Lista::adauga(IteratorLP& poz, TElem e) {
	if (!poz.valid())
		throw std::exception();

	int i = aloca();
	elems[i] = e;

	int urmPoz = poz.curent;
	int precPoz = prec[urmPoz];

	urm[i] = urmPoz;
	prec[i] = precPoz;

	if (precPoz != -1)
		urm[precPoz] = i;
	else
		primIndex = i;

	prec[urmPoz] = i;
	poz.curent = i;
	dimensiune++;
}

/*
Best Case: Θ(1) – cand nu este nevoie de realocare
Worst Case: Θ(n) – cand se face alocare suplimentara (alocaSpatiu)
Overall Complexity: O(n)
*/
void Lista::adaugaInceput(TElem e) {
	int i = aloca();
	elems[i] = e;
	urm[i] = primIndex;
	prec[i] = -1;

	if (primIndex != -1)
		prec[primIndex] = i;
	else
		ultim = i;

	primIndex = i;
	dimensiune++;
}

/*
Best Case: Θ(1) – inserare directa cand exista spatiu
Worst Case: Θ(n) – in caz de realocare
Overall Complexity: O(n)
*/
void Lista::adaugaSfarsit(TElem e) {
	int i = aloca();
	elems[i] = e;
	urm[i] = -1;
	prec[i] = ultim;

	if (ultim != -1)
		urm[ultim] = i;
	else
		primIndex = i;

	ultim = i;
	dimensiune++;
}

/*
Best Case = Worst Case: Θ(1) – dealocare vectori
Overall Complexity: Θ(1)
*/
Lista::~Lista() {
	delete[] elems;
	delete[] urm;
	delete[] prec;
}
