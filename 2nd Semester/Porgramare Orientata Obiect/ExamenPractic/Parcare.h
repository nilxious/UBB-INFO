#pragma once
#include <string>
using std::string;

class Parcare {
private:
    string adresa;
    int linii;
    int coloane;
    string stare;
public:
    /*
     * Constructorul clasei Parcare
     * Parametri:
     *     string adresa - adresa parcarii
     *     int linii - numarul de linii ale parcarii
     *     int coloane - numarul de coloane ale parcarii
     *     string stare - starea parcarii
     * Return: -
     */
    Parcare(string adresa, int linii, int coloane, string stare);

    /*
     * Returneaza adresa parcarii
     * Return: string- adresa parcarii
     */
    string getAdresa() const;

    /*
     * Returneaza numarul de linii ale parcarii
     * Return: int - numarul de linii ale parcarii
     */
    int getLinii() const;

    /*
     * Returneaza numarul de coloane ale parcarii
     * Return: int - numarul de coloane ale parcarii
     */
    int getColoane() const;


    /*
     * Returneaza starea parcarii
     * Return: string - starea
     */
    string getStare() const;

    /*
    * Seteaza starea cu o valoare noua
    * Parametru: string nou - noua valoare pentru stare
    * Return: -
    */
    void setStarea(string nou);

    /*
    * Seteaza nr. de linii cu o valoare noua
    * Parametru: int nou - noua valoare pentru numarul de linii
    * Return: -
    */
    void setLinii(int nou);

    /*
    * Seteaza nr. de coloane cu o valoare noua
    * Parametru: int nou - noua valoare pentru nr. de coloane
    * Return: -
    */
    void setColoane(int nou);
};