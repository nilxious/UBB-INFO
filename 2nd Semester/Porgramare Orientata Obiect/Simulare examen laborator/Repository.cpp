#include "Repository.h"
#include <fstream>
#include <sstream>

using namespace std;

Repository::Repository(string cale_fisier): path(std::move(cale_fisier)) {
    citesteFisier();
}

void Repository::citesteFisier() {
    ifstream fin(path);
    haine.clear();
    string linie;
    while(getline(fin, linie)) {
        stringstream ss(linie);

        string cod_str, categorie, brand, marime;

        getline(ss, cod_str, ',');
        getline(ss, categorie, ',');
        getline(ss, brand, ',');
        getline(ss, marime, ',');

        int cod = stoi(cod_str);

        haine.emplace_back(cod, categorie, brand, marime);
    }

    fin.close();
}

void Repository::scrieFisier() {
    ofstream fout(path);
    for (auto &c : haine) {
        fout << c.getCod() << "," << c.getCategorie() << "," << c.getBrand() << "," << c.getMarime() << '\n';
    }
}

std::vector<Imbracaminte>& Repository::getAll() {
    return haine;
}

void Repository::reset() {
    haine.clear();
}
