#include "validator.h"

#include "validator.h"

void Validator::valideaza(const Produs& produs) const {
    ValidationException exception;

    int id = produs.getId();
    if (id < 100 || id > 999) {
        exception.addMessage("ID-ul produsului trebuie sa fie un numar de 3 cifre.");
    }

    string nume = produs.getNume();
    if (nume.empty()) {
        exception.addMessage("Numele produsului nu poate fi gol.");
    }

    string tip = produs.getTip();
    if (tip.empty()) {
        exception.addMessage("Tipul produsului nu poate fi gol.");
    }

    string producator = produs.getProducator();
    if (producator.empty()) {
        exception.addMessage("Producatorul produsului nu poate fi gol.");
    }

    if (!exception.getMessage().empty()) {
        throw exception;
    }
}
