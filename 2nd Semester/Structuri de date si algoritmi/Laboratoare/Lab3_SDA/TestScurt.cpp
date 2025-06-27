#include "TestScurt.h"

#include <assert.h>
#include <exception>


#include "Lista.h"
#include "IteratorLP.h"



using namespace std;

void testAll(){
	Lista lista = Lista();
	assert(lista.dim() == 0);
	assert(lista.vida());

    lista.adaugaSfarsit(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());

    IteratorLP it = lista.cauta(1);
    assert(it.valid());
    assert(it.element() == 1);
    it.urmator();
    assert(!it.valid());
    it.prim();
    assert(it.valid());
    assert(it.element() == 1);

    assert(lista.sterge(it) == 1);
    assert(lista.dim() == 0);
    assert(lista.vida());

    lista.adaugaInceput(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());

}

void testAvanseazaKPasi() {
	Lista lista;

	// Test pe lista vida
	IteratorLP it0 = lista.prim();
	assert(!it0.valid());
	try {
		it0.avanseazaKPasi(1);
		assert(false);
	} catch (exception&) {
		assert(true);
	}

	// Populam lista cu valori 1, 2, 3, 4, 5
	for (int i = 1; i <= 5; ++i) {
		lista.adaugaSfarsit(i);
	}

	IteratorLP it = lista.prim();
	assert(it.valid());
	assert(it.element() == 1);

	// Avansam 1 pas
	it.avanseazaKPasi(1);
	assert(it.valid());
	assert(it.element() == 2);

	// Avansam inca 2 pasi
	it.avanseazaKPasi(2);
	assert(it.valid());
	assert(it.element() == 4);

	// Avansam 1 pas (ajungem la 5)
	it.avanseazaKPasi(1);
	assert(it.valid());
	assert(it.element() == 5);

	// Avansam 1 pas - iteratorul devine invalid
	it.avanseazaKPasi(1);
	assert(!it.valid());

	// Avansam k cand iteratorul este deja invalid
	try {
		it.avanseazaKPasi(1);
		assert(false);
	} catch (exception&) {
		assert(true);
	}

	// Avansam cu k negativ
	IteratorLP it2 = lista.prim();
	try {
		it2.avanseazaKPasi(0);
		assert(false);
	} catch (exception&) {
		assert(true);
	}

	try {
		it2.avanseazaKPasi(-3);
		assert(false);
	} catch (exception&) {
		assert(true);
	}

	// Avansam cu un k mai mare decat lungimea ramasa
	IteratorLP it3 = lista.prim(); // pe 1
	it3.avanseazaKPasi(10); // lista are doar 5 elemente
	assert(!it3.valid());
}


