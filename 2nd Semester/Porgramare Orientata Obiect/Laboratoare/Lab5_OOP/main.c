#include "../LAB5_OOP/Domain/Tests1.h"
#include "../LAB5_OOP/Vector/Tests4.h"
#include "../LAB5_OOP/Repository/Tests2.h"
#include "../LAB5_OOP/Service/Tests3.h"
#include "UI/UI.h"

int main(void) {
    domainTests();
    vectorTests();
    repositoryTests();
    serviceTests();
    UI* ui;
    initUI(&ui);
    startUI(ui);
    destroyUI(ui);
    return 0;
}
