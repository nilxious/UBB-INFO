from domain import (makeNumber, getRealPart, getImaginaryPart, addToEndOfList, addToGivenPos, listFromPositions, numbersWModulusEqual,
                    numbersWModulusLess, removeGivenCondition, removeAtPosition, extractImaginaryParts, lessThan, biggerThan, equalTo,
                    removeBetweenPositions, replaceComplexNumber, calculateSum, calculateProduct, sortDescending, removePrimeNumbers,
                    copyListOfDicts, undo, addToUndoList)

def show_menu() -> None:
    # F1. Adauga numar la lista
    print("Adauga numar la lista: ")
    print("     1. Adauga numar complex la sfarsit de lista")
    print("     2. Insereaza numar complex pe pozitie data")
    print("----------------------------------------------------------------------------")
    # F2. Modifica elemente in lista
    print("Modifica elemente in lista: ")
    print("     3. Sterge element pe o pozitie data")
    print("     4. Sterge elementele de pe un interval de pozitii")
    print("     5. Inlocuieste toate aparitiile unui numar complex cu un alt numar complex")
    print("----------------------------------------------------------------------------")
    # F3. Cautare numere
    print("Cuata numere: ")
    print("     6. Tipareste partea imaginara pentru numerele din lista. Se da intervalul de pozitii (sub secventa)")
    print("     7. Tipareste toate numerele complexe care au modulul < 10")
    print("     8. Tipareste toate numerele complexe care au modulul = 10")
    print("----------------------------------------------------------------------------")
    # F4. Operatii cu numere din lista
    print("Executa operatii cu numere din lista: ")
    print("     9. Suma numerelor dintr-o subsecventa data (se da poz. inceput si sfarsit)")
    print("     10. Produsul numerelor dintr-o subsecventa data")
    print("     11. Tipareste lista sortata descrescator dupa partea imaginara")
    print("----------------------------------------------------------------------------")
    # F5. Filtrare
    print("Filtreaza lista: ")
    print("     12. Elimina din lista numerele complexe la care partea reala este prim")
    print("     13. Elimina din lista numerele complexe cu modulul <, =, sau > decat un numar dat")
    print("----------------------------------------------------------------------------")
    # F6. Undo
    print("Undo ultima operatie care modifica lista: ")
    print("     14. Reface ultima operatie")
    print("----------------------------------------------------------------------------")
    # Exit
    print("Iesi din program: ")
    print("     E. Exit")
    print("----------------------------------------------------------------------------")
    # Afiseaza lista
    print("Afiseaza lista: ")
    print("     A. Afiseaza toate numerele complexe din lista")


def show_subMenu() -> None:
    print("A. Elimina din lista numerele complexe cu modulul < decat un numar dat")
    print("B. Elimina din lista numerele complexe cu modulul = decat un numar dat")
    print("C. Elimina din lista numerele complexe cu modulul > decat un numar dat")
    print("Q. Revino la meniul initial")

def readParts()-> tuple:
    """
    Citeste partea reala, respectiv partea imaginara a unui numar complex, ambele parti fiind de tip float
    :return: partea reala si imaginara, ambele de tip float, a numarului complex, drept un tuple
    """
    # Validare partea reala
    while True:
        try:
            Re = float(input("Introduce partea reala a numarului complex: "))
            break
        except ValueError:
            print("Valoare invalida! Introduce din nou partea reala a numarului complex: ")
    # Validare partea imaginara
    while True:
        try:
            Im = float(input("Introduce partea imaginara a numarului complex: "))
            break
        except ValueError:
            print("Valoare invalida! Introduce din nou partea imaginara a numarului complex: ")

    return Re, Im # return as tuple

