#include <assert.h>
#include <exception>

#include "TestExtins.h"
#include "IteratorLP.h"
#include "Lista.h"

using namespace std;

void testAllExtins() {
    Lista lista = Lista();
    assert(lista.vida());
    IteratorLP it0 = lista.prim();
    assert(!it0.valid());
    try {
        it0.element();
        assert(false);
    } catch (exception&) {
        assert(true);
    }

    lista.adaugaSfarsit(1);
    assert(lista.dim() == 1);
    IteratorLP it = lista.prim();
    assert(it.element() == 1);

    IteratorLP it2 = lista.prim();
    for (int i = 0; i < 100; i++) {
        lista.adaugaSfarsit(i);
        if (i <= 50) {
            it2.urmator();
        }
        it.urmator();
        assert(it.element() == i);
    }

    assert(it2.element() == 50);
    assert(lista.dim() == 101);
    assert(it.valid());
    it.urmator();
    assert(!it.valid());
    try {
        lista.element(it);
        assert(false);
    } catch (exception&) {
        assert(true);
    }

    IteratorLP it3 = lista.cauta(50);
    assert(it3.valid());
    assert(it3.element() == 50);
    TElem oldVal = lista.modifica(it3, 51);
    assert(oldVal == 50);
    assert(it3.element() == it2.element());

    IteratorLP it3_2 = lista.cauta(50);
    assert(!it3_2.valid());  // FIXED: 50 no longer exists

    try {
        lista.adauga(it3_2, 0);
        assert(false);
    } catch (exception&) {
        assert(true);
    }

    IteratorLP it4 = lista.cauta(99);
    assert(it4.element() == 99);
    it4.urmator();
    assert(!it4.valid());
    try {
        it4.urmator();
        assert(false);
    } catch (exception&) {
        assert(true);
    }

    // Add element after 51
    IteratorLP it3_3 = lista.cauta(51);
    lista.adauga(it3_3, 150);
    assert(it3_3.element() == 150);

    // Now modify 51 back to 50
    IteratorLP it5 = lista.cauta(51);
    lista.modifica(it5, 50);
    assert(lista.element(it5) == 50);

    // Delete 150
    TElem deleted = lista.sterge(it3_3);
    assert(deleted == 150);

    // Invalid modifications
    try {
        lista.modifica(it, 0);
        assert(false);
    } catch (exception&) {
        assert(true);
    }
    try {
        lista.sterge(it);
        assert(false);
    } catch (exception&) {
        assert(true);
    }
}
