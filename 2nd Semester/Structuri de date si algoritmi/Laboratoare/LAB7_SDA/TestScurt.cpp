#include "TestScurt.h"
#include "Colectie.h"
#include "IteratorColectie.h"
#include <cassert>
#include <stdexcept>

void testAll() {
	Colectie c;
	c.adauga(5);
	c.adauga(6);
	c.adauga(0);
	c.adauga(5);
	c.adauga(10);
	c.adauga(8);

	assert(c.dim() == 6);
	assert(c.nrAparitii(5) == 2);

	assert(c.sterge(5) == true);
	assert(c.dim() == 5);

	assert(c.cauta(6) == true);
	assert(c.vida() == false);

	IteratorColectie ic = c.iterator();
	assert(ic.valid() == true);
	while (ic.valid()) {
		ic.element();
		ic.urmator();
	}
	assert(ic.valid() == false);
	ic.prim();
	assert(ic.valid() == true);

}

void testAdaugaAparitiiMultiple() {
	Colectie c;

	// Test 1: Adaugare element nou cu nr aparitii
	c.adaugaAparitiiMultiple(3, 10);
	assert(c.nrAparitii(10) == 3);
	assert(c.dim() == 3);

	// Test 2: Adaugare suplimentara la acelasi element
	c.adaugaAparitiiMultiple(2, 10);
	assert(c.nrAparitii(10) == 5);
	assert(c.dim() == 5);

	// Test 3: Adaugare alt element
	c.adaugaAparitiiMultiple(4, 20);
	assert(c.nrAparitii(20) == 4);
	assert(c.dim() == 9);

	// Test 4: Combinat cu adauga simplu
	c.adauga(10);
	assert(c.nrAparitii(10) == 6);
	assert(c.dim() == 10);

	// Test 5: Arunca exceptie pentru nr <= 0
	try {
		c.adaugaAparitiiMultiple(0, 5);
		assert(false); // nu ar trebui sa ajunga aici
	} catch (std::invalid_argument&) {
		assert(true);
	}

	try {
		c.adaugaAparitiiMultiple(-1, 5);
		assert(false); // nu ar trebui sa ajunga aici
	} catch (std::invalid_argument&) {
		assert(true);
	}

	// Test 6: Adaugare in arbore mare
	for (int i = 0; i < 100; i += 2) {
		c.adaugaAparitiiMultiple(1, i); // adauga 0,2,4,...,98
	}

	for (int i = 0; i < 100; i += 2) {
		assert(c.nrAparitii(i) == 1);
	}

	printf("Teste adaugaAparitiiMultiple() trecute cu succes!\n");
}
