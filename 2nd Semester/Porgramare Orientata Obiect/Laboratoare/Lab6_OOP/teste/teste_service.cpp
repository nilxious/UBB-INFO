#include "teste_service.h"
#include "../repo.h"
#include "../validator.h"
#include "../service.h"
#include <iostream>
using std::cout;

void TesteService::test_add() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("Laptop", 5000, "Electronics", "Dell", 101);
    serv.add("Phone", 2000, "Electronics", "Samsung", 102);

    assert(serv.getAll().size() == 2);

    try {
        serv.add("Tablet", 1500, "Electronics", "Apple", 101);
        assert(false);
    } catch (const RepoException& e) {
        assert(true);
    }

    try {
        serv.add("", 1500, "Electronics", "Apple", 103);
        assert(false);
    } catch (const ValidationException& e) {
        assert(true);
    }

    try {
        serv.add("Smartwatch", 1500, "", "Apple", 104);
        assert(false);
    } catch (const ValidationException& e) {
        assert(true);
    }

    try {
        serv.add("Tablet", 1500, "Electronics", "", 105);
        assert(false);
    } catch (const ValidationException& e) {
        assert(true);
    }

    try {
        serv.add("Phone", 1500, "Electronics", "Apple", 9999);
        assert(false);
    } catch (const ValidationException& e) {
        assert(true);
    }
}

void TesteService::test_remove() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("Telefon", 3000, "Electronics", "Samsung", 102);
    serv.remove(102);
    assert(serv.getAll().empty());

    try {
        serv.remove(999);
        assert(false);
    } catch (const RepoException& e) {
        assert(true);
    }

    try {
        serv.remove(-1);
        assert(false);
    } catch (const ValidationException& e) {
        assert(true);
    }

    try {
        serv.remove(102);
        assert(false);
    } catch (const RepoException& e) {
        assert(true);
    }
}


void TesteService::test_modify_price() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("Mouse", 200, "Accessories", "Logitech", 103);
    serv.modify_price(103, 250);
    assert(serv.getAll()[0].getPret() == 250);

    try {
        serv.modify_price(999, 250);
        assert(false);
    } catch (const RepoException& e) {
        assert(true);
    }
}

void TesteService::test_modify_tip() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("Keyboard", 400, "Accessories", "Razer", 104);
    serv.modify_tip(104, "Gaming");
    assert(serv.getAll()[0].getTip() == "Gaming");

    try {
        serv.modify_tip(999, "Gaming");
        assert(false);
    } catch (const RepoException& e) {
        assert(true);
    }
}

void TesteService::test_modify_nume() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("Monitor", 800, "Electronics", "LG", 105);
    serv.modify_nume(105, "Gaming Monitor");
    assert(serv.getAll()[0].getNume() == "Gaming Monitor");

    try {
        serv.modify_nume(999, "Gaming Monitor");
        assert(false);
    } catch (const RepoException& e) {
        assert(true);
    }
}

void TesteService::test_modify_producator() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("Headset", 600, "Audio", "Sony", 106);
    serv.modify_producator(106, "Bose");
    assert(serv.getAll()[0].getProducator() == "Bose");

    try {
        serv.modify_producator(999, "Bose");
        assert(false);
    } catch (const RepoException& e) {
        assert(true);
    }
}

void TesteService::test_search() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("Tablet", 2500, "Electronics", "Apple", 107);
    const Produs& found = serv.search(107);
    assert(found.getNume() == "Tablet");

    try {
        serv.search(999);
        assert(false);
    } catch (const RepoException& e) {
        assert(true);
    }
}

void TesteService::test_getAll() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("TV", 3500, "Electronics", "Samsung", 108);
    serv.add("Camera", 1500, "Photography", "Canon", 109);
    assert(serv.getAll().size() == 2);
}

void TesteService::test_filterByPret() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("Smartwatch", 1500, "Wearable", "Garmin", 110);
    serv.add("Drone", 4500, "Gadgets", "DJI", 111);

    vector<Produs> filtered = serv.filterByPret(1000, 2000);
    assert(filtered.size() == 1 && filtered[0].getNume() == "Smartwatch");

    try {
        filtered = serv.filterByPret(5000, 6000);
        assert(filtered.empty());
    } catch (const RepoException& e) {
        assert(true);
    }

    try {
        filtered = serv.filterByPret(4500, 4500);
        assert(filtered.empty());
    } catch (const RepoException& e) {
        assert(true);
    }
}

