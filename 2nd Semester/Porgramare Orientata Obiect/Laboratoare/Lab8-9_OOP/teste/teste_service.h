#ifndef TESTE_SERVICE_H
#define TESTE_SERVICE_H

#include "../service.h"
#include <cassert>
#include <iostream>

class TesteService {
public:
    void test_add();
    void test_remove();
    void test_modify_price();
    void test_modify_tip();
    void test_modify_nume();
    void test_modify_producator();
    void test_search();
    void test_getAll();
    void test_filterByPret();
    void test_filterByNume();
    void test_filterByProducator();
    void test_sortByNume();
    void test_sortByPret();
    void test_sortByNumeSiTip();
    void test_undo();
    void test_cos_operations();

    void run_all_tests();
};

#endif // TESTE_SERVICE_H

