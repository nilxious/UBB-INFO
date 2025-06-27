#include "Parcare.h"
#include <vector>
#include <fstream>
#include <sstream>
#include "Repository.h"
#include <algorithm>

Repository::Repository(string filename) : filename{ filename } { loadFromFile(); }

void Repository::loadFromFile() {
    parcari.clear();
    std::ifstream fin(filename);
    string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        string idS, linii, coloane, stare;
        std::getline(ss, idS, ' ');
        std::getline(ss, linii, ' ');
        std::getline(ss, coloane, ' ');
        std::getline(ss, stare);
        int liniiint = stoi(linii);
        int coloaneint = stoi(coloane);
        parcari.emplace_back(idS, liniiint, coloaneint, stare);
    }
    fin.close();
} 

void Repository::writeToFile() {
    std::ofstream fout(filename);
    for (const auto& m : parcari) {
        fout << m.getAdresa() << " " << m.getLinii() << " " << m.getColoane() << " " << m.getStare() << "\n";
    }
    fout.close();
} 

std::vector<Parcare>& Repository::getAll() { return parcari; }

void Repository::add(const Parcare& m) { parcari.push_back(m); writeToFile(); }

void Repository::update(const Parcare& m) {
    for (auto& el : parcari)
        if (el.getAdresa() == m.getAdresa()) {
            el.setLinii(m.getLinii());
            el.setColoane(m.getColoane());
            el.setStarea(m.getStare());
        }
    writeToFile();
} 

