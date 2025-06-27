#ifndef TESTE_PRODUS_H
#define TESTE_PRODUS_H

#include "../produs.h"

class TesteProdus {
public:
    void test_getNume();
    void test_getPret();
    void test_getTip();
    void test_getProducator();
    void test_getId();
    void test_setNume();
    void test_setPret();
    void test_setTip();
    void test_setProducator();
    void test_copyConstructor();
    void run_all_tests();
    void test_operatorEqual();
};

#endif // TESTE_PRODUS_H

