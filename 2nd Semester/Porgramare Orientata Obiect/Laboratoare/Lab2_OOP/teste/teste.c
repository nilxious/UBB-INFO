#include "teste.h"
#include "../controller/Service.h"
#include "../repository/Repository.h"
#include "../validator/Validator.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void ruleaza_teste_adaugare_repo() {
    int result;
    Repository repo = creeaza_repository();

    Medicament medicament1 = creeazaMedicament(123, "Medicament1", 40, 40);

    result = adauga_medicament(&repo, medicament1);
    assert(result == 1);

    assert(repo.stoc_curent == 1);
    assert(repo.stoc[0].cod == 123);
    assert(strcmp(repo.stoc[0].nume, "Medicament1") == 0);

    Medicament medicament2 = creeazaMedicament(123, "Medicament2", 30, 60);
    result = adauga_medicament(&repo, medicament2);
    assert(result == 0);

    Medicament medicament3 = creeazaMedicament(123, "Medicament1", 40, 100);
    result = adauga_medicament(&repo, medicament3);
    assert(result == 2);
    assert(repo.stoc[0].cantitate == 140);

    Medicament medicament4 = creeazaMedicament(124, "Medicament4", 50, 20);
    result = adauga_medicament(&repo, medicament4);
    assert(result == 1);
    assert(repo.stoc_curent == 2);
    assert(repo.stoc[1].cod == 124);
    assert(strcmp(repo.stoc[1].nume, "Medicament4") == 0);

    repo.stoc_curent = 100;
    Medicament medicament5 = creeazaMedicament(125, "Medicament5", 50, 30);
    result = adauga_medicament(&repo, medicament5);
    assert(result == 0);
}

void ruleaza_teste_modificare_repo() {
    int result;
    Repository repo = creeaza_repository();

    Medicament medicament1 = creeazaMedicament(123, "Medicament1", 40, 40);
    adauga_medicament(&repo, medicament1);

    result = modifica_medicament(&repo, 123, "UpdatedMedicament", 50, 60);

    assert(result == 1);
    assert(strcmp(repo.stoc[0].nume, "UpdatedMedicament") == 0);
    assert(repo.stoc[0].cantitate == 60);
    assert(repo.stoc[0].concentratie == 50);

    result = modifica_medicament(&repo, 999, "NonExistent", 50, 50);
    assert(result == -1);
}

void ruleaza_teste_stergere_repo() {
    int result;
    Repository repo = creeaza_repository();

    Medicament medicament1 = creeazaMedicament(123, "Medicament1", 40, 40);
    Medicament medicament2 = creeazaMedicament(124, "Medicament2", 77, 40);

    adauga_medicament(&repo, medicament1);

    result = sterge_medicament(&repo, 123);
    assert(result == 1);
    assert(repo.stoc_curent == 0);

    result = sterge_medicament(&repo, 122);
    assert(result == -3);
    assert(repo.stoc_curent == 0);

    adauga_medicament(&repo, medicament2);
    result = sterge_medicament(&repo, 999);
    assert(result == -1);
}

void ruleaza_teste_add_service() {
    int rezultat;
    Repository repo = creeaza_repository();
    Validator validator = creeaza_validator();
    Service service = creeaza_service(&repo, &validator);

    rezultat = add_medicament(&service, 123, "Medicament1", 40, 40);
    assert(rezultat == 1);

    rezultat = add_medicament(&service, 1234, "Medicament1", 40, 40);
    assert(rezultat == -7);

    rezultat = add_medicament(&service, 123, "Medicament1", -4, 40);
    assert(rezultat == -7);

    rezultat = add_medicament(&service, 1234, "Medicament1", 0, 40);
    assert(rezultat == -7);

    rezultat = add_medicament(&service, -4, "Medicament1", 0, 0);
    assert(rezultat == -7);

    rezultat = add_medicament(&service, 99, "Medicament1", 0, -4);
    assert(rezultat == -7);

    rezultat = add_medicament(&service, 1000, "Medicament1", -40, -4);
    assert(rezultat == -7);

    rezultat = add_medicament(&service, 123, "jnjnikoo", 66, 66);
    assert(rezultat == 0);

    rezultat = add_medicament(&service, 123, "Medicament1", 40, 66);
    assert(rezultat == 2);

    service.repo->stoc_curent = 100;
    rezultat = add_medicament(&service, 123, "Medicament2", 66, 66);
    assert(rezultat == 0);

}

