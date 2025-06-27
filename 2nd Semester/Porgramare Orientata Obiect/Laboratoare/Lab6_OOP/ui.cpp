#include "UI.h"
#include <iostream>

using std::cin;
using std::cout;

void UI::startUI() {
    serv.add("Laptop", 3500, "Electronics", "Dell", 111);
    serv.add("Telefon", 2500, "Electronics", "Samsung", 112);
    serv.add("Frigider", 1800, "Electrocasnice", "LG", 113);
    serv.add("Televizor", 2200, "Electronics", "Sony", 114);
    serv.add("Masina de spalat", 1600, "Electrocasnice", "Bosch", 115);
    serv.add("Casti", 400, "Electronics", "JBL", 116);
    serv.add("Aspirator", 900, "Electrocasnice", "Dyson", 117);
    serv.add("Monitor", 1200, "Electronics", "Acer", 118);
    serv.add("Tastatura", 300, "Electronics", "Logitech", 119);
    serv.add("Mouse", 250, "Electronics", "Razer", 120);

    while (true) {
        cout << "1. Adauga\n2. Afiseaza\n3. Sterge\n4. Modifica (pret, producator, tip, nume)\n5. Cauta dupa ID\n6. Filtreaza dupa pret/nume/producator\n7. Sorteaza dupa nume/pret/nume+tip\n0. Exit\nCommand: ";
        int cmd = 0;
        cin >> cmd;

        if (cmd == 0) break;
        else if (cmd == 1) ui_adauga();
        else if (cmd == 2) ui_afiseaza();
        else if (cmd == 3) ui_sterge();
        else if (cmd == 4) ui_modifica();
        else if (cmd == 5) ui_cauta();
        else if (cmd == 6) ui_filtreaza();
        else if (cmd == 7) ui_sorteaza();
        else cout << "Comanda invalida!\n";
    }
}

void UI::ui_adauga() {
    string nume, tip, producator;
    int pret, id;
    cout << "Introdu nume: ";
    cin >> nume;
    cout << "Introdu pret: ";
    cin >> pret;
    cout << "Introdu tip: ";
    cin >> tip;
    cout << "Introdu producator: ";
    cin >> producator;
    cout << "Introdu id: ";
    cin >> id;

    try {
        serv.add(nume, pret, tip, producator, id);
        cout << "Produs adaugat!!!\n";
    }
    catch (ValidationException& ex) {
        cout << ex.getMessage() << "\n";
    }
    catch (RepoException& ex) {
        cout << ex.getMessage() << "\n";
    }
}

void UI::ui_afiseaza() {
    for (const auto& p : serv.getAll()) {
        cout <<"ID: " << p.getId() << ", Nume: "<< p.getNume() << ", Pret: " << p.getPret() << ", Tip: " << p.getTip() << ", Producator: " << p.getProducator() << "\n";
    }
}

void UI::ui_sterge() {
    int id;
    cout << "Introdu ID Produs: ";
    cin >> id;

    try {
        serv.remove(id);
        cout << "Produs sters!!!\n";
    }
    catch (ValidationException& ex) {
        cout << ex.getMessage() << "\n";
    }
    catch (RepoException& ex) {
        cout << ex.getMessage() << "\n";
    }
}

void UI::ui_modifica() {
    int id;
    cout << "Introdu ID produs de modificat: ";
    cin >> id;

    cout << "Modifica pret(1), producator(2), tip(3), sau nume(4)? ";
    int modifyChoice;
    cin >> modifyChoice;

    if (modifyChoice == 1) ui_modifica_pret(id);
    else if (modifyChoice == 2) ui_modifica_producator(id);
    else if (modifyChoice == 3) ui_modifica_tip(id);
    else if (modifyChoice == 4) ui_modifica_nume(id);
    else cout << "Optiune invalida\n";
}

void UI::ui_modifica_pret(int id) {
    int price;
    cout << "Introdu noul pret: ";
    cin >> price;

    if (price < 0) {
        cout << "Pretul nu poate fi negativ!\n";
        return;
    }

    try {
        serv.modify_price(id, price);
        cout << "Pret modificat\n";
    }
    catch (ValidationException& ex) {
        cout << ex.getMessage() << "\n";
    }
    catch (RepoException& ex) {
        cout << ex.getMessage() << "\n";
    }
}

