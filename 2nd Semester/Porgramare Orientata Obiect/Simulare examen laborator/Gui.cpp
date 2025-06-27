//
// Created by Catalin on 5/23/2025.
//

#include "Gui.h"
#include <QMessageBox>
#include <QLabel>

#include <QString>
#include <QListWidgetItem>
#include <QLineEdit>
using std::to_string;

void Gui::initializareGUI() {
    layoutPrincipal = new QHBoxLayout();
    this->setLayout(layoutPrincipal);

    layoutLista = new QVBoxLayout();
    layoutPrincipal->addLayout(layoutLista);

    listaImbracaminte = new QListWidget();
    layoutLista->addWidget(listaImbracaminte);

    layoutButoane = new QVBoxLayout();
    layoutPrincipal->addLayout(layoutButoane);

    btnFiltrareBrand = new QPushButton("Filtrare brand");
    layoutButoane->addWidget(btnFiltrareBrand);
    btnResetare = new QPushButton("Reset");
    layoutButoane->addWidget(btnResetare);
    btnSortareMarime = new QPushButton("Sortare marime");
    layoutButoane->addWidget(btnSortareMarime);

}

void Gui::reincarcareLista() {

    vector<Imbracaminte> haine;
    listaImbracaminte->clear();
    switch(sortare) {
        default:
            haine = service.getAll();
            break;
        case 1:
            haine = service.sortareMarime();
            break;
    }

    listaImbracaminte->addItem("Brand | Categorie | Marime");

    for(auto& haina: haine) {
        QString text = QString::fromStdString(haina.getBrand() + '|' +
    haina.getCategorie() + '|' +
    haina.getMarime()
    );

        QListWidgetItem* item = new QListWidgetItem(text);
        if(haina.getCategorie() == "tricou") {
            item->setBackground(Qt::yellow);
        }
        if(haina.getCategorie() == "pantalon") {
            item->setBackground(Qt::green);
        }
        if(haina.getCategorie() == "geaca") {
            item->setBackground(Qt::blue);
        }
        if(haina.getCategorie() == "hanorac") {
            item->setBackground(Qt::gray);
        }
        item->setData(Qt::UserRole, haina.getBrand().c_str());
        item->setData(Qt::UserRole+1, haina.getMarime().c_str());
        item->setData(Qt::UserRole+2, haina.getCategorie().c_str());

        listaImbracaminte->addItem(item);
    }
}

void Gui::conectareSemnale() {
    if(listaImbracaminte->selectedItems().empty() == false) {
        QLabel* label = new QLabel();
        string mesaj = "Articolul";
        label->setText("Articolul ");
    }

    connect(btnResetare, QPushButton::clicked, [this]() {
        service.reset();
        reincarcareLista();
    });

    connect(btnFiltrareBrand, QPushButton::clicked, [this]() {
        filtrare = 1;
    });

    connect(btnSortareMarime, QPushButton::clicked, [this]() {
        sortare = 1;
        reincarcareLista();
    });
}

Gui::Gui(const Service& service): service(service) {
    initializareGUI();
    conectareSemnale();
    reincarcareLista();
}