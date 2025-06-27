#include "teste_cos.h"
#include "../CosCumparaturi.h"
#include "../Produs.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

void TesteCos::run_all_tests() {
    testGolesteCos();
    testAdaugaInCos();
    testGenereazaCos();
    testExportToCSV();
    testExportToHTML();
    testTotalCos();
    std::cout << "Toate testele pentru CosCumparaturi au trecut cu succes!\n";
}

void TesteCos::testGolesteCos() {
    CosCumparaturi cos;
    Produs p1("Produs1", 100, "Tip1", "Producator1", 101);
    cos.adaugaInCos(p1);
    assert(cos.getProduse().size() == 1);
    cos.golesteCos();
    assert(cos.getProduse().empty());
}

void TesteCos::testAdaugaInCos() {
    CosCumparaturi cos;
    Produs p2("Produs2", 200, "Tip2", "Producator2", 102);
    cos.adaugaInCos(p2);
    assert(cos.getProduse().size() == 1);
    assert(cos.getProduse()[0].getNume() == "Produs2");
    assert(cos.getProduse()[0].getPret() == 200);
    assert(cos.getProduse()[0].getId() == 102);
}

void TesteCos::testGenereazaCos() {
    CosCumparaturi cos;
    std::vector<Produs> lista = {
        Produs("ProdA", 10, "T1", "PA", 111),
        Produs("ProdB", 20, "T2", "PB", 112),
        Produs("ProdC", 30, "T3", "PC", 113)
    };
    cos.genereazaCos(lista, 5);
    assert(cos.getProduse().size() == 5);
}

void TesteCos::testExportToCSV() {
    CosCumparaturi cos;
    Produs p("ProdCSV", 150, "Export", "CSV_Inc", 123);
    cos.adaugaInCos(p);
    cos.exportToCSV("test_cos.csv");

    std::ifstream in("test_cos.csv");
    std::string line;
    std::getline(in, line);
    in.close();
    assert(line == "123,ProdCSV,150,Export,CSV_Inc");
}

void TesteCos::testExportToHTML() {
    CosCumparaturi cos;
    Produs p("ProdHTML", 300, "Export", "HTML_Corp", 124);
    cos.adaugaInCos(p);
    cos.exportToHTML("test_cos.html");

    std::ifstream in("test_cos.html");
    std::string content((std::istreambuf_iterator<char>(in)),
                         std::istreambuf_iterator<char>());
    in.close();
    assert(content.find("ProdHTML") != std::string::npos);
    assert(content.find("<table") != std::string::npos);
}

void TesteCos::testTotalCos() {
    CosCumparaturi cos;
    cos.adaugaInCos(Produs("Prod1", 100, "T1", "A", 125));
    cos.adaugaInCos(Produs("Prod2", 250, "T2", "B", 126));
    assert(cos.totalCos() == 350);
}
