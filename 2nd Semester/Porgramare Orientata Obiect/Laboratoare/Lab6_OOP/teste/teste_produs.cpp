#include "teste_produs.h"
#include <iostream>
#include <cassert>

void TesteProdus::test_getNume() {
    Produs produs("Phone", 3500, "Mobile", "Samsung", 123);
    assert(produs.getNume() == "Phone");
}

void TesteProdus::test_getPret() {
    Produs produs("Phone", 3500, "Mobile", "Samsung", 123);
    assert(produs.getPret() == 3500);
}

void TesteProdus::test_getTip() {
    Produs produs("Phone", 3500, "Mobile", "Samsung", 123);
    assert(produs.getTip() == "Mobile");
}

void TesteProdus::test_getProducator() {
    Produs produs("Phone", 3500, "Mobile", "Samsung", 123);
    assert(produs.getProducator() == "Samsung");
}

void TesteProdus::test_getId() {
    Produs produs("Phone", 3500, "Mobile", "Samsung", 123);
    assert(produs.getId() == 123);
}

void TesteProdus::test_setNume() {
    Produs produs("Phone", 3500, "Mobile", "Samsung", 123);
    produs.setNume("Laptop");
    assert(produs.getNume() == "Laptop");
}

void TesteProdus::test_setPret() {
    Produs produs("Phone", 3500, "Mobile", "Samsung", 123);
    produs.setPret(5000);
    assert(produs.getPret() == 5000);
}

void TesteProdus::test_setTip() {
    Produs produs("Phone", 3500, "Mobile", "Samsung", 123);
    produs.setTip("Laptop");
    assert(produs.getTip() == "Laptop");
}

void TesteProdus::test_setProducator() {
    Produs produs("Phone", 3500, "Mobile", "Samsung", 123);
    produs.setProducator("Dell");
    assert(produs.getProducator() == "Dell");
}

void TesteProdus::test_copyConstructor() {
    Produs produs1("Phone", 3500, "Mobile", "Samsung", 123);
    Produs produs2 = produs1;
    assert(produs2.getNume() == produs1.getNume());
    assert(produs2.getPret() == produs1.getPret());
    assert(produs2.getTip() == produs1.getTip());
    assert(produs2.getProducator() == produs1.getProducator());
    assert(produs2.getId() == produs1.getId());
}

void TesteProdus::run_all_tests() {
    test_getNume();
    test_getPret();
    test_getTip();
    test_getProducator();
    test_getId();
    test_setNume();
    test_setPret();
    test_setTip();
    test_setProducator();
    test_copyConstructor();

    std::cout << "Testele din domain au mers\n";
}
