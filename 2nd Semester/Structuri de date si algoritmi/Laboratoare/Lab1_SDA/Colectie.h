#pragma once

typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	TElem* elems;
	int n;
	int cap;
	void redimensioneaza();

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

		//operatie extra
		void adaugaAparitiiMultiple(int nr, TElem elem);

		/* Pseudocod operatie extra
		void adaugaAparitiiMultiple(nr, elem)
			daca nr < 0 atunci
				arunca exceptie
			sfarsit daca

			pentru i de la 0 la nr - 1
				adauga(elem)
			sfarsit pentru
		sfarsit functie
		*/


		/*
		 Complexitati

		Best case = worst case = Theta(n * nr),
		-se executa adaugarea de nr ori
		-daca elementul este cel mai mare din colectie, se va adauga la final (while se executa de 0 ori si for de n ori)
		-daca elementul este cel mai mic, while se executa de n ori si for de 0 ori)

		Complexitate overall: Theta(n * nr)
		*/

		// destructorul colectiei
		~Colectie();
};

