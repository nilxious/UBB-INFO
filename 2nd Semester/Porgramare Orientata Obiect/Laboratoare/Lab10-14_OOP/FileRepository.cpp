#include "FileRepository.h"
#include <fstream>
#include <sstream>

FileRepository::FileRepository(const std::string& caleFisier) : caleFisier(caleFisier) {
    citesteFisier();
}

void FileRepository::citesteFisier() {
    std::ifstream fin(caleFisier);
    if (!fin.is_open()) {
        throw RepoException("Fisierul nu a putut fi deschis!\n");
    }

    produse.clear();
    string nume, tip, producator;
    int pret, id;

    while (fin >> std::ws && std::getline(fin, nume, ',') &&
           std::getline(fin, tip, ',') &&
           fin >> pret &&
           fin.ignore() &&
           std::getline(fin, producator, ',') &&
           fin >> id) {
        produse.emplace_back(nume, pret, tip, producator, id);
           }

    fin.close();
}

void FileRepository::scrieFisier() {
    std::ofstream fout(caleFisier);
    if (!fout.is_open()) {
        throw RepoException("Fisierul nu a putut fi deschis!\n");
    }

    for (const auto& it : getAll()) {
        fout << it.getNume() << "," << it.getTip() << "," << it.getPret()
             << "," << it.getProducator() << "," << it.getId() << "\n";
    }

    fout.close();
}

void FileRepository::store(const Produs& produs) {
    Repo::store(produs);
    scrieFisier();
}

void FileRepository::remove(const int& id) {
    Repo::remove(id);
    scrieFisier();
}

void FileRepository::modify_price(const int& id, const int& price) {
    Repo::modify_price(id, price);
    scrieFisier();
}

void FileRepository::modify_tip(const int& id, const std::string& tip) {
    Repo::modify_tip(id, tip);
    scrieFisier();
}

void FileRepository::modify_nume(const int& id, const std::string& nume) {
    Repo::modify_nume(id, nume);
    scrieFisier();
}

void FileRepository::modify_producator(const int& id, const std::string& producator) {
    Repo::modify_producator(id, producator);
    scrieFisier();
}

