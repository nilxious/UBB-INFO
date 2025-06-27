#include "Colectie.h"
#include <iostream>
#include <stdexcept>

using namespace std;

bool rel(TElem e1, TElem e2) {
	return e1 <= e2;
}

Colectie::Colectie() {
	capacity = 10;
	nodes = new Node[capacity];
	root = -1;
	firstEmpty = 0;
	size = 0;

	for (int i = 0; i < capacity - 1; ++i)
		nodes[i].left = i + 1;
	nodes[capacity - 1].left = -1;
}


/*
 Best Case = Worst Case = Theta(n), n = toate nodurile
 */
void Colectie::resize() {
	int newCapacity = capacity * 2;
	Node* newNodes = new Node[newCapacity];

	for (int i = 0; i < capacity; ++i)
		newNodes[i] = nodes[i];

	for (int i = capacity; i < newCapacity - 1; ++i)
		newNodes[i].left = i + 1;
	newNodes[newCapacity - 1].left = -1;

	firstEmpty = capacity;
	delete[] nodes;
	nodes = newNodes;
	capacity = newCapacity;
}


int Colectie::createNode(TElem elem) {
	if (firstEmpty == -1)
		resize();

	int newPos = firstEmpty;
	firstEmpty = nodes[firstEmpty].left;

	nodes[newPos].element = elem;
	nodes[newPos].left = -1;
	nodes[newPos].right = -1;

	return newPos;
}

/*
Caz favorabil: Θ(1) — se adaugă în rădăcină.

Caz defavorabil: Θ(h) — se parcurge arborele până la frunză.

Complexitate generală: O(h)
 */
void Colectie::adauga(TElem e) {
	if (root == -1) {
		root = createNode(e);
		size++;
		return;
	}

	int current = root;
	int parent = -1;

	while (current != -1) {
		parent = current;
		if (rel(e, nodes[current].element))
			current = nodes[current].left;
		else
			current = nodes[current].right;
	}

	int newNode = createNode(e);
	if (rel(e, nodes[parent].element))
		nodes[parent].left = newNode;
	else
		nodes[parent].right = newNode;

	size++;
}


/*
Caz favorabil: Θ(1) — elementul e în rădăcină și are count > 1.

Caz defavorabil: Θ(h) — elementul e la ultima frunză, cu doi copii.

Complexitate generală: O(h)
 */
bool Colectie::sterge(TElem e) {
	bool removed = false;
	root = removeRec(root, e, removed);
	if (removed)
		size--;
	return removed;
}

/*
Caz favorabil:
	Elementul e găsit imediat (în rădăcină) și are count > 1 - Θ(1)

Caz defavorabil:
	Trebuie parcurse ramuri până la frunză, posibil și căutarea minimului în subarborele drept
		Θ(h)
	(h = înălțimea arborelui)

Overall complexity: O(h)
*/
int Colectie::removeRec(int node, TElem e, bool& removed) {
	if (node == -1)
		return -1;

	if (e == nodes[node].element) {
		removed = true;
		// 0 or 1 copil
		if (nodes[node].left == -1)
			return deallocateAndReturn(nodes[node].right, node);
		if (nodes[node].right == -1)
			return deallocateAndReturn(nodes[node].left, node);
		// 2 copii
		int minNode = minimum(nodes[node].right);
		nodes[node].element = nodes[minNode].element;
		nodes[node].right = removeRec(nodes[node].right, nodes[minNode].element, removed);
		return node;
	} else if (rel(e, nodes[node].element)) {
		nodes[node].left = removeRec(nodes[node].left, e, removed);
	} else {
		nodes[node].right = removeRec(nodes[node].right, e, removed);
	}

	return node;
}

int Colectie::deallocateAndReturn(int child, int node) {
	deallocateNode(node);
	return child;
}


int Colectie::minimum(int node) const {
	while (nodes[node].left != -1)
		node = nodes[node].left;
	return node;
}

void Colectie::deallocateNode(int pos) {
	nodes[pos].left = firstEmpty;
	firstEmpty = pos;
}

/*
	Caz favorabil: Θ(1) — găsit în rădăcină.

	Caz defavorabil: Θ(h) — căutare eșuată sau la frunză.

	Complexitate generală: O(h)
 */
int Colectie::search(TElem elem) const {
	int current = root;
	while (current != -1) {
		if (nodes[current].element == elem)
			return current;
		if (rel(elem, nodes[current].element))
			current = nodes[current].left;
		else
			current = nodes[current].right;
	}
	return -1;
}
/*
	Caz favorabil: Θ(1) — găsit în rădăcină.

	Caz defavorabil: Θ(h) — căutare eșuată sau la frunză.

	Complexitate generală: O(h)
 */
bool Colectie::cauta(TElem elem) const {
	return search(elem) != -1;
}


/*
Intern, folosește search(e)

Complexitate: O(h)
 */
int Colectie::nrAparitii(TElem elem) const {
	return nrAparitiiRec(root, elem);
}

int Colectie::nrAparitiiRec(int node, TElem elem) const {
	if (node == -1)
		return 0;

	int count = 0;
	if (nodes[node].element == elem)
		count = 1;

	return count + nrAparitiiRec(nodes[node].left, elem) + nrAparitiiRec(nodes[node].right, elem);
}

int Colectie::dim() const {
	return size;
}

bool Colectie::vida() const {
	return size == 0;
}

IteratorColectie Colectie::iterator() const {
	return IteratorColectie(*this);
}

Colectie::~Colectie() {
	delete[] nodes;
}
/*
FUNCTIE adaugaAparitiiMultiple(nr, elem)
	DACA nr <= 0 ATUNCI
		ARUNCA exceptie "numar invalid"
	SFARSIT DACA

	nod ← root
	parinte ← NIL

	CAT TIMP nod ≠ NIL EXECUTA
		DACA nod.element == elem ATUNCI
			nod.count ← nod.count + nr
			size ← size + nr
			RETURN
		SFARSIT DACA

		parinte ← nod
		DACA elem < nod.element ATUNCI
			nod ← nod.left
		ALT_FEL
			nod ← nod.right
		SFARSIT DACA
	SFARSIT CAT TIMP

	// Elementul nu exista, adauga nod nou
	nou ← createNode(elem)
	nodes[nou].count ← nr
	size ← size + nr

	DACA parinte == NIL ATUNCI
		root ← nou
	ALT_FEL DACA elem < parinte.element ATUNCI
		parinte.left ← nou
	ALT_FEL
		parinte.right ← nou
	SFARSIT DACA
SFARSIT FUNCTIE
*/

/*
 	h = inaltimea arborelui

	n = numar total de noduri din arbore

Caz favorabil: elem se gaseste direct in radacina - Θ(1)

Caz defavorabil: elem nu exista si se adauga in frunza ultimului nivel - Θ(h)

Overall Complexity: O(n)

 */
void Colectie::adaugaAparitiiMultiple(int nr, TElem elem) {
	if (nr <= 0)
		throw std::invalid_argument("Numarul de aparitii trebuie sa fie pozitiv.");

	for (int i = 0; i < nr; ++i)
		adauga(elem);
}

