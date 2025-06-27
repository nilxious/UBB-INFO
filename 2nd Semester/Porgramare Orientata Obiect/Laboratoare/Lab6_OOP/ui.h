#ifndef UI_H
#define UI_H
#include <iostream>
#include "service.h"

class UI
{
private:
    Service& serv;
public:
    UI(Service& serv) : serv{ serv } {

    }
    void startUI();
    void ui_adauga();
    void ui_afiseaza();
    void ui_sterge();
    void ui_modifica();
    void ui_modifica_pret(int id);
    void ui_modifica_producator(int id);
    void ui_modifica_tip(int id);
    void ui_modifica_nume(int id);
    void ui_cauta();
    void ui_filtreaza();
    void ui_filtreaza1();
    void ui_filtreaza2();
    void ui_filtreaza3();
    void ui_sorteaza();
    void ui_sorteaza1();
    void ui_sorteaza2();
    void ui_sorteaza3();
};


#endif //UI_H
