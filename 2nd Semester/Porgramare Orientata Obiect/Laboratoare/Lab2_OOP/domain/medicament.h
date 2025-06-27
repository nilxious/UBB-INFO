#ifndef MEDICAMENT_H
#define MEDICAMENT_H

typedef struct {
    int cod;
    char nume[20];
    int concentratie;
    int cantitate;
}Medicament;

typedef struct {
    Medicament medicamente[100];
    int size;
}MedicamentList;

Medicament creeazaMedicament(int cod, char nume[20], int concentratie, int cantitate);

#endif //MEDICAMENT_H
