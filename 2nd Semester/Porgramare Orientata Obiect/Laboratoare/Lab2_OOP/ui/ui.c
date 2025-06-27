#include "Ui.h"
#include <stdio.h>

Ui creeaza_ui(Service* service) {
    Ui ui;
    ui.service = service;
    return ui;
}

void ui_afiseaza_meniu() {
    printf("\n");
    printf("-----------MENIU-----------\n");
    printf("1. Adauga medicament\n");
    printf("2. Actualizeaza medicament\n");
    printf("3. Sterge intreg stoc dintr-un medicament\n");
    printf("4. Vizualizare medicamente din stoc, ordonat dupa nume, cantitate (crescator/descrescator)\n");
    printf("5. Vizualizare lista de medicamente dupa un criteriu. Medicamentele unde stocul disponibil este mai mic decat o valoare data; medicamente cu numele incepand cu o litera data\n");
    printf("6. Afiseaza stocul\n");
    printf("7. Exit\n");
    printf("\n");
}

void ui_afiseaza_stoc(Ui* ui) {
    int nr_elemente = ui->service->repo->stoc_curent;
    Medicament medicament;
    for(int i=0;i<nr_elemente;i++){
        medicament = ui->service->repo->stoc[i];
        printf("Nume: %s, Cantitate: %d, Concentratie: %d, Cod: %d\n", medicament.nume, medicament.cantitate, medicament.concentratie, medicament.cod);
    }
    printf("\n");
}

void ui_afiseaza_lista_medicamente(Medicament lista[], int size) {
    for(int i=0; i<size;i++) {
        printf("Nume: %s, Cantitate: %d, Concentratie: %d, Cod: %d\n", lista[i].nume, lista[i].cantitate, lista[i].concentratie, lista[i].cod);
    }
    printf("\n");
}

void ui_adauga_medicament(Ui* ui) {
    int cod, concentratie, cantitate;
    char nume[20];

    printf("Codul medicamentului: \n");
    scanf("%d", &cod);

    printf("Numele medicamentului: \n");
    scanf("%19s", nume);

    printf("Concentratia medicamentului: \n");
    scanf("%d", &concentratie);

    printf("Cantitate medicamentului: \n");
    scanf("%d", &cantitate);

    int rezultat = add_medicament(ui->service, cod, nume, concentratie, cantitate);

    if (rezultat == 0) {
        printf("Eroare: Deja exista un medicament cu acest cod sau nu mai exista spatiu de stocare!\n");
    } else if (rezultat == -7) {
        printf("Eroare: Datele medicamentului sunt invalide!\n");
    } else if (rezultat == 2) {
        printf("Cantitatea medicamentului a fost modificata cu succes!\n");
    } else
        printf("Medicament adaugat cu succes!\n");

}

void ui_actualizeaza_medicament(Ui* ui) {
    int cod, concentratie, cantitate;
    char nume[20];

    printf("Codul medicamentului pe care vrei sa il modifici: \n");
    scanf("%d", &cod);

    printf("Numele nou al medicamentului: \n");
    scanf("%19s", nume);

    printf("Concentratia noua medicamentului: \n");
    scanf("%d", &concentratie);

    printf("Cantitate noua a medicamentului: \n");
    scanf("%d", &cantitate);

    int rezultat = modify_medicament(ui->service, cod, nume, concentratie, cantitate);

    if (rezultat == -7) printf("Datele introduse sunt invalide\n");
    else if (rezultat == -1) printf("Nu exista nici un medicament in stoc cu acest cod\n");
    else if (rezultat == 0) printf("Nu mai exista spatiu in stoc\n");
    else if (rezultat == 1) printf("Modificare realizata cu succes\n");
}

void ui_sterge_stoc_intreg(Ui* ui) {
    int cod;

    printf("Introduce codul medicamentului pe care vrei sa il stergi\n");
    scanf("%d", &cod);

    int rezultat = remove_medicament(ui->service, cod);
    if (rezultat == -3) printf("Nu mai exista nici un medicament in stoc\n");
    else if (rezultat == -7) printf("Codul introdus nu este valid\n");
    else if (rezultat == -1) printf("Nu s-a gasit un medicament cu acest cod\n");
    else if (rezultat == 1) printf("Stocul intreg al medicamentului a fost sters cu succes\n");
}