void UI::ui_modifica_producator(int id) {
    string producer;
    cout << "Introdu noul producator: ";
    cin >> producer;

    try {
        serv.modify_producator(id, producer);
        cout << "Producator modificat\n";
    }
    catch (ValidationException& ex) {
        cout << ex.getMessage() << "\n";
    }
    catch (RepoException& ex) {
        cout << ex.getMessage() << "\n";
    }
}

void UI::ui_modifica_tip(int id) {
    string type;
    cout << "Introdu noul tip: ";
    cin >> type;

    try {
        serv.modify_tip(id, type);
        cout << "Tip modificat\n";
    }
    catch (ValidationException& ex) {
        cout << ex.getMessage() << "\n";
    }
    catch (RepoException& ex) {
        cout << ex.getMessage() << "\n";
    }
}

void UI::ui_modifica_nume(int id) {
    string name;
    cout << "Introdu noul nume: ";
    cin >> name;

    try {
        serv.modify_nume(id, name);
        cout << "Nume modificat\n";
    }
    catch (ValidationException& ex) {
        cout << ex.getMessage() << "\n";
    }
    catch (RepoException& ex) {
        cout << ex.getMessage() << "\n";
    }
}

void UI::ui_cauta() {
    int id;
    cout << "Introdu ID produs: ";
    cin >> id;

    try {
        Produs p = serv.search(id);
        cout << p.getNume() << " " << p.getPret() << " " << p.getTip() << " " << p.getProducator() << "\n";
        cout << "Produs afisat!\n";
    }
    catch (RepoException& ex) {
        cout << ex.getMessage() << "\n";
    }
}

void UI::ui_filtreaza() {
    cout << "Filtreaza dupa pret(1), nume(2), sau producator(3)? ";
    int cmd;
    cin >> cmd;

    if (cmd == 1) ui_filtreaza1();
    else if (cmd == 2) ui_filtreaza2();
    else if (cmd == 3) ui_filtreaza3();
    else cout << "Comanda invalida\n";
}

void UI::ui_filtreaza1() {
    int pret1, pret2;
    cout << "Introdu intervalul pretului [pret1, pret2]: ";
    cin >> pret1 >> pret2;

    auto products = serv.filterByPret(pret1, pret2);
    for (const auto& p : products) {
        cout << p.getNume() << " " << p.getPret() << " " << p.getTip() << " " << p.getProducator() << "\n";
    }
}

void UI::ui_filtreaza2() {
    string name;
    cout << "Introdu nume: ";
    cin >> name;

    auto products = serv.filterByNume(name);
    for (const auto& p : products) {
        cout << p.getNume() << " " << p.getPret() << " " << p.getTip() << " " << p.getProducator() << "\n";
    }
}

void UI::ui_filtreaza3() {
    string producer;
    cout << "Introdu producator: ";
    cin >> producer;

    auto products = serv.filterByProducator(producer);
    for (const auto& p : products) {
        cout << p.getNume() << " " << p.getPret() << " " << p.getTip() << " " << p.getProducator() << "\n";
    }
}

void UI::ui_sorteaza() {
    cout << "Sorteaza dupa nume(1), pret(2), sau nume+tip(3)? ";
    int cmd;
    cin >> cmd;

    if (cmd == 1) ui_sorteaza1();
    else if (cmd == 2) ui_sorteaza2();
    else if (cmd == 3) ui_sorteaza3();
    else cout << "Comanda invalida\n";
}

void UI::ui_sorteaza1() {
    auto sorted = serv.sortByNume(true);
    for (const auto& p : sorted) {
        cout << p.getNume() << " " << p.getPret() << " " << p.getTip() << " " << p.getProducator() << "\n";
    }
}

void UI::ui_sorteaza2() {
    auto sorted = serv.sortByPret(true);
    for (const auto& p : sorted) {
        cout << p.getNume() << " " << p.getPret() << " " << p.getTip() << " " << p.getProducator() << "\n";
    }
}

void UI::ui_sorteaza3() {
    auto sorted = serv.sortByNumeSiTip(true);
    for (const auto& p : sorted) {
        cout << p.getNume() << " " << p.getPret() << " " << p.getTip() << " " << p.getProducator() << "\n";
    }
}
