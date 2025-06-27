#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	static const int M = 101;
	int m;
	int* urm;
	int primLiber;

	struct Nod {
		TElem element;
		int frecventa;
	};

	Nod* e;
	int* hashTable;
	int capacitate;
	int dimensiune;

	// helpers
	void redim();
	int d(TElem elem) const;
	int aloca();
	void dealoca(int i);
	int creeazaNod(TElem elem, int frecv);
public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		void adaugaToateElementele(const Colectie&b);

		// destructorul colectiei
		~Colectie();

};

