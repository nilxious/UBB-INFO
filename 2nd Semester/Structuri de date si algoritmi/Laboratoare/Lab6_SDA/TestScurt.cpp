#include "TestScurt.h"
#include <assert.h>
#include "Colectie.h"
#include "IteratorColectie.h"





void testAll() { //apelam fiecare functie sa vedem daca exista
	Colectie c;
	assert(c.vida() == true);
	assert(c.dim() == 0); //adaug niste elemente
	c.adauga(5);
	c.adauga(1);
	c.adauga(10);
	c.adauga(7);
	c.adauga(1);
	c.adauga(11);
	c.adauga(-3);
	assert(c.dim() == 7);
	assert(c.cauta(10) == true);
	assert(c.cauta(16) == false);
	assert(c.nrAparitii(1) == 2);
	assert(c.nrAparitii(7) == 1);
	assert(c.sterge(1) == true);
	assert(c.sterge(6) == false);
	assert(c.dim() == 6);
	assert(c.nrAparitii(1) == 1);
	IteratorColectie ic = c.iterator();
	ic.prim();
	while (ic.valid()) {
		TElem e = ic.element();
		ic.urmator();
	}	 
}

void testAdaugaToateElementele() {
	Colectie c1, c2;
	for (int i = 1; i <= 5; i++) c1.adauga(i);
	for (int i = 6; i <= 10; i++) c2.adauga(i);
	c1.adaugaToateElementele(c2);
	assert(c1.dim() == 10);
	for (int i = 1; i <= 10; i++) assert(c1.cauta(i));

	Colectie c3, c4;
	for (int i = 1; i <= 10; i++) {
		c3.adauga(i);
		c4.adauga(i);
		c4.adauga(i);
	}
	c3.adaugaToateElementele(c4);
	assert(c3.dim() == 30);
	for (int i = 1; i <= 10; i++) assert(c3.nrAparitii(i) == 3);

	Colectie c5, c6;
	c5.adaugaToateElementele(c6);
	assert(c5.vida());

	Colectie c7;
	for (int i = 1; i <= 5; i++) c7.adauga(i);
	c7.adaugaToateElementele(c7);
	assert(c7.dim() == 10);
	for (int i = 1; i <= 5; i++) assert(c7.nrAparitii(i) == 2);
}