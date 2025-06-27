#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie() {
	m = M;
	capacitate = 200;
	dimensiune = 0;
	e = new Nod[capacitate];
	urm = new int[capacitate];
	hashTable = new int[m];
	for (int i = 0; i < m; i++)
		hashTable[i] = -1;
	for (int i = 0; i < capacitate - 1; i++)
		urm[i] = i + 1;
	urm[capacitate - 1] = -1;
	primLiber = 0;
}

int Colectie::d(TElem elem) const {
	return abs(elem) % m;
}

int Colectie::aloca() {
	int i = primLiber;
	if (i != -1)
		primLiber = urm[primLiber];
	return i;
}

void Colectie::dealoca(int i) {
	urm[i] = primLiber;
	primLiber = i;
}

int Colectie::creeazaNod(TElem elem, int frecv) {
	int i = aloca();
	if (i == -1) {
		redim();
		i = aloca();
	}
	e[i].element = elem;
	e[i].frecventa = frecv;
	urm[i] = -1;
	return i;
}

void Colectie::redim() {
	int oldCap = capacitate;
	Nod* oldE = e;
	int* oldUrm = urm;
	int* oldHashTable = hashTable;
	int oldM = m;

	capacitate *= 2;
	m = capacitate;

	e = new Nod[capacitate];
	urm = new int[capacitate];
	hashTable = new int[m];

	for (int i = 0; i < m; i++) {
		hashTable[i] = -1;
	}

	for (int i = 0; i < capacitate - 1; i++) {
		urm[i] = i + 1;
	}
	urm[capacitate - 1] = -1;
	primLiber = 0;

	for (int i = 0; i < oldM; i++) {
		int p = oldHashTable[i];
		while (p != -1) {
			TElem elem = oldE[p].element;
			int frecv = oldE[p].frecventa;

			int newHash = d(elem);

			int newNode = aloca();
			if (newNode == -1) {
				throw std::bad_alloc();
			}

			e[newNode].element = elem;
			e[newNode].frecventa = frecv;

			urm[newNode] = hashTable[newHash];
			hashTable[newHash] = newNode;

			p = oldUrm[p];
		}
	}

	delete[] oldE;
	delete[] oldUrm;
	delete[] oldHashTable;
}

void Colectie::adauga(TElem elem) {
	if (primLiber == -1) {
		redim();
	}

	int i = d(elem);
	int p = hashTable[i];
	while (p != -1) {
		if (e[p].element == elem) {
			e[p].frecventa++;
			dimensiune++;
			return;
		}
		p = urm[p];
	}

	int nou = creeazaNod(elem, 1);
	urm[nou] = hashTable[i];
	hashTable[i] = nou;
	dimensiune++;
}


bool Colectie::sterge(TElem elem) {
	int i = d(elem);
	int p = hashTable[i];
	int prev = -1;

	while (p != -1) {
		if (e[p].element == elem) {
			e[p].frecventa--;
			dimensiune--;
			if (e[p].frecventa == 0) {
				if (prev == -1)
					hashTable[i] = urm[p];
				else
					urm[prev] = urm[p];
				dealoca(p);
			}
			return true;
		}
		prev = p;
		p = urm[p];
	}

	return false;
}


bool Colectie::cauta(TElem elem) const {
		int i = d(elem);
		int p = hashTable[i];
		while (p != -1) {
			if (e[p].element == elem)
				return true;
			p = urm[p];
		}
		return false;
}

int Colectie::nrAparitii(TElem elem) const {
		int i = d(elem);
		int p = hashTable[i];
		while (p != -1) {
			if (e[p].element == elem)
				return e[p].frecventa;
			p = urm[p];
		}
		return 0;
}


int Colectie::dim() const {
	return dimensiune;
}


bool Colectie::vida() const {
	return dimensiune == 0;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

/*
 n - nr total de elemente din colectia b
 m - dimensiunea tabelei de dispersie curente
Caz favorabil: Θ(n) - cand toate elementele din b sunt in primul bucket pe prima pozitie

Caz defavorabil: Θ(n*m) - cand toate elementele din b exista deja si se afla in ultimul bucket pe ultima pozitie

Complexitate generala: O(n + m)

PSEUDOCOD:
FUNCTIE adaugaToateElementele(b)
	PENTRU FIECARE galeata IN b EXECUTA
		nod ← galeata.primul
		CAT TIMP nod ≠ NIL EXECUTA
			elem ← nod.element
			frecventa ← nod.frecventa

			// Cauta în colectia curenta
			gasit ← fals
			nod_curent ← tabela_hash_curentă[hash(elem)]

			CAT TIMP nod_curent ≠ NIL SI NU gasit EXECUTA
				DACA nod_curent.element = elem ATUNCI
					nod_curent.frecventa += frecventa
					dimensiune_colectie += frecventa
					gasit ← adevarat
				SFARSIT DACA
				nod_curent ← nod_curent.urmator
			SFARSIT CAT TIMP

			DACA NU gasit ATUNCI
				DACA nu_are_spatiu_liber ATUNCI
					redimensioneaza_tabela()
					RECALCULEAZA hash(elem)
				SFARSIT DACA

				nod_nou ← creeaza_nod(elem, frecventa)
				INSEREAZA nod_nou la inceputul galetiii
				dimensiune_colectie += frecventa
			SFARSIT DACA

			nod ← nod.urmator
		SFARSIT CAT TIMP
	SFARSIT PENTRU
SFARSIT FUNCTIE
 */
void Colectie::adaugaToateElementele(const Colectie& b) {
	// Iteram peste fiecare bucket din tabela
	for (int i = 0; i < b.m; i++) {
		int p = b.hashTable[i];
		while (p != -1) {
			TElem elem = b.e[p].element;
			int frecv = b.e[p].frecventa;

			// Verificam daca elementul deja se afla in colectia noastra
			int j = d(elem);
			int q = hashTable[j];
			bool found = false;

			while (q != -1 && !found) {
				if (e[q].element == elem) {
					e[q].frecventa += frecv;
					dimensiune += frecv;
					found = true;
				}
				q = urm[q];
			}

			// Daca nu exista elementul, cream un nod nou
			if (!found) {
				if (primLiber == -1) {
					redim();
					j = d(elem); // Rehash dupa resize
				}
				int nou = creeazaNod(elem, frecv);
				urm[nou] = hashTable[j];
				hashTable[j] = nou;
				dimensiune += frecv;
			}

			p = b.urm[p];
		}
	}
}

Colectie::~Colectie() {
		delete[] e;
		delete[] urm;
		delete[] hashTable;
}


