#pragma once
#include "../Service/Service.h"
#ifndef UI_H
#define UI_H
typedef struct {
    Service* service;
} UI;
void initUI(UI**);
void destroyUI(UI*);
void startUI(UI*);
void addCarUI(UI*);
void showAll(UI*);
void updateCarUI(UI*);
void rentUI(UI*);
void returnUI(UI*);
void filterUI(UI*);
void sortUI(UI*);
void undoUI(UI* ui);
#endif //UI_H