def readPartsToReplace()-> tuple:
    """
    Citeste partea reala, respectiv partea imaginara a unui numerelor complexe care vor fi inlocuite, ambele parti fiind de tip float
    :return: partea reala si imaginara, ambele de tip float, a numarului complex, drept un tuple
    """
    # Validare partea reala
    while True:
        try:
            Re = float(input("Introduce partea reala a numerelor complexe pe care le vreti inlocuite: "))
            break
        except ValueError:
            print("Valoare invalida! Introduce din nou partea reala a numarului complex: ")
    # Validare partea imaginara
    while True:
        try:
            Im = float(input("Introduce partea imaginara a numerelor complexe pe care le vreti inlocuite: "))
            break
        except ValueError:
            print("Valoare invalida! Introduce din nou partea imaginara a numarului complex: ")

    return Re, Im # return as tuple

def readPartsForReplacement()-> tuple:
    """
    Citeste partea reala, respectiv partea imaginara a noului numar complex pentru a fi inlocuit, ambele parti fiind de tip float
    :return: partea reala si imaginara, ambele de tip float, a numarului complex, drept un tuple
    """
    # Validare partea reala
    while True:
        try:
            Re = float(input("Introduce partea reala a numarului complex pentru inlocuire: "))
            break
        except ValueError:
            print("Valoare invalida! Introduce din nou partea reala a numarului complex: ")
    # Validare partea imaginara
    while True:
        try:
            Im = float(input("Introduce partea imaginara a numarului complex pentru inlocuire: "))
            break
        except ValueError:
            print("Valoare invalida! Introduce din nou partea imaginara a numarului complex: ")

    return Re, Im # return as tuple

def readPositionsIntervalToPrint(numberList: list)-> tuple:
    """
    Citeste prima pozitie si ultima pozitie a intervalului pentru a tipari
    :param numberList: lista de numere complexe
    :return: cele doua pozitii, de tip int, drept un tuple
    """
    position1 = input("Introduceti pozitia de la care vreti sa tipariti: ")
    while not position1.isdigit() or int(position1) > len(numberList) or int(position1) < 0:
        print("Valoare eronata")
        position1 = input("Valoare invalida! Introduceti din nou pozitia de la care vreti sa tipariti: ")
    position1 = int(position1)

    position2 = input("Introduceti ultima pozitie pana la care sa tipariti: ")
    while not position2.isdigit() or int(position2) < position1 or int(position2) < 0:
        print("Valoare eronata")
        position2 = input("Valoare invalida! Introduceti din nou ultima pozitie pana la care sa tipariti: ")
    position2 = int(position2)

    return position1, position2

def readPositionsIntervalToCalculate(numberList: list)-> tuple:
    """
    Citeste prima pozitie si ultima pozitie a intervalului pentru a calcula o suma
    :param numberList: lista de numere complexe
    :return: cele doua pozitii, de tip int, drept un tuple
    """
    position1 = input("Introduceti pozitia de la care vreti sa calculati suma: ")
    while not position1.isdigit() or int(position1) > len(numberList) or int(position1) < 0:
        print("Valoare eronata")
        position1 = input("Valoare invalida! Introduceti din nou pozitia de la care vreti sa calculati suma: ")
    position1 = int(position1)

    position2 = input("Introduceti ultima pozitie pana la care se va calcula suma: ")
    while not position2.isdigit() or int(position2) < position1 or int(position2) < 0:
        print("Valoare eronata")
        position2 = input("Valoare invalida! Introduceti din nou ultima pozitie pana la care se va calcula suma: ")
    position2 = int(position2)

    return position1, position2

def readPositionsIntervalToRemove(numberList: list)-> tuple:
    """
    Citeste prima si ultima pozitie a intervalului pentru a calcula un produs
    :param numberList: lista de numere complexe
    :return: cele doua pozitii, de tip int, drept un tuple
    """
    position1 = input("Introduceti pozitia de la care vreti sa stergeti elemente: ")
    while not position1.isdigit() or int(position1) > len(numberList) or int(position1) < 0:
        print("Valoare eronata")
        position1 = input("Valoare invalida! Introduceti din nou pozitia de la care vreti sa stergeti elemente: ")
    position1 = int(position1)

    position2 = input("Introduceti ultima pozitie pana la care se vor sterge elemente: ")
    while not position2.isdigit() or int(position2) < position1 or int(position2) < 0:
        print("Valoare eronata")
        position2 = input("Valoare invalida! Introduceti din nou pozitia pana la care se vor sterge elemente: ")
    position2 = int(position2)

    return position1, position2

