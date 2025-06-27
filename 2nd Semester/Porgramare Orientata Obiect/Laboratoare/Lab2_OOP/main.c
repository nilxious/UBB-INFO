#include "C:\Users\Catalin\Documents\Lab2_OOP\ui\ui.h"
#include "C:\Users\Catalin\Documents\Lab2_OOP\controller\service.h"
#include "C:\Users\Catalin\Documents\Lab2_OOP\repository\repository.h"
#include "C:\Users\Catalin\Documents\Lab2_OOP\validator\validator.h"
#include "C:\Users\Catalin\Documents\Lab2_OOP\teste\teste.h"


int main(void)
{
    Repository repo;
    Validator validator;
    Service service;
    Ui ui;

    repo = creeaza_repository();
    validator = creeaza_validator();
    service = creeaza_service(&repo, &validator);
    ui = creeaza_ui(&service);

    ruleaza_teste_repository();
    ruleaza_teste_validator();
    ruleaza_teste_service();

    add_medicament(&service, 123, "Xanax", 20 , 100);
    add_medicament(&service, 124, "Fentanil", 15 , 80);
    add_medicament(&service, 125, "Morfina", 40 , 50);
    add_medicament(&service, 126, "Amfetamina", 60 , 30);
    add_medicament(&service, 127, "Paracetamol", 30 , 40);
    add_medicament(&service, 128, "Ibuprofen", 25 , 70);
    add_medicament(&service, 129, "Magneziu", 77, 120);

    run(&ui);

    return 0;
}
