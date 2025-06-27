// TestFileRepo.h
#ifndef TESTE_FILEREPO_H
#define TESTE_FILEREPO_H

#include <cassert>
#include <iostream>
#include <fstream>
#include "../FileRepository.h"

class TestFileRepo {
public:
    void test_initialization_from_file();
    void test_store_and_file_persistence();
    void test_remove_and_file_update();
    void test_modify_and_file_update();
    void test_handle_missing_file();
    void test_modify_tip();
    void test_modify_nume();
    void test_modify_producator();
    void run_all_tests();
    void test_scrieFisier_fails();
};

#endif //TESTE_FILEREPO_H