void TesteService::test_filterByNume() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("Printer", 1000, "Office", "HP", 112);
    serv.add("Printer", 1200, "Office", "Epson", 113);

    vector<Produs> filtered = serv.filterByNume("Printer");
    assert(filtered.size() == 2);

    try {
        filtered = serv.filterByNume("Scanner");
        assert(filtered.empty());
    } catch (const RepoException& e) {
        assert(true);
    }

    try {
        filtered = serv.filterByNume("");
        assert(filtered.empty());
    } catch (const RepoException& e) {
        assert(true);
    }
}

void TesteService::test_filterByProducator() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    serv.add("VR Headset", 3000, "Gaming", "Oculus", 114);
    serv.add("VR Headset", 3200, "Gaming", "Oculus", 115);

    vector<Produs> filtered = serv.filterByProducator("Oculus");
    assert(filtered.size() == 2);

    try {
        filtered = serv.filterByProducator("HTC");
        assert(filtered.empty());
    } catch (const RepoException& e) {
        assert(true);
    }

    try {
        filtered = serv.filterByProducator("");
        assert(filtered.empty());
    } catch (const RepoException& e) {
        assert(true);
    }
}

void TesteService::test_sortByNume() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    try {
        vector<Produs> sorted = serv.sortByNume(true);
        assert(false);
    } catch (const RepoException& ex) {
        assert(true);
    }

    try {
        vector<Produs> sorted = serv.sortByNume(false);
        assert(false);
    } catch (const RepoException& ex) {
        assert(true);
    }

    serv.add("Tablet", 2500, "Electronics", "Apple", 116);
    serv.add("Smartphone", 3500, "Electronics", "Samsung", 117);

    vector<Produs> sorted = serv.sortByNume(true);
    assert(sorted[0].getNume() == "Smartphone");
    assert(sorted[1].getNume() == "Tablet");

    sorted = serv.sortByNume(false);
    assert(sorted[0].getNume() == "Tablet");
    assert(sorted[1].getNume() == "Smartphone");
}

void TesteService::test_sortByPret() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    try {
        vector<Produs> sorted = serv.sortByPret(true);
        assert(false);
    } catch (const RepoException& ex) {
        assert(true);
    }

    try {
        vector<Produs> sorted = serv.sortByPret(false);
        assert(false);
    } catch (const RepoException& ex) {
        assert(true);
    }

    serv.add("Earpods", 800, "Audio", "Apple", 118);
    serv.add("Speaker", 1200, "Audio", "JBL", 119);

    vector<Produs> sorted = serv.sortByPret(true);
    assert(sorted[0].getPret() == 800);
    assert(sorted[1].getPret() == 1200);

    sorted = serv.sortByPret(false);
    assert(sorted[0].getPret() == 1200);
    assert(sorted[1].getPret() == 800);
}

void TesteService::test_sortByNumeSiTip() {
    Repo repo;
    Validator val;
    Service serv(repo, val);

    try {
        vector<Produs> sorted = serv.sortByNumeSiTip(true);
        assert(false);
    } catch (const RepoException& ex) {
        assert(true);
    }

    try {
        vector<Produs> sorted = serv.sortByNumeSiTip(false);
        assert(false);
    } catch (const RepoException& ex) {
        assert(true);
    }

    serv.add("Phone", 3500, "Mobile", "Samsung", 120);
    serv.add("Phone", 3000, "Mobile", "Apple", 121);
    serv.add("Laptop", 5000, "Electronics", "Dell", 550);
    serv.add("Tablet", 2500, "Electronics", "Lenovo", 330);

    vector<Produs> sorted = serv.sortByNumeSiTip(true);
    assert(sorted[0].getNume() == "Laptop");
    assert(sorted[1].getNume() == "Phone");
    assert(sorted[2].getNume() == "Phone");
    assert(sorted[3].getNume() == "Tablet");

    sorted = serv.sortByNumeSiTip(false);
    assert(sorted[0].getNume() == "Tablet");
    assert(sorted[1].getNume() == "Phone");
    assert(sorted[2].getNume() == "Phone");
    assert(sorted[3].getNume() == "Laptop");
}


void TesteService::run_all_tests() {
    test_add();
    test_remove();
    test_modify_price();
    test_modify_tip();
    test_modify_nume();
    test_modify_producator();
    test_search();
    test_getAll();
    test_filterByPret();
    test_filterByNume();
    test_filterByProducator();
    test_sortByNume();
    test_sortByPret();
    test_sortByNumeSiTip();
    cout << "Testele din service au mers\n";
}
