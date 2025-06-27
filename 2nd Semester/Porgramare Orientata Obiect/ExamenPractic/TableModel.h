#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "Parcare.h"
#include "Service.h"

class TableModel : public QAbstractTableModel {
private:
    Service& srv;
    std::vector<Parcare> parcari;
public:
    TableModel(Service& srv) : srv{ srv } { reloadData(); }

    void reloadData() {
        parcari = srv.getAllSortedByTotalLocuri();
        beginResetModel(); 
        endResetModel();
    }

    int rowCount(const QModelIndex& = QModelIndex()) const override {
        return static_cast<int>(parcari.size());
    }

    int columnCount(const QModelIndex& = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole) {
            const auto& m = parcari[index.row()];
            switch (index.column()) {
                case 0: return QString::fromStdString(m.getAdresa());
                case 1: return QVariant::fromValue(m.getLinii());
                case 2: return QVariant::fromValue(m.getColoane());
                case 3: return QString::fromStdString(m.getStare());
                default: return QVariant();
            }
        }
        return QVariant();
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return "Adresa";
                case 1: return "Linii";
                case 2: return "Coloane";
                case 3: return "Stare";
                default: return QVariant();
            }
        }
        return QVariant();
    }

    Parcare getFromRow(int row) const {
        return parcari.at(static_cast<size_t>(row));
    }
};
