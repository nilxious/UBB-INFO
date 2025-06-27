#include "teste_repo.h"
#include <iostream>
#include <algorithm>

using std::cout;

void TesteRepo::test_getAll() {
    Repo repo;
    assert(repo.getAll().size() == 0);

    repo.store(Produs("Laptop", 3500, "Electronics", "Dell", 111));
    repo.store(Produs("Telefon", 2500, "Electronics", "Samsung", 112));

    const vector<Produs>& produse = repo.getAll();
    assert(produse.size() == 2);
    assert(produse[0].getNume() == "Laptop");
    assert(produse[1].getNume() == "Telefon");
}


void TesteRepo::test_add() {
    Repo repo;
    Produs p1("Laptop", 3500, "Electronics", "Dell", 111);
    repo.store(p1);
    assert(repo.getAll().size() == 1);

    Produs p2("Telefon", 2500, "Electronics", "Samsung", 112);
    repo.store(p2);
    assert(repo.getAll().size() == 2);

    try {
        repo.store(p1);
        assert(false);
    }
    catch (RepoException& ex) {
        assert(true);
    }
}

void TesteRepo::test_remove() {
    Repo repo;
    repo.store(Produs("Laptop", 3500, "Electronics", "Dell", 111));
    repo.remove(111);
    assert(repo.getAll().size() == 0);

    try {
        repo.remove(111);
        assert(false);
    }
    catch (RepoException& ex) {
        assert(ex.getMessage() == "Nu s-a gasit un produs cu acest id");
    }
}

void TesteRepo::test_modify_price() {
    Repo repo;
    repo.store(Produs("Laptop", 3500, "Electronics", "Dell", 111));
    repo.modify_price(111, 4000);
    assert(repo.search(111).getPret() == 4000);

    try {
        repo.modify_price(222, 5000);
        assert(false);
    }
    catch (RepoException& ex) {
        assert(ex.getMessage() == "Nu s-a gasit un produs cu acest id");
    }
}

void TesteRepo::test_modify_tip() {
    Repo repo;
    repo.store(Produs("Laptop", 3500, "Electronics", "Dell", 111));
    repo.modify_tip(111, "IT");
    assert(repo.search(111).getTip() == "IT");

    try {
        repo.modify_tip(222, "Gadget");
        assert(false);
    }
    catch (RepoException& ex) {
        assert(ex.getMessage() == "Nu s-a gasit un produs cu acest id");
    }
}

void TesteRepo::test_modify_nume() {
    Repo repo;
    repo.store(Produs("Laptop", 3500, "Electronics", "Dell", 111));
    repo.modify_nume(111, "Ultrabook");
    assert(repo.search(111).getNume() == "Ultrabook");

    try {
        repo.modify_nume(222, "Smartphone");
        assert(false);
    }
    catch (RepoException& ex) {
        assert(ex.getMessage() == "Nu s-a gasit un produs cu acest id");
    }
}

void TesteRepo::test_modify_producator() {
    Repo repo;
    repo.store(Produs("Laptop", 3500, "Electronics", "Dell", 111));
    repo.modify_producator(111, "HP");
    assert(repo.search(111).getProducator() == "HP");

    try {
        repo.modify_producator(2, "Apple");
        assert(false);
    }
    catch (RepoException& ex) {
        assert(ex.getMessage() == "Nu s-a gasit un produs cu acest id");
    }
}

void TesteRepo::test_search() {
    Repo repo;
    repo.store(Produs("Laptop", 3500, "Electronics", "Dell", 111));

    Produs found = repo.search(111);
    assert(found.getNume() == "Laptop");

    try {
        repo.search(222);
        assert(false);
    }
    catch (RepoException& ex) {
        assert(ex.getMessage() == "Nu s-a gasit un produs cu acest id");
    }
}

void TesteRepo::test_update() {
    Repo repo;
    Produs p1("Laptop", 3500, "Electronics", "Dell", 111);
    repo.store(p1);

    Produs nouProdus("LaptopNou", 4000, "Gadget", "HP", 111);

    // Hack: cast away const to get a modifiable iterator
    // (ONLY acceptable in controlled tests, not in real code)
    auto& produseConst = repo.getAll();
    auto& produse = const_cast<std::vector<Produs>&>(produseConst);

    auto it = std::find_if(produse.begin(), produse.end(), [](const Produs& p) {
        return p.getId() == 111;
    });

    assert(it != produse.end()); // make sure we found the element

    repo.update(it, nouProdus);

    const Produs& updated = repo.search(111);
    assert(updated.getNume() == "LaptopNou");
    assert(updated.getPret() == 4000);
    assert(updated.getTip() == "Gadget");
    assert(updated.getProducator() == "HP");
}



void TesteRepo::run_all_tests() {
    cout << "Running Repo Tests...\n";
    test_add();
    test_remove();
    test_modify_price();
    test_modify_tip();
    test_modify_nume();
    test_modify_producator();
    test_search();
    test_update();
    cout << "Testele din repo au mers!\n";
}

