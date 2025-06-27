
#include "repo.h"
#include "UI.h"
#include "service.h"
#include "validator.h"
#include "teste/teste_repo.h"
#include "teste/teste_service.h"
#include "teste/teste_produs.h"
#include "teste/teste_validator.h"
#include "teste/teste_cos.h"
#include "teste/teste_filerepo.h"
#include "FileRepository.h"


int main() {
    TesteRepo teste_repo;
    teste_repo.run_all_tests();

    TesteService teste_service;
    teste_service.run_all_tests();

    TesteProdus teste_produs;
    teste_produs.run_all_tests();

    TesteValidator teste_validator;
    teste_validator.run_all_tests();

    TesteCos teste_cos;
    teste_cos.run_all_tests();

    TestFileRepo teste_filerepo;
    teste_filerepo.run_all_tests();
    CosCumparaturi cos;

    FileRepository rep("fisier_repo.txt");
    Validator val;
    Service serv{ rep, val, cos};

    UI ui{ serv };
    ui.startUI();
    return 0;
}