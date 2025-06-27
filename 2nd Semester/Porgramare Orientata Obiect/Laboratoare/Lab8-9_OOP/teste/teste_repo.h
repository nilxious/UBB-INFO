#ifndef TESTE_REPO_H
#define TESTE_REPO_H

#include "../repo.h"
#include <cassert>

class TesteRepo {
public:
    void test_getAll();
    void test_add();
    void test_remove();
    void test_modify_price();
    void test_modify_tip();
    void test_modify_nume();
    void test_modify_producator();
    void test_search();
    void run_all_tests();
    void test_update();
};

#endif // TESTE_REPO_H



