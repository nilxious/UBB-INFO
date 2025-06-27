#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include "Service.h"

class Gui: public QWidget {
private:
    Service service;

    int sortare;
    int filtrare;

    int tip_sortare;

    QHBoxLayout* layoutPrincipal;

    QVBoxLayout* layoutLista;

    QListWidget* listaImbracaminte;

    QVBoxLayout* layoutButoane;

    QPushButton* btnResetare;
    QPushButton* btnSortareMarime;
    QPushButton* btnFiltrareBrand;

    void initializareGUI();

    void conectareSemnale();

    void reincarcareLista();

public:
    Gui(const Service& service);
};