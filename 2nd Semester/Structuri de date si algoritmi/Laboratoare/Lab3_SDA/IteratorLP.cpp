#include "IteratorLP.h"
#include <exception>

IteratorLP::IteratorLP(const Lista& l) : lista(l) {
	curent = lista.primIndex;
}

/*
Best Case = Worst case: Θ(1) – se face o simpla atribuire, indiferent de marimea listei.
Overall Complexity: Θ(1)
 */
void IteratorLP::prim() {
	curent = lista.primIndex;
}

/*
Best Case = Worst Case: Θ(1) – se executa un singur pas
Overall Complexity: Θ(1)
 */
void IteratorLP::urmator() {
	if (!valid())
		throw std::exception();
	curent = lista.urm[curent];
}

/*
Best Case = Worst case: Θ(1)
Overall Complexity: Θ(1)
 */
bool IteratorLP::valid() const {
	return curent != -1;
}

/*
Best Case = Worst case: Θ(1)
Overall Complexity: Θ(1)
*/
TElem IteratorLP::element() const {
	if (!valid())
		throw std::exception();
	return lista.elems[curent];
}


/* PSEUDOCOD
FUNCȚIE avanseazaKPasi(k)
	DACA NU valid() ATUNCI
		aruncă excepție
	SFARSIT DACA

	DACA k ≤ 0 ATUNCI
		aruncă excepție
	SFARSIT DACA

	CAT TIMP k > 0 SI curent ≠ -1 EXECUTĂ
		curent ← lista.urm[curent]   // mută iteratorul la următorul element
		k ← k - 1
	SFARSIT CAT TIMP

	// Dacă k > 0 înseamnă că am depășit lista, curent = -1 (invalid)
SFARSIT FUNCȚIE
*/

/* COMPLEXITATI
Best Case Θ(1) - Se întampla când k=1 (iteratorul avanseaza doar un singur pas), sau k <= 0, sau iterator invalid
Worst Case Θ(k) - Se întampla când k≥dimensiunea listei ramase (iteratorul parcurge toate elementele pana devine invalid)
Overall complexity O(k) - deoarece în cel mai rau caz, metoda trebuie sa parcurga k elemente sau până la sfarsitul listei
 */
void IteratorLP::avanseazaKPasi(int k) {
	if (!valid())
		throw std::exception();
	if (k <= 0)
		throw std::exception();

	while (k > 0 && valid()) {
		curent = lista.urm[curent];
		k--;
	}
}