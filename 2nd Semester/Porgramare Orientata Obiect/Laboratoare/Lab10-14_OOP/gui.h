#ifndef GUI_H
#define GUI_H

#include "ProdusTableModel.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QTableWidget>
#include <QMessageBox>
#include <QCloseEvent>
#include <vector>
#include <string>
#include "service.h"
#include <QHBoxLayout>

using std::string;
using std::vector;

class GUI : public QWidget {
    Q_OBJECT

public:
    explicit GUI(Service& service) : service(service) {
        initGUI();
        connectSignals();
        reload();
    }

private:

    Service& service;

    // UI elements
    QLineEdit* txtId = new QLineEdit();
    QLineEdit* txtNume = new QLineEdit();
    QLineEdit* txtPret = new QLineEdit();
    QLineEdit* txtTip = new QLineEdit();
    QLineEdit* txtProducator = new QLineEdit();

    QPushButton* btnAdd = new QPushButton("Add");
    QPushButton* btnRemove = new QPushButton("Remove");
    QPushButton* btnModifyPret = new QPushButton("Modify Price");
    QPushButton* btnModifyNume = new QPushButton("Modify Name");
    QPushButton* btnModifyTip = new QPushButton("Modify Type");
    QPushButton* btnModifyProducator = new QPushButton("Modify Producer");

    QPushButton* btnSortNume = new QPushButton("Sort by Name");
    QPushButton* btnSortPret = new QPushButton("Sort by Price");
    QPushButton* btnSortNumeTip = new QPushButton("Sort by Name+Type");

    QPushButton* btnFilterPret = new QPushButton("Filter by Price");
    QPushButton* btnFilterNume = new QPushButton("Filter by Name");
    QPushButton* btnFilterProducator = new QPushButton("Filter by Producer");

    QPushButton* btnUndo = new QPushButton("Undo");

    QPushButton* btnCosAdd = new QPushButton("Add to Cart");
    QPushButton* btnCosGen = new QPushButton("Generate Cart");
    QPushButton* btnCosClear = new QPushButton("Clear Cart");
    QPushButton* btnCosExport = new QPushButton("Export Cart");

    QPushButton* btnStatistici = new QPushButton("Show Statistics");

    QTableWidget* table = new QTableWidget();
    QListWidget* listCos = new QListWidget();

    QWidget* typeButtonsWidget = new QWidget();
    QVBoxLayout* typeButtonsLayout = new QVBoxLayout(typeButtonsWidget);

    QListWidget* productListWidget = new QListWidget();

    QPushButton* btnDeschideCRUD;
    QPushButton* btnDeschideReadOnly;

    QTableView* tableView;
    ProdusTableModel* tableModel;


    void initGUI();
    void connectSignals();

    void guiAdd();
    void guiRemove();
    void guiModifyPret();
    void guiModifyNume();
    void guiModifyTip();
    void guiModifyProducator();

    void guiFilterPret();
    void guiFilterNume();
    void guiFilterProducator();

    void loadTable(const vector<Produs>& produse);
    void loadCos();
    void reload();
    void loadTypeTable();
    void loadProductList();

};


#endif // GUI_H
