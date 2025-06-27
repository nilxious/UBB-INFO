#pragma once
#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include "TableModel.h"
#include <QLabel>
#include <QMessageBox>
#include <random>
#include <stdlib.h>

class Gui : public QWidget {
private:
    Service& srv;
    TableModel* model;

    QTableView* table;

    QVBoxLayout* window1;
    QVBoxLayout* window2;
    
    QLineEdit* txtAdresa;
    QLineEdit* txtLinii;
    QLineEdit* txtColoane;
    QLineEdit* txtStare;

    QPushButton* btnAdd;
    QPushButton* btnModify;
    QPushButton* btnCompleteazaStare;

    QWidget* tablaWidget;
    QGridLayout* tablaLayout;
    std::vector<QPushButton*> gridButtons;

    bool parcareSelectat = false;

public:
    Gui(Service& srv) : srv{ srv }{
            model = new TableModel(srv);
            table = new QTableView;
            window1 = new QVBoxLayout();
            window2 = new QVBoxLayout();
            table->setModel(model);
            table->setSelectionBehavior(QAbstractItemView::SelectRows);

            txtAdresa = new QLineEdit;
            txtLinii = new QLineEdit;
            txtColoane = new QLineEdit;
            txtStare = new QLineEdit;

            btnAdd = new QPushButton("Adauga parcare");
            btnModify = new QPushButton("Modifica parcare");
            btnCompleteazaStare = new QPushButton("Completeaza starea");

            QVBoxLayout* layout = new QVBoxLayout;
            layout->addWidget(table);
            layout->addWidget(new QLabel("Adresa:"));
            layout->addWidget(txtAdresa);
            layout->addWidget(new QLabel("Linii:"));
            layout->addWidget(txtLinii);
            layout->addWidget(new QLabel("Coloane:"));
            layout->addWidget(txtColoane);
            layout->addWidget(new QLabel("Stare:"));
            layout->addWidget(txtStare);
            layout->addWidget(btnAdd);
            layout->addWidget(btnModify);
            layout->addWidget(btnCompleteazaStare);

            tablaWidget = new QWidget;
            tablaLayout = new QGridLayout(tablaWidget);
            layout->addWidget(new QLabel("Parcarea:"));
            layout->addWidget(tablaWidget);
            setLayout(layout);

            connectSignalsSlots();
        }

