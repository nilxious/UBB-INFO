
#include "teste_filerepo.h"
#include "../FileRepository.h"
#include "../Produs.h"
#include <fstream>
#include <iostream>

void TestFileRepo::test_initialization_from_file() {
    const std::string temp_file = "test_file.csv";
    std::ofstream fout(temp_file);
    fout << "Laptop,Electronics,5000,Dell,101\n";
    fout << "Phone,Electronics,2000,Samsung,102\n";
    fout.close();

    try {
        FileRepository repo(temp_file);

        auto all_products = repo.getAll();
        assert(all_products.size() == 2);
        assert(all_products[0].getId() == 101);
        assert(all_products[1].getId() == 102);
        assert(all_products[0].getNume() == "Laptop");

    } catch (const RepoException& e) {
        std::cerr << "Error during initialization: " << e.getMessage() << std::endl;
    }
}

void TestFileRepo::test_store_and_file_persistence() {
    const std::string temp_file = "test_file.csv";

    std::ofstream fout(temp_file, std::ios::trunc);
    fout.close();

    FileRepository repo(temp_file);

    Produs produs("Tablet", 1500, "Electronics", "Apple", 103);
    repo.store(produs);

    auto all_products = repo.getAll();
    assert(all_products.size() == 1);
    assert(all_products[0].getId() == 103);

    std::ifstream fin(temp_file);
    std::string line;
    bool found = false;
    while (std::getline(fin, line)) {
        if (line.find("Tablet") != std::string::npos) {
            found = true;
            break;
        }
    }
    fin.close();

    assert(found);
}



void TestFileRepo::test_remove_and_file_update() {
    const std::string temp_file = "test_file.csv";
    std::ofstream fout(temp_file);
    fout << "Laptop,Electronics,5000,Dell,101\n";
    fout << "Phone,Electronics,2000,Samsung,102\n";
    fout.close();

    FileRepository repo(temp_file);

    repo.remove(101);

    auto all_products = repo.getAll();
    assert(all_products.size() == 1);
    assert(all_products[0].getId() == 102);

    std::ifstream fin(temp_file);
    std::string line;
    bool found = false;
    while (std::getline(fin, line)) {
        if (line.find("Laptop") != std::string::npos) {
            found = true;
            break;
        }
    }
    assert(!found);
}

void TestFileRepo::test_modify_and_file_update() {
    const std::string temp_file = "test_file.csv";
    std::ofstream fout(temp_file);
    fout << "Laptop,Electronics,5000,Dell,101\n";
    fout << "Phone,Electronics,2000,Samsung,102\n";
    fout.close();

    FileRepository repo(temp_file);

    repo.modify_price(101, 6000);

    auto all_products = repo.getAll();
    assert(all_products[0].getPret() == 6000);

    std::ifstream fin(temp_file);
    std::string line;
    bool found = false;
    while (std::getline(fin, line)) {
        if (line.find("6000") != std::string::npos) {
            found = true;
            break;
        }
    }
    assert(found);
}

void TestFileRepo::test_handle_missing_file() {
    try {
        FileRepository repo("nonexistent_file.csv");
        assert(false);
    } catch (const RepoException& e) {
    }
}

void TestFileRepo::test_modify_tip() {
    const std::string temp_file = "test_modify_tip.csv";

    std::ofstream fout(temp_file, std::ios::trunc);
    fout.close();

    FileRepository repo(temp_file);

    Produs produs("Phone", 2000, "Electronics", "Samsung", 102);
    repo.store(produs);

    repo.modify_tip(102, "Smartphone");

    auto all_products = repo.getAll();
    assert(all_products.size() == 1);
    assert(all_products[0].getTip() == "Smartphone");

    std::ifstream fin(temp_file);
    std::string line;
    bool found = false;
    while (std::getline(fin, line)) {
        if (line.find("Smartphone") != std::string::npos) {
            found = true;
            break;
        }
    }
    fin.close();

    assert(found);
}

void TestFileRepo::test_modify_nume() {
    const std::string temp_file = "test_modify_nume.csv";

    std::ofstream fout(temp_file, std::ios::trunc);
    fout.close();

    FileRepository repo(temp_file);

    Produs produs("Tablet", 1500, "Electronics", "Apple", 103);
    repo.store(produs);

    repo.modify_nume(103, "Smart Tablet");

    auto all_products = repo.getAll();
    assert(all_products.size() == 1);
    assert(all_products[0].getNume() == "Smart Tablet");

    std::ifstream fin(temp_file);
    std::string line;
    bool found = false;
    while (std::getline(fin, line)) {
        if (line.find("Smart Tablet") != std::string::npos) {
            found = true;
            break;
        }
    }
    fin.close();

    assert(found);
}

void TestFileRepo::test_modify_producator() {
    const std::string temp_file = "test_modify_producator.csv";

    std::ofstream fout(temp_file, std::ios::trunc);
    fout.close();

    FileRepository repo(temp_file);

    Produs produs("Laptop", 5000, "Electronics", "Dell", 101);
    repo.store(produs);

    repo.modify_producator(101, "HP");

    auto all_products = repo.getAll();
    assert(all_products.size() == 1);
    assert(all_products[0].getProducator() == "HP");

    std::ifstream fin(temp_file);
    std::string line;
    bool found = false;
    while (std::getline(fin, line)) {
        if (line.find("HP") != std::string::npos) {
            found = true;
            break;
        }
    }
    fin.close();

    assert(found);
}

void TestFileRepo::test_scrieFisier_fails() {
    std::string unwritablePath = "/this/path/should/not/exist/test.csv";

    try {
        FileRepository repo(unwritablePath);
        repo.store(Produs("test", 123, "type", "brand", 1));
        assert(false);
    } catch (const RepoException& e) {
        std::string mesaj = e.getMessage();
        assert(mesaj.find("Fisierul nu a putut fi deschis") != std::string::npos);
    }
}


void TestFileRepo::run_all_tests() {
    test_initialization_from_file();
    test_store_and_file_persistence();
    test_remove_and_file_update();
    test_modify_and_file_update();
    test_handle_missing_file();
    test_modify_tip();
    test_modify_nume();
    test_modify_producator();
    test_scrieFisier_fails();
}