def readPositionsIntervalToMultiply(numberList: list)-> tuple:
    """
    Citeste prima si ultima pozitie a intervalului pentru a calcula un produs
    :param numberList: lista de numere complexe
    :return: cele doua pozitii, de tip int, drept un tuple
    """
    position1 = input("Introduceti pozitia de la care vreti sa calculati produsul: ")
    while not position1.isdigit() or int(position1) > len(numberList) or int(position1) < 0:
        print("Valoare eronata")
        position1 = input("Valoare invalida! Introduceti din nou pozitia de la care vreti sa calculati produsul: ")
    position1 = int(position1)

    position2 = input("Introduceti ultima pozitie pana la care se va calcula produsul: ")
    while not position2.isdigit() or int(position2) < position1 or int(position2) < 0:
        print("Valoare eronata")
        position2 = input("Valoare invalida! Introduceti din nou pozitia pana la care se va calcula produsul: ")
    position2 = int(position2)

    return position1, position2

def readPositionToAdd(numberList: list)-> int:
    """
    Citeste pozitia la care sa se adauge un numar complex in lista
    :param numberList: lista de numere complexe
    :return: pozitia, de tip int
    """
    position = input("Introduceti pozitia la care vreti sa adaugati numarul complex in lista: ")
    while not position.isdigit() or int(position) > len(numberList) or int(position) < 0:
        print("Valoare eronata")
        position = input("Valoare invalida! Introduceti din nou pozitia la care vreti sa adaugati numarul complex in lista: ")
    position = int(position)

    return position

def readPositionToRemove(numberList: list)-> int:
    """
    Citeste pozitia la care sa se stearga un numar complex din lista
    :param numberList: lista de numere complexe
    :return: pozitia, de tip int
    """
    position = input("Introduceti pozitia la care vreti sa stergeti numarul complex din lista: ")
    while not position.isdigit() or int(position) > len(numberList) or int(position) < 0:
        print("Valoare eronata")
        position = input("Valoare invalida! Introduceti din nou pozitia la care vreti sa stergeti numarul complex din lista: ")
    position = int(position)

    return position

def readValue()-> float:
    """
    Citeste o valoare de tip float
    :return: valoarea citita, tip float
    """
    value = float(input("Introduceti o valoare: "))
    return value

def printImaginaryParts(imaginaryParts: list)-> None:
    """
    Afiseaza partile imaginare dintr-o lista cu numere
    :param imaginaryParts: lista cu valori de tip float
    :return: -
    """
    for value in imaginaryParts:
        print(value)

def printNumbers(numberList: list)-> None:
    """
    Afiseaza numerele complexe dintr-o lista de numere complexe, intr-un format de tip a+bi, unde a este partea reala,
    iar b cea imaginara
    :param numberList: lista de numere complexe
    :return: -
    """
    for i in range(len(numberList)):
        if i > 0:
            print(", ", end="")
        print(f"{getRealPart(numberList[i])} + {getImaginaryPart(numberList[i])}i", end="")
    print()

def printSuma(complexNum: dict)-> None:
    """
    Afiseaza suma numerelor complexe din lista dintr-o subsecventa de numere complexe
    return: -
    """
    print(f"Rezultatul sumei este: {getRealPart(complexNum)} + {getImaginaryPart(complexNum)}i")

def printProdus(complexNum: dict)-> None:
    """
    Afiseaza suma numerelor complexe din lista dintr-o subsecventa de numere complexe
    :return: -
    """
    print(f"Rezultatul produsului este: {getRealPart(complexNum)} + {getImaginaryPart(complexNum)}i")


