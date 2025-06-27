"""
Lista functionalitati:
    F1. Adauga numar in lista
        - Adauga numar complex la sfarsit de lista
        - Insereaza numar complex pe pozitie data

    F2. Modifica elemente in lista
        - Sterge element pe o pozitie data
        - Sterge elementele de pe un interval de pozitii
        - Inlocuieste toate aparitiile unui numar complex cu un alt numar complex

    F3. Cautare numere
        - Tipareste partea imaginara pentru numerele din lista. Se da intervalul de pozitii (sub secventa)
        - Tipareste toate numerele complexe care au modulul < 10
        - Tipareste toate numerele complexe care au modulul = 10

    F4. Operatii cu numere din lista
        - Suma numerelor dintr-o subsecventa data (se da poz. inceput si sfarsit)
        - Produsul numerelor dintr-o subsecventa data
        - Tipareste lista sortata descrescator dupa partea imaginara

    F5. Filtrare
        - Filtrare partea reala prim - elimina din lista numerele complexe la care partea reala este prim
        - Filtrare modul - elimina din lista numerele complexe cu modulul <, =, sau > decat un numar dat

    F6. undo
        - Reface ultima operatie (lista de nr. revine la nr. care existau inainte de ultima
        operatie care a modificat lista)
---------------------------------------------------------------------------------------------------------
Plan de iteratii:
    1. Saptamana 4: F1, F3, F5
    2. Saptamana 5: F2, F4
    3. Saptamana 6: F6
"""

from uinou import run
from tests import runTests

runTests()
run()