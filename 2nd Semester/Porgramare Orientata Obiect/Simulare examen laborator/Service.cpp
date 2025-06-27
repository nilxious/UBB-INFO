//
// Created by Catalin on 5/23/2025.
//
#include <unordered_map>
#include "Service.h"
#include <algorithm>

using namespace std;

vector<Imbracaminte>&Service::getAll() {
    return repository.getAll();
}

vector<Imbracaminte>Service::filtrareBrand(string brand) {
    vector<Imbracaminte> filtrata;

    for(const auto& haina: repository.getAll()) {
        if (haina.getBrand() == brand) {
            filtrata.push_back(haina);
        }
    }

    return filtrata;
}

vector<Imbracaminte> Service::sortareMarime() {
    vector<Imbracaminte> haine = repository.getAll();

    unordered_map<string, int> dict_marimi = {{"XS", 1}, {"S", 2}, {"M", 3}, {"XL", 4}, {"XXL", 5} };
    ranges::sort(haine.begin(), haine.end(), [dict_marimi](const Imbracaminte& r1, const Imbracaminte& r2) {
       return dict_marimi.at(r1.getMarime()) < dict_marimi.at(r2.getMarime());
    });

    return haine;
}

void Service::reset() {
    repository.reset();
}