void ui_vizualizare_filtrata1(Ui* ui) {
    MedicamentList result ;
    int cantitate;

    printf("Valoarea dupa care se va aplica filtrul 1: \n");
    scanf("%d", &cantitate);

    result = filter1(ui->service, cantitate);

    if (result.size > 0) {
        ui_afiseaza_lista_medicamente(result.medicamente, result.size);
    } else {
        printf("Nu au fost gasite medicamente care sa corespunda filtrului.\n");
    }
}

void ui_vizualizare_filtrata2(Ui* ui) {
    MedicamentList result ;
    char litera;

    printf("Litera dupa care se va aplica filtrul 2: \n");
    getchar();
    scanf("%c", &litera);

    result = filter2(ui->service, litera);

    if (result.size > 0) {
        ui_afiseaza_lista_medicamente(result.medicamente, result.size);
    } else {
        printf("Nu au fost gasite medicamente care sa corespunda filtrului.\n");
    }
}

void ui_ordonare1(Ui* ui, int tip_ordonare) {
    Medicament* ordonate = ordered1(ui->service, tip_ordonare);
    for(int i=0; i<ui->service->repo->stoc_curent; i++) {
        printf("Nume: %s, Cantitate: %d, Concentratie: %d, Cod: %d\n", ordonate[i].nume, ordonate[i].cantitate, ordonate[i].concentratie, ordonate[i].cod);
    }
    printf("\n");
}

void ui_ordonare2(Ui* ui, int tip_ordonare) {
    Medicament* ordonate = ordered2(ui->service, tip_ordonare);
    for(int i=0; i<ui->service->repo->stoc_curent; i++) {
        printf("Nume: %s, Cantitate: %d, Concentratie: %d, Cod: %d\n", ordonate[i].nume, ordonate[i].cantitate, ordonate[i].concentratie, ordonate[i].cod);
    }
    printf("\n");
}

void ui_vizualizare_filtrata(Ui* ui) {
    int optiune;

    printf("Alege una dintre cele doua filtrari: \n");
    printf("1 - Cantitatea mai mica decat o valoare data\n");
    printf("2 - Medicamentele care incep cu o litera data\n");

    scanf("%d", &optiune);
    switch (optiune) {
        case 1:
            ui_vizualizare_filtrata1(ui);
            break;
        case 2:
            ui_vizualizare_filtrata2(ui);
            break;
        default:
            printf("Aceasta nu este o optiune valida\n");
            break;
    }
}

void ui_vizualizare_medicamente_ordonate(Ui* ui) {
    int optiune1, optiune2;
    int tip_ordonare = 0;

    printf("Alege una dintre cele doua criterii de sortare a listei de medicamente: \n");
    printf("1 - Ordonare dupa nume\n");
    printf("2 - Ordonare dupa cantitate\n");

    scanf("%d", &optiune1);

    printf("Alege una dintre cele doua tipuri de sortari: \n");
    printf("1 - Crescatoare\n");
    printf("2 - Descrescatoare\n");

    scanf("%d", &optiune2);

    switch (optiune2) {
        case 1:
            tip_ordonare = 1;
            break;
        case 2:
            tip_ordonare = -1;
            break;
        default:
            printf("Aceasta nu este o optiune valida\n");
            return;
    }

    switch (optiune1) {
        case 1:
            ui_ordonare1(ui, tip_ordonare);
            break;
        case 2:
            ui_ordonare2(ui, tip_ordonare);
            break;
        default:
            printf("Aceasta nu este o optiune valida\n");
            break;
    }
}



void run(Ui* ui) {
    int comanda;
    while(1) {
        ui_afiseaza_meniu();
        printf("Alege o optiune: ");

        scanf("%d", &comanda);

        switch(comanda) {
            case 1:
                ui_adauga_medicament(ui);
                break;
            case 2:
                ui_actualizeaza_medicament(ui);
                break;
            case 3:
                ui_sterge_stoc_intreg(ui);
                break;
            case 4:
                ui_vizualizare_medicamente_ordonate(ui);
                break;
            case 5:
                ui_vizualizare_filtrata(ui);
                break;
            case 6:
                ui_afiseaza_stoc(ui);
                break;
            case 7:
                return;
        }
    }

}