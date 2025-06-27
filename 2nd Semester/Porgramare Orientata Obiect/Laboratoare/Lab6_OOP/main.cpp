#include "repo.h"
#include "UI.h"
#include "service.h"
#include "validator.h"
#include "teste/teste_repo.h"
#include "teste/teste_service.h"
#include "teste/teste_produs.h"
#include "teste/teste_validator.h"
int main() {
    TesteRepo teste_repo;
    teste_repo.run_all_tests();

    TesteService teste_service;
    teste_service.run_all_tests();

    TesteProdus teste_produs;
    teste_produs.run_all_tests();

    TesteValidator teste_validator;
    teste_validator.run_all_tests();

    Repo rep;
    Validator val;
    Service serv{ rep, val };

    UI ui{ serv };
    ui.startUI();
    return 0;
}