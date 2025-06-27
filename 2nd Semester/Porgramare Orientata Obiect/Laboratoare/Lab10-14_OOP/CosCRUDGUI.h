#include "observer.h"
#include "CosCumparaturi.h"
#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QPushButton>

class CosCRUDGUI : public QWidget, public Observer {
    Q_OBJECT

private:
    CosCumparaturi& cos;
    QListWidget* listWidget = new QListWidget();

public:
    explicit CosCRUDGUI(CosCumparaturi& cos) : cos{ cos } {
        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(listWidget);
        setLayout(layout);
        cos.addObserver(this);
        update(); // inițial
    }

    ~CosCRUDGUI() override {
        cos.removeObserver(this);
    }

    void update() override {
        listWidget->clear();
        for (const auto& p : cos.getProduse()) {
            listWidget->addItem(QString::fromStdString(p.getNume()));
        }
    }
};
