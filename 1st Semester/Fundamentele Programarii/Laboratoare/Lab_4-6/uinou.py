"""

              comenzi
    adauga numar sfarsit {a+bi}
    adauga numar pozitie {a+bi} {p}
    sterge element pozitie {p}
    sterge elemente interval pozitii {p1} {p2}
    inlocuieste aparitii {a+bi} {c+di}
    tipareste parti imaginare subsecventa {p1} {p2}
    tipareste modul<10
    tipareste modul=10
    calculeaza suma subsecventa {p1} {p2}
    calculeaza produs subsecventa {p1} {p2}
    tipareste descrescator dupa imaginare
    filtreaza parte reala
    filtreaza modul<
    filtreaza modul=
    filtreaza modul>
    undo
    exit

"""

from domain import (makeNumber, getRealPart, getImaginaryPart, addToEndOfList, addToGivenPos, listFromPositions, numbersWModulusEqual,
                    numbersWModulusLess, removeGivenCondition, removeAtPosition, extractImaginaryParts, lessThan, biggerThan, equalTo,
                    removeBetweenPositions, replaceComplexNumber, calculateSum, calculateProduct, sortDescending, removePrimeNumbers,
                    copyListOfDicts, undo, addToUndoList)

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

def printImaginaryParts(imaginaryParts: list)-> None:
    """
    Afiseaza partile imaginare dintr-o lista cu numere
    :param imaginaryParts: lista cu valori de tip float
    :return: -
    """
    for i, value in enumerate(imaginaryParts):
        if i>0:
            print(", ", end="")
        print(value, end="")
    print()

def readValue()-> float:
    """
    Citeste o valoare de tip float
    :return: valoarea citita, tip float
    """
    value = float(input("Introduceti o valoare: "))
    return value

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

def readCommand():
    command = str(input(">>>").lower().strip())
    return command

def numberCheck(numar: str):
    if numar.endswith("i"):
        for i in range(1, len(numar)):
            if numar[i] == '+' or numar[i] == '-':
                real_part = numar[:i]
                imag_part = numar[i:-1]
                try:
                    float(real_part)
                    float(imag_part)
                    return float(real_part), float(imag_part)
                except ValueError:
                    return False

def intCheck(element: str):
    try:
        int(element)
        return int(element)
    except ValueError:
        return False

def undoProcess(numberList: list, undoList: list):
    listaCopiata = copyListOfDicts(numberList)
    addToUndoList(undoList, listaCopiata)

def commandCheck(command: str, numberList: list, undoList: list):
    parts = command.split()

    if command == "tipareste descrescator dupa imaginare":
        descendingList = sortDescending(numberList)
        printNumbers(descendingList)

    elif parts[0] == "adauga" and parts[1] == "numar":
        if parts[2] == "sfarsit":
            numar = parts[3]

            Re, Im = numberCheck(numar)
            complexNum = makeNumber(Re, Im)
            undoProcess(numberList, undoList)
            addToEndOfList(numberList, complexNum)

        elif parts[2] == "pozitie":
            numar = parts[3]
            pozitie = parts[4]

            Re, Im = numberCheck(numar)
            complexNum = makeNumber(Re, Im)
            position = intCheck(pozitie)
            undoProcess(numberList, undoList)
            addToGivenPos(numberList, complexNum, position)

    elif parts[0] == "sterge" and parts[1] == "element" and parts[2] == "pozitie":
        undoProcess(numberList, undoList)

        pozitie = parts[3]
        position = intCheck(pozitie)
        removeAtPosition(numberList, position)

    elif parts[0] == "sterge" and parts[1] == "elemente" and parts[2] == "interval" and parts[3] == "pozitii":
        pozitie1 = parts[4]
        pozitie2 = parts[5]

        position1 = intCheck(pozitie1)
        position2 = intCheck(pozitie2)
        if position1>0 and position2<len(numberList):
            undoProcess(numberList, undoList)
            removeBetweenPositions(numberList, position1, position2)

    elif parts[0] == "tipareste" and parts[1] == "parti" and parts[2] == "imaginare" and parts[3] == "subsecventa":
        pozitie1 = parts[4]
        pozitie2 = parts[5]

        position1 = intCheck(pozitie1)
        position2 = intCheck(pozitie2)
        if position1 >= 0 and position2 < len(numberList):
            undoProcess(numberList, undoList)
            listWPositions = listFromPositions(numberList, position1, position2)
            imaginaryPartsList = extractImaginaryParts(listWPositions)
            printImaginaryParts(imaginaryPartsList)

    elif parts[0] == "tipareste":
        if parts[1] == "modul<10":
            undoProcess(numberList, undoList)

            numsWModulusLess = numbersWModulusLess(numberList, 10)
            printNumbers(numsWModulusLess)
        elif parts[1] == "modul=10":
            undoProcess(numberList, undoList)

            numsWModulusEqual = numbersWModulusEqual(numberList, 10)
            printNumbers(numsWModulusEqual)

    elif parts[0] == "calculeaza":
        if parts[1] == "suma" and parts[2] == "subsecventa":
            pozitie1 = parts[3]
            pozitie2 = parts[4]

            position1 = intCheck(pozitie1)
            position2 = intCheck(pozitie2)
            if position1 >= 0 and position2 < len(numberList):
                undoProcess(numberList, undoList)
                sequence = listFromPositions(numberList, position1, position2)
                suma = calculateSum(sequence)
                printSuma(suma)
        elif parts[1] == "produs" and parts[2] == "subsecventa":
            pozitie1 = parts[3]
            pozitie2 = parts[4]

            position1 = intCheck(pozitie1)
            position2 = intCheck(pozitie2)
            if position1 >= 0 and position2 < len(numberList):
                undoProcess(numberList, undoList)
                sequence = listFromPositions(numberList, position1, position2)
                produs = calculateProduct(sequence)
                printProdus(produs)

    elif parts[0] == "exit":
        RUNNING = False

    elif parts[0] == "afiseaza" and parts[1] == "numere":
        printNumbers(numberList)

    elif parts[0] == "filtreaza":
        if parts[1] == "parte" and parts[2] == "reala":
            undoProcess(numberList, undoList)
            numberList = removePrimeNumbers(numberList)
        elif parts[1] == "modul<":
            undoProcess(numberList, undoList)
            value = readValue()
            numberList = removeGivenCondition(numberList, lessThan, value)
        elif parts[1] == "modul=":
            undoProcess(numberList, undoList)
            value = readValue()
            numberList = removeGivenCondition(numberList, equalTo, value)
        elif parts[2] == "modul>":
            undoProcess(numberList, undoList)
            value = readValue()
            numberList = removeGivenCondition(numberList, biggerThan, value)


    elif parts[0] == "inlocuieste" and parts[1] == "aparitii":
        numar1 = parts[2]
        numar2 = parts[3]

        Re1, Im1 = numberCheck(numar1)
        Re2, Im2 = numberCheck(numar2)

        complexNumToReplace = makeNumber(Re1, Im1)
        newComplexNum = makeNumber(Re2, Im2)

        undoProcess(numberList, undoList)
        replaceComplexNumber(numberList, complexNumToReplace, newComplexNum)
    elif parts[0] == "undo":
        undo(undoList, numberList)



def run():
    numberList = [{'Re': 2, 'Im': 9}, {'Re': 11, 'Im': -2}, {'Re': -5, 'Im': -9}, {'Re': 2, 'Im': 1}, {'Re': 33, 'Im': 11}]
    undoList = []
    RUNNING = True
    while RUNNING:
        command = readCommand()
        commandCheck(command, numberList, undoList)