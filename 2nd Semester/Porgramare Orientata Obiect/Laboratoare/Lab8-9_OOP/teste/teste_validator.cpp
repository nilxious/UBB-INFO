#include "teste_validator.h"
#include "../validator.h"
#include <cassert>
#include <iostream>
using std::cout;

void TesteValidator::test_valideaza() {
    Validator validator;

    try {
        Produs validProdus("Laptop", 5000, "Electronics", "Dell", 123);
        validator.valideaza(validProdus);
    } catch (const ValidationException&) {
        assert(false);
    }

    try {
        Produs invalidProdus("", 5000, "Electronics", "Dell", 123);
        validator.valideaza(invalidProdus);
        assert(false);
    } catch (const ValidationException& ex) {
        assert(ex.getMessage() == "Numele produsului nu poate fi gol.");
    }

    try {
        Produs invalidProdus("Phone", 5000, "", "Apple", 123);
        validator.valideaza(invalidProdus);
        assert(false);
    } catch (const ValidationException& ex) {
        assert(ex.getMessage() == "Tipul produsului nu poate fi gol.");
    }

    try {
        Produs invalidProdus("Monitor", 5000, "Electronics", "", 123);
        validator.valideaza(invalidProdus);
        assert(false);
    } catch (const ValidationException& ex) {
        assert(ex.getMessage() == "Producatorul produsului nu poate fi gol.");
    }

    try {
        Produs invalidProdus("Mouse", 5000, "Peripherals", "Logitech", 99);
        validator.valideaza(invalidProdus);
        assert(false);
    } catch (const ValidationException& ex) {
        assert(ex.getMessage() == "ID-ul produsului trebuie sa fie un numar de 3 cifre.");
    }

    try {
        Produs invalidProdus("Keyboard", 5000, "Peripherals", "Corsair", 1000);
        validator.valideaza(invalidProdus);
        assert(false);
    } catch (const ValidationException& ex) {
        assert(ex.getMessage() == "ID-ul produsului trebuie sa fie un numar de 3 cifre.");
    }

    try {
        Produs multipleErrors("", 5000, "", "", 50);
        validator.valideaza(multipleErrors);
        assert(false);
    } catch (const ValidationException& ex) {
        assert(ex.getMessage() ==
               "ID-ul produsului trebuie sa fie un numar de 3 cifre.\n"
               "Numele produsului nu poate fi gol.\n"
               "Tipul produsului nu poate fi gol.\n"
               "Producatorul produsului nu poate fi gol.");
    }
}

void TesteValidator::run_all_tests() {
    test_valideaza();
    cout << "Testele din validator au mers\n";
}
