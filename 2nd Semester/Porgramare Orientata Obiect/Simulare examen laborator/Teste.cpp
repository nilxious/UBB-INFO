//
// Created by Catalin on 5/23/2025.
//

#include "Teste.h"
#include <cassert>
#include "Imbracaminte.h"
#include "Service.h"

void testeDomain() {
    Imbracaminte i(123, "categorie", "brand", "marime");

    assert(i.getCod() == 123);
    assert(i.getBrand() == "brand");
    assert(i.getMarime() == "marime");
    assert(i.getCategorie() == "categorie");
}

void testeRepository() {
    Repository repo("fisier_test.txt");
    assert(repo.getAll().size() == 4);
}

void testeService() {
    Repository repo2("fisier_test.txt");
    Service serv(repo2);

    vector<Imbracaminte> sortata = serv.sortareMarime();
    vector<Imbracaminte> expected;
    expected.emplace_back(15,"pantalon","Nike","XS");
    expected.emplace_back(18,"pantalon","Nike","S");
    expected.emplace_back(16,"tricou","Gucci","M");
    expected.emplace_back(14,"pantalon","Nike","XXL");

    vector<Imbracaminte> filtrata = serv.filtrareBrand("Nike");
    vector<Imbracaminte> expected2;
    expected2.emplace_back(14,"pantalon","Nike","XXL");
    expected2.emplace_back(15,"pantalon","Nike","XS");
    expected2.emplace_back(18,"pantalon","Nike","S");

    vector<Imbracaminte> filtrata2 = serv.filtrareBrand("Inexistent");
    assert(filtrata2.size() == 0);

    assert(expected2.size()==filtrata.size());
    assert(expected2==filtrata);

    assert(expected.size()==sortata.size());
    assert(expected==sortata);


    serv.reset();
    assert(serv.getAll().size() == 0);
}

void ruleazaTestele() {
    testeDomain();
    printf("Testele din domain au mers\n");
    testeRepository();
    printf("Testele din repository au mers\n");
    testeService();
    printf("Testele din service au mers\n");
}