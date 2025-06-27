#include <QApplication>
#include <iostream>

#include "produs.h"
#include "repo.h"
#include "FileRepository.h"
#include "service.h"
#include "validator.h"
#include "cosCumparaturi.h"
#include "gui.h"
#include "ui.h"

// Test headers
#include "teste/teste_repo.h"
#include "teste/teste_service.h"
#include "teste/teste_produs.h"
#include "teste/teste_validator.h"
#include "teste/teste_cos.h"
#include "teste/teste_filerepo.h"

using std::cout;
using std::endl;

void run_all_tests() {
    TesteRepo().run_all_tests();
    TesteService().run_all_tests();
    TesteProdus().run_all_tests();
    TesteValidator().run_all_tests();
    TesteCos().run_all_tests();
    TestFileRepo().run_all_tests();

    cout << "Toate testele au fost rulate cu succes!" << endl;
}

int main(int argc, char* argv[]) {
    run_all_tests();

    QApplication a(argc, argv);

    FileRepository repo("fisier_repo.txt");

    Validator validator;
    CosCumparaturi cos;
    Service service(repo, validator, cos);

    GUI gui(service);
    gui.show();

    return a.exec();
}