void ruleaza_teste_remove_service() {
    int rezultat;
    Repository repo = creeaza_repository();
    Validator validator = creeaza_validator();
    Service service = creeaza_service(&repo, &validator);

    rezultat = add_medicament(&service, 123, "Medicament1", 40, 40);
    rezultat = add_medicament(&service, 124, "Medicament2", 60, 50);

    rezultat = remove_medicament(&service, 123);
    assert(rezultat == 1);

    rezultat = remove_medicament(&service, 1234);
    assert(rezultat == -7);

    rezultat = remove_medicament(&service, 99);
    assert(rezultat == -7);

    rezultat = remove_medicament(&service, 125);
    assert(rezultat == -1);

    rezultat = remove_medicament(&service, 124);
    assert(rezultat == 1);

    rezultat = remove_medicament(&service, 123);
    assert(rezultat == -3);

}

void ruleaza_teste_modify_service() {
    int rezultat;
    Repository repo = creeaza_repository();
    Validator validator = creeaza_validator();
    Service service = creeaza_service(&repo, &validator);

    add_medicament(&service, 123, "Medicament1", 40, 50);

    rezultat = modify_medicament(&service, 124, "MedicamentModificat", 40, 50);
    assert(rezultat == -1);

    rezultat = modify_medicament(&service, 123, "MedModificat", 99, 99);
    assert(rezultat == 1);
    assert(service.repo->stoc[0].cod == 123);
    assert(strcmp(service.repo->stoc[0].nume, "MedModificat") == 0);
    assert(service.repo->stoc[0].concentratie == 99);
    assert(service.repo->stoc[0].cantitate == 99);

    rezultat = modify_medicament(&service, 123, "MedModificat", 0, 7);
    assert(rezultat == -7);

    rezultat = modify_medicament(&service, 123, "MedModificat", -4, 6);
    assert(rezultat == -7);

    rezultat = modify_medicament(&service, 1234, "MedModificat", 4, 6);
    assert(rezultat == -7);

}

void ruleaza_teste_ordered1_service() {
    Repository repo = creeaza_repository();
    Validator validator = creeaza_validator();
    Service service = creeaza_service(&repo, &validator);

    add_medicament(&service, 123, "Xanax", 20 , 100);
    add_medicament(&service, 124, "Fentanil", 15 , 80);
    add_medicament(&service, 125, "Morfina", 40 , 50);
    add_medicament(&service, 126, "Amfetamina", 60 , 30);
    add_medicament(&service, 127, "Paracetamol", 30 , 40);
    add_medicament(&service, 128, "Ibuprofen", 25 , 70);
    add_medicament(&service, 129, "Magneziu", 77, 120);

    Medicament rezultat_expectat[100];
    rezultat_expectat[0] = creeazaMedicament(126, "Amfetamina", 60 , 30);
    rezultat_expectat[1] = creeazaMedicament(124, "Fentanil", 15 , 80);
    rezultat_expectat[2] = creeazaMedicament(128, "Ibuprofen", 25 , 70);
    rezultat_expectat[3] = creeazaMedicament(129, "Magneziu", 77, 120);
    rezultat_expectat[4] = creeazaMedicament(125, "Morfina", 40 , 50);
    rezultat_expectat[5] = creeazaMedicament(127, "Paracetamol", 30 , 40);
    rezultat_expectat[6] = creeazaMedicament(123, "Xanax", 20 , 100);

    Medicament* rezultat_actual = ordered1(&service, 1);


    for(int i=0; i<service.repo->stoc_curent; i++) {
        assert(rezultat_expectat[i].cod == rezultat_actual[i].cod);
        assert(strcmp(rezultat_expectat[i].nume, rezultat_actual[i].nume) == 0);
        assert(rezultat_expectat[i].concentratie == rezultat_actual[i].concentratie);
        assert(rezultat_expectat[i].cantitate == rezultat_actual[i].cantitate);
    }


    Medicament* rezultat_actual2 = ordered1(&service, -1);
    rezultat_expectat[6] = creeazaMedicament(126, "Amfetamina", 60 , 30);
    rezultat_expectat[5] = creeazaMedicament(124, "Fentanil", 15 , 80);
    rezultat_expectat[4] = creeazaMedicament(128, "Ibuprofen", 25 , 70);
    rezultat_expectat[3] = creeazaMedicament(129, "Magneziu", 77, 120);
    rezultat_expectat[2] = creeazaMedicament(125, "Morfina", 40 , 50);
    rezultat_expectat[1] = creeazaMedicament(127, "Paracetamol", 30 , 40);
    rezultat_expectat[0] = creeazaMedicament(123, "Xanax", 20 , 100);

    for(int i=0; i<service.repo->stoc_curent; i++) {
        assert(rezultat_expectat[i].cod == rezultat_actual2[i].cod);
        assert(strcmp(rezultat_expectat[i].nume, rezultat_actual2[i].nume) == 0);
        assert(rezultat_expectat[i].concentratie == rezultat_actual2[i].concentratie);
        assert(rezultat_expectat[i].cantitate == rezultat_actual2[i].cantitate);
    }
}

