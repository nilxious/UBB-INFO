#ifndef FILEREPOSITORY_H
#define FILEREPOSITORY_H
#include "repo.h"
#include <string>

class FileRepository : public Repo {
private:
    std::string caleFisier;

    void citesteFisier();

    void scrieFisier();

public:
    explicit FileRepository(const std::string& caleFisier);

    void store(const Produs& produs) override;
    void remove(const int& id) override;
    void modify_price(const int& id, const int& price) override;
    void modify_tip(const int& id, const std::string& tip) override;
    void modify_nume(const int& id, const std::string& nume) override;
    void modify_producator(const int& id, const std::string& producator) override;
};



#endif //FILEREPOSITORY_H
