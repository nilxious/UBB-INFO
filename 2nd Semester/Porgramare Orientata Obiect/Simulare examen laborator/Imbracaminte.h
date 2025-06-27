#ifndef IMBRACAMINTE_H
#define IMBRACAMINTE_H

#include <string>
using std::string;

class Imbracaminte {
private:
    int cod;
    string categorie;
    string brand;
    string marime;
public:
    /*
     * Constructor default
     */
    Imbracaminte() = default;

    /*
     * Constructor care creeaza un obiect de tip imbracaminte
     */
    Imbracaminte(int cod, const string& categorie, const string& brand, const string& marime);

    /*
     * Constructorul de distrugere
     */
    ~Imbracaminte() = default;

    /*
     * Getter pentru codul imbracamintii
     * return: int
     */
    int getCod() const;

    /*
    * Getter pentru categoria imbracamintii
    * return: string
    */
    const string& getCategorie() const;

   /*
   * Getter pentru brand-ul imbracamintii
   * return: string
   */
    const string& getBrand() const;

     /*
    * Getter pentru marimea imbracamintii
    * return: string
    */
    const string& getMarime() const;


    /*
    * Operatorul de egalitate
    * param ot: Imbracamintea cu care se compara
    * return : true daca obiectele sunt egale, false altfel
    */
     bool operator==(const Imbracaminte& ot) const;
};



#endif //IMBRACAMINTE_H
