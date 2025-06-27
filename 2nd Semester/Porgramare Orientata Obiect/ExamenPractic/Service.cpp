#include "Service.h"
#include "Repository.h"
#include <algorithm>

Service::Service(Repository& repo) : repo{ repo } {}

std::vector<Parcare> Service::getAllSortedByTotalLocuri() {
    auto all = repo.getAll();

    std::sort(all.begin(), all.end(), [](const Parcare& m1, const Parcare& m2) {
        return m1.getLinii()*m1.getColoane() < m2.getLinii()*m2.getColoane();
    });

    return all;
}

void Service::add(const Parcare& m) { repo.add(m); }

void Service::update(const Parcare& m) { repo.update(m); }
