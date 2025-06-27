#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "Produs.h"

class ProdusTableModel : public QAbstractTableModel {
    Q_OBJECT
private:
    std::vector<Produs> produse;

public:
    explicit ProdusTableModel(QObject* parent = nullptr) : QAbstractTableModel(parent) {}

    void setProduse(const std::vector<Produs>& produseNou) {
        beginResetModel();
        produse = produseNou;
        endResetModel();
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return static_cast<int>(produse.size());
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 5; // ID, Nume, Pret, Tip, Producator
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole) {
            const Produs& p = produse[index.row()];
            switch (index.column()) {
                case 0: return p.getId();
                case 1: return QString::fromStdString(p.getNume());
                case 2: return p.getPret();
                case 3: return QString::fromStdString(p.getTip());
                case 4: return QString::fromStdString(p.getProducator());
            }
        }
        return {};
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return "ID";
                case 1: return "Nume";
                case 2: return "Pret";
                case 3: return "Tip";
                case 4: return "Producator";
            }
        }
        return {};
    }
};
