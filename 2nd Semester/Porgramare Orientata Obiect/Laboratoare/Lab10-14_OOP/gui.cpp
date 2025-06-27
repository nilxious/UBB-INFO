#include "gui.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QTableWidget>
#include <QHeaderView>
#include "CosCRUDGUi.h"
#include "CosREadOnlyGui.h"
#include <QLabel>
#include <QTableView>
#include "ProdusTableModel.h"


void GUI::initGUI() {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addWidget(new QLabel("Lista Produse (simpla):"));
    leftLayout->addWidget(productListWidget);
    QWidget* leftWidget = new QWidget;
    leftWidget->setLayout(leftLayout);

    QVBoxLayout* rightLayout = new QVBoxLayout;

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("ID:", txtId);
    formLayout->addRow("Nume:", txtNume);
    formLayout->addRow("Pret:", txtPret);
    formLayout->addRow("Tip:", txtTip);
    formLayout->addRow("Producator:", txtProducator);
    rightLayout->addLayout(formLayout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(btnAdd);
    buttonsLayout->addWidget(btnRemove);
    buttonsLayout->addWidget(btnModifyPret);
    buttonsLayout->addWidget(btnModifyNume);
    buttonsLayout->addWidget(btnModifyTip);
    buttonsLayout->addWidget(btnModifyProducator);
    rightLayout->addLayout(buttonsLayout);

    QHBoxLayout* sortButtonsLayout = new QHBoxLayout;
    sortButtonsLayout->addWidget(btnSortNume);
    sortButtonsLayout->addWidget(btnSortPret);
    sortButtonsLayout->addWidget(btnSortNumeTip);
    rightLayout->addLayout(sortButtonsLayout);

    QHBoxLayout* filterButtonsLayout = new QHBoxLayout;
    filterButtonsLayout->addWidget(btnFilterPret);
    filterButtonsLayout->addWidget(btnFilterNume);
    filterButtonsLayout->addWidget(btnFilterProducator);
    rightLayout->addLayout(filterButtonsLayout);

    rightLayout->addWidget(btnUndo);

    rightLayout->addWidget(new QLabel("Produse detaliate:"));

    rightLayout->addWidget(typeButtonsWidget);

    rightLayout->addWidget(new QLabel("Cos de cumparaturi:"));
    rightLayout->addWidget(listCos);

    QHBoxLayout* cartButtonsLayout = new QHBoxLayout;
    cartButtonsLayout->addWidget(btnCosAdd);
    cartButtonsLayout->addWidget(btnCosGen);
    cartButtonsLayout->addWidget(btnCosClear);
    cartButtonsLayout->addWidget(btnCosExport);
    rightLayout->addLayout(cartButtonsLayout);

    rightLayout->addWidget(btnStatistici);

    QWidget* rightWidget = new QWidget;
    rightWidget->setLayout(rightLayout);

    mainLayout->addWidget(leftWidget, 1);
    mainLayout->addWidget(rightWidget, 3);

    btnDeschideCRUD = new QPushButton("Deschide CosCRUDGUI");
    btnDeschideReadOnly = new QPushButton("Deschide CosReadOnlyGUI");

    mainLayout->addWidget(btnDeschideCRUD);
    mainLayout->addWidget(btnDeschideReadOnly);

    tableView = new QTableView;
    tableModel = new ProdusTableModel(this);
    tableView->setModel(tableModel);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    rightLayout->addWidget(tableView);
}




void GUI::connectSignals() {
    QObject::connect(btnAdd, &QPushButton::clicked, this, &GUI::guiAdd);
    QObject::connect(btnRemove, &QPushButton::clicked, this, &GUI::guiRemove);
    QObject::connect(btnModifyPret, &QPushButton::clicked, this, &GUI::guiModifyPret);
    QObject::connect(btnModifyNume, &QPushButton::clicked, this, &GUI::guiModifyNume);
    QObject::connect(btnModifyTip, &QPushButton::clicked, this, &GUI::guiModifyTip);
    QObject::connect(btnModifyProducator, &QPushButton::clicked, this, &GUI::guiModifyProducator);

    QObject::connect(btnSortNume, &QPushButton::clicked, [&]() {
        loadTable(service.sortByNume(true));
    });
    QObject::connect(btnSortPret, &QPushButton::clicked, [&]() {
        loadTable(service.sortByPret(true));
    });
    QObject::connect(btnSortNumeTip, &QPushButton::clicked, [&]() {
        loadTable(service.sortByNumeSiTip(true));
    });

    QObject::connect(btnFilterPret, &QPushButton::clicked, this, &GUI::guiFilterPret);
    QObject::connect(btnFilterNume, &QPushButton::clicked, this, &GUI::guiFilterNume);
    QObject::connect(btnFilterProducator, &QPushButton::clicked, this, &GUI::guiFilterProducator);

    QObject::connect(btnUndo, &QPushButton::clicked, [&]() {
        try {
            service.undo();
            reload();
        } catch (const RepoException& e) {
            QMessageBox::warning(this, "Undo", QString::fromStdString(e.getMessage()));
        }
    });

    QObject::connect(btnCosAdd, &QPushButton::clicked, [&]() {
        QString nume = txtNume->text();
        try {
            service.cosAdauga(nume.toStdString());
            loadCos();
        } catch (const RepoException& e) {
            QMessageBox::warning(this, "Cos", QString::fromStdString(e.getMessage()));
        }
    });

    QObject::connect(btnCosClear, &QPushButton::clicked, [&]() {
        service.cosGoleste();
        loadCos();
    });

    QObject::connect(btnCosGen, &QPushButton::clicked, [&]() {
        bool ok;
        int count = QInputDialog::getInt(this, "Genereaza cos", "Numar produse:", 1, 1, 100, 1, &ok);
        if (ok) {
            service.cosGenereaza(count);
            loadCos();
        }
    });

    QObject::connect(btnCosExport, &QPushButton::clicked, [&]() {
        QString filename = QFileDialog::getSaveFileName(this, "Export Cos", "", "HTML (*.html);;CSV (*.csv)");
        if (filename.isEmpty()) return;
        bool html = filename.endsWith(".html");
        service.cosExport(filename.toStdString(), html);
        QMessageBox::information(this, "Export", "Cos exportat!");
    });

    QObject::connect(btnStatistici, &QPushButton::clicked, [&]() {
        auto stat = service.getTypeCountMap();
        QString result;
        for (const auto& [tip, dto] : stat) {
            result += QString::fromStdString(tip) + ": " + QString::number(dto.getCount()) + "\n";
        }
        QMessageBox::information(this, "Statistici pe tip", result);
    });

    connect(btnDeschideCRUD, &QPushButton::clicked, [&]() {
        auto* fereastra = new CosCRUDGUI(service.getCos());
        fereastra->show();
    });

    connect(btnDeschideReadOnly, &QPushButton::clicked, [&]() {
        auto* fereastra = new CosReadOnlyGUI(service.getCos());
        fereastra->show();
    });
}


void GUI::guiAdd() {
    try {
        service.add(txtNume->text().toStdString(),
                    txtPret->text().toInt(),
                    txtTip->text().toStdString(),
                    txtProducator->text().toStdString(),
                    txtId->text().toInt());
        reload();
    } catch (const ValidationException& e) {
        QMessageBox::warning(this, "Add", QString::fromStdString(e.getMessage()));
    } catch (const RepoException& e) {
        QMessageBox::warning(this, "Add", QString::fromStdString(e.getMessage()));
    }
}

void GUI::guiRemove() {
    try {
        service.remove(txtId->text().toInt());
        reload();
    } catch (const ValidationException& e) {
        QMessageBox::warning(this, "Remove", QString::fromStdString(e.getMessage()));
    } catch (const RepoException& e) {
        QMessageBox::warning(this, "Remove", QString::fromStdString(e.getMessage()));
    }
}

void GUI::guiModifyPret() {
    try {
        service.modify_price(txtId->text().toInt(), txtPret->text().toInt());
        reload();
    } catch (const ValidationException& e) {
        QMessageBox::warning(this, "Modify pret", QString::fromStdString(e.getMessage()));
    } catch (const RepoException& e) {
        QMessageBox::warning(this, "Modify pret", QString::fromStdString(e.getMessage()));
    }
}

void GUI::guiModifyNume() {
    try {
        service.modify_nume(txtId->text().toInt(), txtNume->text().toStdString());
        reload();
    } catch (const ValidationException& e) {
        QMessageBox::warning(this, "Modify nume", QString::fromStdString(e.getMessage()));
    } catch (const RepoException& e) {
        QMessageBox::warning(this, "Modify nume", QString::fromStdString(e.getMessage()));
    }
}

void GUI::guiModifyTip() {
    try {
        service.modify_tip(txtId->text().toInt(), txtTip->text().toStdString());
        reload();
    } catch (const ValidationException& e) {
        QMessageBox::warning(this, "Modify tip", QString::fromStdString(e.getMessage()));
    } catch (const RepoException& e) {
        QMessageBox::warning(this, "Modify tip", QString::fromStdString(e.getMessage()));
    }
}

void GUI::guiModifyProducator() {
    try {
        service.modify_producator(txtId->text().toInt(), txtProducator->text().toStdString());
        reload();
    } catch (const ValidationException& e) {
        QMessageBox::warning(this, "Modify prodcator", QString::fromStdString(e.getMessage()));
    } catch (const RepoException& e) {
        QMessageBox::warning(this, "Modify producator", QString::fromStdString(e.getMessage()));
    }
}

void GUI::guiFilterPret() {
    bool ok1, ok2;
    int min = QInputDialog::getInt(this, "Pret minim", "De la:", 0, 0, 100000, 1, &ok1);
    int max = QInputDialog::getInt(this, "Pret maxim", "Pana la:", 0, 0, 100000, 1, &ok2);
    if (ok1 && ok2) {
        try {
            loadTable(service.filterByPret(min, max));
        } catch (const RepoException& e) {
            QMessageBox::information(this, "Filtrare", QString::fromStdString(e.getMessage()));
        }
    }
}

void GUI::guiFilterNume() {
    QString nume = QInputDialog::getText(this, "Filtrare nume", "Nume:");
    try {
        loadTable(service.filterByNume(nume.toStdString()));
    } catch (const RepoException& e) {
        QMessageBox::information(this, "Filtrare", QString::fromStdString(e.getMessage()));
    }
}

void GUI::guiFilterProducator() {
    QString prod = QInputDialog::getText(this, "Filtrare producator", "Producator:");
    try {
        loadTable(service.filterByProducator(prod.toStdString()));
    } catch (const RepoException& e) {
        QMessageBox::information(this, "Filtrare", QString::fromStdString(e.getMessage()));
    }
}

void GUI::loadTable(const std::vector<Produs>& produse) {
    tableModel->setProduse(produse);
}

void GUI::loadCos() {
    listCos->clear();
    for (const auto& p : service.cosGetProduse()) {
        listCos->addItem(QString::fromStdString(p.getNume() + " - " + std::to_string(p.getPret())));
    }
}

void GUI::reload() {
    loadTable(service.getAll());
    loadCos();
    loadTypeTable();
    loadProductList();
}

void GUI::loadTypeTable() {
    QLayoutItem* item;
    while ((item = typeButtonsLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }

    auto typeCount = service.getTypeCountMap();

    for (const auto& pair : typeCount) {
        const std::string& tip = pair.first;
        const DTO& dto = pair.second;
        int count = dto.getCount();

        QPushButton* btn = new QPushButton(QString::fromStdString(tip));
        typeButtonsLayout->addWidget(btn);

        QObject::connect(btn, &QPushButton::clicked, this, [this, tip, count]() {
            QMessageBox::information(this, "Statistica",
                QString("Exista %1 produse de tip '%2'")
                    .arg(count)
                    .arg(QString::fromStdString(tip)));
        });
    }

    typeButtonsLayout->addStretch();
}

void GUI::loadProductList() {
    productListWidget->clear();
    for (const auto& p : service.getAll()) {
        QString itemText = QString::number(p.getId()) + " - " +
                           QString::fromStdString(p.getNume()) + " - " +
                           QString::number(p.getPret());
        productListWidget->addItem(itemText);
    }
}