        void connectSignalsSlots() {
            QObject::connect(btnAdd, &QPushButton::clicked, [&]() {
                try {
                    int linii = stoi(txtLinii->text().toStdString());
                    int coloane = stoi(txtColoane->text().toStdString());
                    string stare = txtStare->text().toStdString();
                    string adresa = txtAdresa->text().toStdString();

                    string errors;

                    if (linii < 1 || linii > 5)
                        errors += "Liniile trebuie sa fie in intervalul [1..5] .\n";

                    if (coloane < 1 || coloane > 5)
                        errors += "Coloanele trebuie sa fie in intervalul [1..5] .\n";

                    if (stare.size() != linii*coloane)
                        errors += "Starea trebuie sa aiba exact linii * coloane caractere.\n";

                    for (char c : stare) {
                        if (c != 'X' && c != '-')
                            errors += "Starea poate contine doar caracterele X sau -.\n";
                    }

                    int exista = 0;
                    auto parcari = srv.getAllSortedByTotalLocuri();
                    for(int i =0; i< parcari.size();i++) {
                        if ( parcari[i].getAdresa() == adresa ) {
                            exista = 1;
                        }
                    }

                    if (!errors.empty()) {
                        QMessageBox::warning(this, "Eroare la validare", QString::fromStdString(errors));
                        return;
                    }

                    if (exista) {
                        QMessageBox::warning(this, "Eroare la adaugare", QString::fromStdString("Deja exista aceasta adresa"));
                        return;
                        }



                    Parcare parcare{adresa, linii, coloane, stare};
                    srv.add(parcare);
                    model->reloadData();
            } catch (std::exception& e) {
                QMessageBox::warning(this, "Exceptie", e.what());
            }
        });

        QObject::connect(btnCompleteazaStare, &QPushButton::clicked, [&]() {
            string stare;
            try {
                int linii = stoi(txtLinii->text().toStdString());
                int coloane = stoi(txtColoane->text().toStdString());
                for(int i=0;i<linii*coloane;i++) {
                    int nr = rand()%2;
                    if (nr == 0) {stare+="X";}
                    if (nr == 1) {stare+="-";}
                }
                txtStare->setText(QString::fromStdString(stare));
            }catch(std::exception& e) {
                QMessageBox::warning(this, "Exceptie", "Nu ai introdus liniile si coloanele");
                return;
            }

    });

            QObject::connect(btnModify, &QPushButton::clicked, [&]() {
        try {
            string adresa = txtAdresa->text().toStdString();
            int linii = stoi(txtLinii->text().toStdString());
            int coloane = stoi(txtColoane->text().toStdString());
            std::string stare = txtStare->text().toStdString();

            string errors;

            if (linii < 1 || linii > 5)
                errors += "Liniile trebuie sa fie in intervalul [1..5] .\n";

            if (coloane < 1 || coloane > 5)
                errors += "Coloanele trebuie sa fie in intervalul [1..5] .\n";

            if (stare.size() != linii*coloane)
                errors += "Starea trebuie sa aiba exact linii * coloane caractere.\n";

            for (char c : stare) {
                if (c != 'X' && c != '-')
                    errors += "Starea poate contine doar caracterele X sau -.\n";
            }

            if (!errors.empty()) {
                QMessageBox::warning(this, "Eroare la validare", QString::fromStdString(errors));
                return;
            }

            int exista = 0;
            auto parcari = srv.getAllSortedByTotalLocuri();
                for(int i =0; i< parcari.size();i++) {
                    if ( parcari[i].getAdresa() == adresa ) {
                        exista = 1;
                }
            }

            if (!exista) {
                QMessageBox::warning(this, "Eroare la modificare", QString::fromStdString("Nu exista aceasta adresa"));
                return;
            }

            Parcare updated{adresa, linii, coloane, stare};
            srv.update(updated);
            model->reloadData();

        } catch (std::exception& e) {
            QMessageBox::warning(this, "Exceptie", e.what());
        }
    });

            QObject::connect(table->selectionModel(), &QItemSelectionModel::selectionChanged, this, [=](const QItemSelection &selected, const QItemSelection &) {
                if (selected.indexes().isEmpty()) return;

                int row = selected.indexes().first().row();
                Parcare parcare = model->getFromRow(row);

                Parcare parcareCurenta = parcare;
                parcareSelectat = true;

                // Daca exista deja tabla, o ștergem
                if (tablaWidget) {
                    layout()->removeWidget(tablaWidget);
                    delete tablaWidget;
                    tablaWidget = nullptr;
                }

                // Cream parcare noua
                tablaWidget = new QWidget;
                QGridLayout* grid = new QGridLayout;

                int linii = parcare.getLinii();
                int coloane = parcare.getColoane();
                std::string stare = parcare.getStare();

                for (int i = 0; i < linii; ++i) {
                    for (int j = 0; j < coloane; ++j) {
                        int idx = i * linii + j;
                        QChar c = stare[idx];
                        QPushButton* btn = new QPushButton(c == "-" ? "-" : QString(c));
                        btn->setFixedSize(40, 40);

                        QObject::connect(btn, &QPushButton::clicked, [=, this]() {
                            if (stare[idx] == '-') {
                                std::string parcareCopy = parcareCurenta.getStare();
                                parcareCopy[idx] = 'X';
                                btn->setText(QString(parcareCopy[idx]));

                                // Creeaza parcare actualizata
                                Parcare updated{
                                    parcareCurenta.getAdresa(),
                                    parcareCurenta.getLinii(),
                                    parcareCurenta.getColoane(),
                                parcareCopy,
                                };


                                srv.update(updated);
                                model->reloadData();
                            }
                            else if (stare[idx] == 'X'){
                                std::string parcareCopy = parcareCurenta.getStare();
                                parcareCopy[idx] = '-';
                                btn->setText(QString(parcareCopy[idx]));

                                // Creeaza parcare actualizata
                                Parcare updated{
                                    parcareCurenta.getAdresa(),
                                    parcareCurenta.getLinii(),
                                    parcareCurenta.getColoane(),
                                parcareCopy,
                                };

                                srv.update(updated);
                                model->reloadData();
                            }
                        });
                        grid->addWidget(btn, i, j);
                    }
                }

                tablaWidget->setLayout(grid);
                layout()->addWidget(tablaWidget);
            });
        }
};