void ruleaza_teste_ordered2_service() {
    Repository repo = creeaza_repository();
    Validator validator = creeaza_validator();
    Service service = creeaza_service(&repo, &validator);

    add_medicament(&service, 123, "Xanax", 20 , 100);
    add_medicament(&service, 124, "Fentanil", 15 , 80);
    add_medicament(&service, 125, "Morfina", 40 , 50);
    add_medicament(&service, 126, "Amfetamina", 60 , 30);
    add_medicament(&service, 127, "Paracetamol", 30 , 40);
    add_medicament(&service, 128, "Ibuprofen", 25 , 70);
    add_medicament(&service, 129, "Magneziu", 77, 120);

    Medicament rezultat_expectat[100];
    rezultat_expectat[0] = creeazaMedicament(126, "Amfetamina", 60 , 30);
    rezultat_expectat[1] = creeazaMedicament(127, "Paracetamol", 30 , 40);
    rezultat_expectat[2] = creeazaMedicament(125, "Morfina", 40 , 50);
    rezultat_expectat[3] = creeazaMedicament(128, "Ibuprofen", 25 , 70);
    rezultat_expectat[4] = creeazaMedicament(124, "Fentanil", 15 , 80);
    rezultat_expectat[5] = creeazaMedicament(123, "Xanax", 20 , 100);
    rezultat_expectat[6] = creeazaMedicament(129, "Magneziu", 77, 120);

    Medicament* rezultat_actual = ordered2(&service, 1);

    for(int i=0; i<service.repo->stoc_curent; i++) {
        assert(rezultat_expectat[i].cod == rezultat_actual[i].cod);
        assert(strcmp(rezultat_expectat[i].nume, rezultat_actual[i].nume) == 0);
        assert(rezultat_expectat[i].concentratie == rezultat_actual[i].concentratie);
        assert(rezultat_expectat[i].cantitate == rezultat_actual[i].cantitate);
    }
}

void ruleaza_teste_filter1_service() {
    Repository repo = creeaza_repository();
    Validator validator = creeaza_validator();
    Service service = creeaza_service(&repo, &validator);

    add_medicament(&service, 123, "Xanax", 20 , 100);
    add_medicament(&service, 124, "Fentanil", 15 , 80);
    add_medicament(&service, 125, "Morfina", 40 , 50);
    add_medicament(&service, 126, "Amfetamina", 60 , 30);
    add_medicament(&service, 127, "Paracetamol", 30 , 40);
    add_medicament(&service, 128, "Ibuprofen", 25 , 70);
    add_medicament(&service, 129, "Magneziu", 77, 120);

    int cantitate_test = 70;
    MedicamentList rezultat_expectat;

    rezultat_expectat.medicamente[0] = creeazaMedicament(125, "Morfina", 40, 50);
    rezultat_expectat.medicamente[1] = creeazaMedicament(126, "Amfetamina", 60, 30);
    rezultat_expectat.medicamente[2] = creeazaMedicament(127, "Paracetamol", 30, 40);
    rezultat_expectat.size = 3;

    MedicamentList rezultat_actual = filter1(&service, cantitate_test);

    assert(rezultat_expectat.size == rezultat_actual.size);

    for(int i=0; i<rezultat_expectat.size; i++) {
        assert(rezultat_expectat.medicamente[i].cod == rezultat_actual.medicamente[i].cod);
        assert(strcmp(rezultat_expectat.medicamente[i].nume, rezultat_actual.medicamente[i].nume) == 0);
        assert(rezultat_expectat.medicamente[i].concentratie == rezultat_actual.medicamente[i].concentratie);
        assert(rezultat_expectat.medicamente[i].cantitate == rezultat_actual.medicamente[i].cantitate);
    }

}

