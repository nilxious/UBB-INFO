#ifndef UI_H
#define UI_H

#endif //UI_H
#include "../controller/Service.h"

typedef struct {
    Service* service;
}Ui;


Ui creeaza_ui(Service* service);

void run(Ui* ui);



Ui creeaza_ui();