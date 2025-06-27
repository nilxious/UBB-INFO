#include "Parcare.h"
#include <cassert>

void teste_domain() {
    Parcare p("ceva", 3, 3, "XX-X--X--");
    assert(p.getAdresa() == "ceva");
    assert(p.getLinii() == 3);
    assert(p.getColoane() == 3);
    assert(p.getStare() == "XX-X--X--");
}



#pragma once
#include "Parcare.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>
#include <cstdio>
#include <fstream>

void test_service_add_and_get_sorted() {
    const std::string testFile = "test_srv_add.txt";
    std::ofstream clear(testFile); clear.close();
    Repository repo(testFile);
    Service srv(repo);
    srv.add(Parcare("adresa2", 3, 4, "XXX---XXX---"));
    srv.add(Parcare("adresa1", 3, 3, "XXX---XXX"));
    auto sorted = srv.getAllSortedByTotalLocuri();
    assert(sorted.size() == 2);
    assert(sorted[0].getAdresa() == "adresa1");
    assert(sorted[1].getAdresa() == "adresa2");
    std::remove(testFile.c_str());
}

void test_service_update() {
    const std::string testFile = "test_srv_update.txt";
    std::ofstream clear(testFile); clear.close();
    Repository repo(testFile);
    Service srv(repo);
    srv.add(Parcare("adresa1", 3, 3, "XXX---XXX"));
    srv.update(Parcare("adresa1", 4, 4, "XXXX----XXXX----"));
    auto all = srv.getAllSortedByTotalLocuri();
    assert(all[0].getLinii() == 4);
    assert(all[0].getColoane() == 4);
    assert(all[0].getStare() == "XXXX----XXXX----");
    std::remove(testFile.c_str());
}

#pragma once
#include "Repository.h"
#include <cassert>
#include <cstdio>
#include <fstream>

void test_repo_add_and_getAll() {
    const std::string testFile = "test_repo_add.txt";
    std::ofstream clear(testFile); clear.close();
    Repository repo(testFile);
    Parcare m1("adresa1", 3, 3, "XXX---XXX");
    Parcare m2("adresa2", 3, 4, "---XXX---");
    repo.add(m1);
    repo.add(m2);
    auto all = repo.getAll();
    assert(all.size() == 2);
    assert(all[0].getAdresa() == "adresa1");
    assert(all[1].getAdresa() == "adresa2");
    std::remove(testFile.c_str());
}


void test_repo_update() {
    const std::string testFile = "test_repo_update.txt";
    std::ofstream clear(testFile); clear.close();
    Repository repo(testFile);
    Parcare m("adresa3", 3, 3, "XXX---XXX");
    repo.add(m);
    Parcare updated("adresa3", 4, 4, "XXXX----XXXX----");
    repo.update(updated);
    auto all = repo.getAll();
    assert(all.size() == 1);
    assert(all[0].getLinii() == 4);
    assert(all[0].getColoane() == 4);
    assert(all[0].getStare() == "XXXX----XXXX----");
    std::remove(testFile.c_str());
}

void test_repo_file_persistence() {
    const std::string testFile = "test_repo_file.txt";
    {
        Repository repo(testFile);
        repo.add(Parcare("adresa1", 3, 3, "XXX---XXX"));
    }
    {
        Repository repo(testFile);
        auto all = repo.getAll();
        assert(all.size() == 1);
        assert(all[0].getAdresa() == "adresa1");
    }
    std::remove(testFile.c_str());
}

void ruleaza_teste() {
    teste_domain();
    test_service_add_and_get_sorted();
    test_service_update();
    test_repo_add_and_getAll();
    test_repo_update();
    test_repo_file_persistence();
}
