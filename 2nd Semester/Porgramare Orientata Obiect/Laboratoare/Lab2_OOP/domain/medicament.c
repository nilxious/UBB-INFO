#include <string.h>
#include "Medicament.h"


Medicament creeazaMedicament(int cod, char nume[20], int concentratie, int cantitate) {
    Medicament medicament_nou;

    medicament_nou.cod = cod;
    strncpy(medicament_nou.nume, nume, sizeof(medicament_nou.nume)-1);
    medicament_nou.nume[sizeof(medicament_nou.nume)-1] = '\0';
    medicament_nou.concentratie = concentratie;
    medicament_nou.cantitate=cantitate;

    return medicament_nou;
}