def run(): # Program principal
    numberList = [{'Re': 2, 'Im': 9}, {'Re': 11, 'Im': -2}, {'Re': -5, 'Im': -9}]
    undoList = []

    RUNNING = True
    while RUNNING:
        show_menu()
        optiune = input(">>>").upper().strip()
        match optiune:
            case '1':
                listaCopiata = copyListOfDicts(numberList)
                addToUndoList(undoList, listaCopiata)

                Re, Im = readParts()
                complexNum = makeNumber(Re, Im)
                addToEndOfList(numberList, complexNum)
            case '2':
                listaCopiata = copyListOfDicts(numberList)
                addToUndoList(undoList, listaCopiata)

                Re, Im = readParts()
                complexNum = makeNumber(Re, Im)
                position = readPositionToAdd(numberList)
                addToGivenPos(numberList, complexNum, position)
            case '3':
                listaCopiata = copyListOfDicts(numberList)
                addToUndoList(undoList, listaCopiata)

                position = readPositionToRemove(numberList)
                removeAtPosition(numberList, position)
            case '4':
                listaCopiata = copyListOfDicts(numberList)
                addToUndoList(undoList, listaCopiata)

                position1, position2 = readPositionsIntervalToRemove(numberList)
                removeBetweenPositions(numberList, position1, position2)
            case '5':
                listaCopiata = copyListOfDicts(numberList)
                addToUndoList(undoList, listaCopiata)

                Re1, Im1 = readPartsToReplace()
                complexNumToReplace = makeNumber(Re1, Im1)

                Re2, Im2 = readPartsForReplacement()
                newComplexNum = makeNumber(Re2, Im2)

                replaceComplexNumber(numberList, complexNumToReplace, newComplexNum)
            case '6':
                position1, position2 = readPositionsIntervalToPrint(numberList)
                listWPositions = listFromPositions(numberList, position1, position2)
                imaginaryPartsList = extractImaginaryParts(listWPositions)
                printImaginaryParts(imaginaryPartsList)
            case '7':
                numsWModulusLess = numbersWModulusLess(numberList, 10)
                printNumbers(numsWModulusLess)
            case '8':
                numsWModulusEqual = numbersWModulusEqual(numberList, 10)
                printNumbers(numsWModulusEqual)
            case '9':
                position1, position2 = readPositionsIntervalToCalculate(numberList)
                sequence = listFromPositions(numberList, position1, position2)
                suma = calculateSum(sequence)
                printSuma(suma)
            case '10':
                position1, position2 = readPositionsIntervalToMultiply(numberList)
                sequence = listFromPositions(numberList, position1, position2)
                produs = calculateProduct(sequence)
                printProdus(produs)
            case '11':
                descendingList = sortDescending(numberList)
                printNumbers(descendingList)
            case '12':
                listaCopiata = copyListOfDicts(numberList)
                addToUndoList(undoList, listaCopiata)

                numberList = removePrimeNumbers(numberList)
            case '13':
                while True:
                    show_subMenu()
                    subOption = input(">>>").upper().strip()
                    match subOption:
                        case 'A':
                            listaCopiata = copyListOfDicts(numberList)
                            addToUndoList(undoList, listaCopiata)

                            value = readValue()
                            numberList = removeGivenCondition(numberList, lessThan, value)
                        case 'B':
                            listaCopiata = copyListOfDicts(numberList)
                            addToUndoList(undoList, listaCopiata)

                            value = readValue()
                            numberList = removeGivenCondition(numberList, equalTo, value)
                        case 'C':
                            listaCopiata = copyListOfDicts(numberList)
                            addToUndoList(undoList, listaCopiata)

                            value = readValue()
                            numberList = removeGivenCondition(numberList, biggerThan, value)
                        case 'Q':
                            break
            case '14':
                undo(undoList, numberList)
            case 'E':
                RUNNING = False
            case 'A':
                printNumbers(numberList)
                print("")