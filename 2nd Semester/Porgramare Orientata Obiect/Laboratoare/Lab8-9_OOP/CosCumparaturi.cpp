
#include "CosCumparaturi.h"

#include "coscumparaturi.h"
#include <stdexcept>

void CosCumparaturi::golesteCos() {
    cos.clear();
}

void CosCumparaturi::adaugaInCos(const Produs& produs) {
    cos.push_back(produs);
}

void CosCumparaturi::genereazaCos(const std::vector<Produs>& toateProdusele, int count) {
    if (toateProdusele.empty()) throw std::runtime_error("Nu exista produse disponibile");

    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(0, toateProdusele.size() - 1);

    for (int i = 0; i < count; ++i) {
        int index = dist(gen);
        cos.push_back(toateProdusele[index]);
    }
}

void CosCumparaturi::exportToCSV(const std::string& filename) const {
    std::ofstream out(filename);
    for (const auto& p : cos) {
        out << p.getId() << "," << p.getNume() << "," << p.getPret() << "," << p.getTip() << "," << p.getProducator() << "\n";
    }
}

void CosCumparaturi::exportToHTML(const std::string& filename) const {
    std::ofstream out(filename);
    out << "<html><body><table border='1'>\n";
    out << "<tr><th>ID</th><th>Nume</th><th>Pret</th><th>Tip</th><th>Producator</th></tr>\n";
    for (const auto& p : cos) {
        out << "<tr><td>" << p.getId() << "</td><td>" << p.getNume()
            << "</td><td>" << p.getPret() << "</td><td>" << p.getTip()
            << "</td><td>" << p.getProducator() << "</td></tr>\n";
    }
    out << "</table></body></html>";
}

int CosCumparaturi::totalCos() const {
    int total = 0;
    for (const auto& p : cos) {
        total += p.getPret();
    }
    return total;
}

const std::vector<Produs>& CosCumparaturi::getProduse() const {
    return cos;
}
