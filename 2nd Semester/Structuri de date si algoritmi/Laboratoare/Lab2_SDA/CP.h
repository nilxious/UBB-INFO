#pragma once
#include <vector>
#include <utility>

using namespace std;

typedef int TElem;
typedef int TPrioritate;

typedef std::pair<TElem, TPrioritate> Element;

typedef bool (*Relatie)(TPrioritate p1, TPrioritate p2);

struct Nod {
	Element e;
	Nod* next;
	Nod(Element elem, Nod* urm = nullptr) : e(elem), next(urm) {}
};

class CP {
private:
	/* aici reprezentarea */
	Nod* prim;
	Relatie rel;
public:
	//constructorul implicit
	CP(Relatie r);

	//adauga un element in CP
	/*
	 *Best case Θ(1) - Se intampla atunci cand adaugam un element cu cea mai mare prioritate
	 *Worst case Θ(n) - Se intampla atunci cand adaugam un element cu cea mai mica priroritate, fiind necesar
	 *sa parcurgem toata coada, n = nr noduri
	 *Overall complexity = O(n)
	 */
	void adauga(TElem e, TPrioritate p);

	//acceseaza elementul cel mai prioritar in raport cu relatia de ordine
	//arunca exceptie daca CP e vida
	Element element() const;

	//sterge elementul cel mai prioritar si il returneaza
	//arunca exceptie daca CP e vida
	Element sterge();

	//verifica daca CP e vida;
	bool vida() const;

	/* PSEUDOCOD
	void imbinare(cp)
		curent ← cp.prim
		cat timp curent ≠ NULL execută
			adauga(curent.e.first, curent.e.second)
			curent ← [curent].next
		sfarsit cat timp
	sfarsit functie
	*/

	/* COMPLEXITATI
	Best Case Θ(m) - Se intampla daca toate elementele din coada cp au prioritati mai mari decat toate elementele
	din coada curenta, m - numarul de noduri ale cozii cp
	Worst Case Θ(m*n) - Se intampla daca toate elementele din coada cp au prirotati mai mici decat toatele elementele
	din coada curenta, m - nr noduri ale cozii cp, n - nr de noduri ale cozii curente
	Overall complexity O(m*n) - deoarece in cel mai rau caz, fiecare insertie in coada curenta necesita o parcurgere completa
	a cozii
	 */
	void imbinare(CP& cp);

	// destructorul cozii
	~CP();

};