void ruleaza_teste_filter2_service() {
    Repository repo = creeaza_repository();
    Validator validator = creeaza_validator();
    Service service = creeaza_service(&repo, &validator);

    add_medicament(&service, 123, "Xanax", 20 , 100);
    add_medicament(&service, 124, "Fentanil", 15 , 80);
    add_medicament(&service, 125, "Morfina", 40 , 50);
    add_medicament(&service, 126, "Amfetamina", 60 , 30);
    add_medicament(&service, 127, "Paracetamol", 30 , 40);
    add_medicament(&service, 128, "Ibuprofen", 25 , 70);
    add_medicament(&service, 129, "Magneziu", 77, 120);

    char litera_test = 'M';
    MedicamentList rezultat_expectat;

    rezultat_expectat.medicamente[0] = creeazaMedicament(125, "Morfina", 40, 50);
    rezultat_expectat.medicamente[1] = creeazaMedicament(129, "Magneziu", 77, 120);
    rezultat_expectat.size = 2;

    MedicamentList rezultat_actual = filter2(&service, litera_test);

    assert(rezultat_expectat.size == rezultat_actual.size);

    for(int i=0; i<rezultat_expectat.size; i++) {
        assert(rezultat_expectat.medicamente[i].cod == rezultat_actual.medicamente[i].cod);
        assert(strcmp(rezultat_expectat.medicamente[i].nume, rezultat_actual.medicamente[i].nume) == 0);
        assert(rezultat_expectat.medicamente[i].concentratie == rezultat_actual.medicamente[i].concentratie);
        assert(rezultat_expectat.medicamente[i].cantitate == rezultat_actual.medicamente[i].cantitate);
    }
}


void ruleaza_teste_repository() {
    ruleaza_teste_adaugare_repo();
    ruleaza_teste_modificare_repo();
    ruleaza_teste_stergere_repo();
    printf("Testele din repo au mers\n");
}

void ruleaza_teste_service() {
    ruleaza_teste_add_service();
    ruleaza_teste_remove_service();
    ruleaza_teste_modify_service();
    ruleaza_teste_filter1_service();
    ruleaza_teste_filter2_service();
    ruleaza_teste_ordered1_service();
    ruleaza_teste_ordered2_service();
    printf("Testele din service au mers\n");
}

void ruleaza_teste_validator() {
    int erori;

    Medicament medicament1 = creeazaMedicament(123, "Medicament1", 40, 40);
    Medicament medicament2 = creeazaMedicament(1234, "Medicament2", 1, 40);
    Medicament medicament3 = creeazaMedicament(1234, "Medicament3", 0, 7);
    Medicament medicament4 = creeazaMedicament(99, "Medicament4", -4, -7);

    Validator validator = creeaza_validator();

    erori = validator.valideaza_cantitate(medicament4.cantitate);
    assert(erori == 0);

    erori = validator.valideaza_cantitate(medicament3.concentratie);
    assert(erori == 0);

    erori = validator.valideaza_cod(medicament3.cod);
    assert(erori == 0);

    erori = validator.valideaza(medicament1);
    assert(erori == 0);

    erori = validator.valideaza(medicament2);
    assert(erori == 1);

    erori = validator.valideaza(medicament3);
    assert(erori == 2);

    erori = validator.valideaza(medicament4);
    assert(erori == 3);

    printf("Testele pentru validator au mers\n");
}
