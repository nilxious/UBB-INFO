def makeNumber(Re: float, Im: float)-> dict:
    """
    Creeaza un numar complex, avand o parte reala si imaginara
    :param Re: partea reala a numarului complex, tip float
    :param Im: partea imaginara a numarului complex, tip float
    :return: un dictionar care reprezinta numarul complex, format din cele doua chei (parti): reala si imaginara
    """
    return {'Re': Re, 'Im': Im}

def getRealPart(complexNumber: dict)-> float:
    """
    Ia partea reala a unui numar complex (tip dictionar)
    :param complexNumber: numarul complex, tip dictionar
    :return: partea reala a numarului complex, tip float
    """
    return complexNumber['Re']

def getImaginaryPart(complexNumber: dict)-> float:
    """
    Ia partea imaginara a unui numar complex (tip dictionar)
    :param complexNumber: numarul complex, tip dictionar
    :return: partea imaginara a numarului complex, tip float
    """
    return complexNumber['Im']

def addToEndOfList(numberList: list, complexNum: dict)-> None:
    """
    Adauga un numar complex la sfarsitul listei de numere complexe
    :param numberList: lista cu numere complexe
    :param complexNum: numarul complex, tip dictionar
    :return: -
    """
    numberList.append(complexNum)

def addToGivenPos(numberList: list, complexNum: dict, position: int)-> None:
    """
    Insereaza un numar complex in lista de numere complexe pe o pozitie data
    :param numberList: lista de numere complexe
    :param complexNum: numarul complex, tip dictionar
    :param position: pozitia la care sa se adauge numarul complex, tip int
    :return: -
    """
    numberList.insert(position, complexNum)

def listFromPositions(numberList: list, position1: int, position2: int)-> list:
    """
    Creeaza o sublista de la pozitia position1 la pozitia position2 inclusiv a listei de numere complexe
    :param numberList: lista de numere complexe
    :param position1: pozitia de la care sa inceapa sublista, tip int
    :param position2: pozitia la care se termina sublista inclusiv, tip int
    :return: noua sublista
    """
    return numberList[position1:position2+1]

def extractImaginaryParts(numberList: list)-> list:
    """
    Creeaza o lista cu partile imaginare dintr-o lista de numere complexe
    :param numberList: lista de numere complexe
    :return: noua lista cu partile imaginare
    """
    imaginaryParts = [getImaginaryPart(number) for number in numberList]
    return imaginaryParts

def Modulus(complexNum: dict | list)-> float:
    """
    Calculeaza modulul unui numar complex
    :param complexNum: numarul complex, tip dictionar
    :return: valoarea modulului numarului complex, tip float
    """
    imaginaryPart = getImaginaryPart(complexNum)
    realPart = getRealPart(complexNum)
    return float((imaginaryPart ** 2 + realPart ** 2)**0.5)

def numbersWModulusEqual(numberList: list, value: float)-> list:
    """
    Creeaza o lista de numere complexe care au modulul egal cu o valoare
    :param numberList: lista de numere complexe
    :param value: valoare numerica, tip float
    :return: noua lista cu numere complexe care au modulul egal cu o valoare
    """
    newList = []
    for i in range(len(numberList)):
        number = numberList[i]
        modulus = Modulus(number)
        if equalTo(modulus, value):
            newList.append(numberList[i])
    return newList

def numbersWModulusLess(numberList: list, value: int)-> list:
    """
    Creeaza o lista de numere complexe care au modulul mai mic decat o valoare
    :param numberList: lista de numere complexe
    :param value: valoare numerica, tip float
    :return: noua lista cu numere complexe care au modulul mai mic decat o valoare
    """
    newList = []
    for i in range(len(numberList)):
        number = numberList[i]
        modulus = Modulus(number)
        if lessThan(modulus, value):
            newList.append(numberList[i])
    return newList

def isPrime(num: float)-> bool:
    """
    Verifica daca un numar este prim
    :param num: numar, tip float
    :return: True sau False
    """
    if num != int(num):
        return False

    number = int(num)
    if number < 2:
        return False

    for divisor in range(2, int(number**0.5)+1):
        if number % divisor == 0:
            return False

    return True

def removePrimeNumbers(numberList: list)-> list:
    """
    Creeaza o noua lista din lista de numere complexe, dar fara numerele complexe care au partea reala un numar prim
    :param numberList: lista de numere complexe
    :return: noua lista filtrata
    """
    filteredList = []
    for number in numberList:
        if not isPrime(getRealPart(number)):
            filteredList.append(number)

    return filteredList

def lessThan(number1: float, value:float)-> bool:
    """
    Verifica daca un numar este mai mic decat o valoare data
    :param number1: numar, tip float
    :param value: valoare data, tip float
    :return: True sau False
    """
    return number1 < value

def equalTo(number1: float, value:float)-> bool:
    """
    Verifica daca un numar este egal cu o valoare data
    :param number1: numar, tip float
    :param value: valoare data, tip float
    :return: True sau False
    """
    return number1 == value

def biggerThan(number1: float, value:float)-> bool:
    """
    Verifica daca un numar este mai mare decat o valoare data
    :param number1: numar, tip float
    :param value: valoare data, tip float
    :return: True sau False
    """
    return number1 > value

def removeGivenCondition(numberList: list, condition, value: float)-> list:
    """
    Creeaza o noua lista din lista de numere complexe, dar fara numerele complexe care au modulul mai mic, egal, sau mai mare
    decat o valoare data
    :param numberList: lista de numere complexe
    :param condition: una dintre cele trei functii: lessThan(), equalTo(), biggerThan()
    :param value: valaore data, tip float
    :return: noua lista filtrata
    """
    filteredList = []
    for number in numberList:
        modulusOfNumber = Modulus(number)
        if not condition(modulusOfNumber, value):
            filteredList.append(number)
    return filteredList

def removeAtPosition(numberList: list, position: int)-> None:
    """
    Elimina numarul complex din lista de numere complexe de pe o pozitie data
    :param numberList: lista de numere complexe
    :param position: pozitia la care se va sterge numarul complex
    :return: -
    """
    del numberList[position]

def removeBetweenPositions(numberList: list, position1: int, position2)-> None:
    """
    Elimina numerele complexe din lista de numere complexe de la o pozitie position1 la o pozitie position2
    :param numberList: lista de numere complexe
    :param position1: pozitia de la care se vor sterge elemente (de tip int)
    :param position2: pozitia pana la care se vor sterge elemente inclusiv (de tip int)
    :return: -
    """
    del numberList[position1:position2+1]

def replaceComplexNumber(numberList: list, complexNumToReplace: dict, newComplexNum: dict)-> None:
    """
    Modifica lista initiala de numere complexe, inlocuind toate aparitiile unui numar complex din lista cu un alt numar complex
    :param numberList: lista de numere complexe
    :param complexNumToReplace: numarul(sau numerele) care for vi inlocuite
    :param newComplexNum: numarul complex care va inlocui numerele complexe specificate
    :return: -
    """
    for index, number in enumerate(numberList):
        if number == complexNumToReplace:
            numberList[index] = newComplexNum

def calculateSum(numberList: list)-> dict:
    """
    Calculeaaza suma numerelor complexe dintr-o secventa (lista)
    :param numberList: secventa de numere complexe (lista)
    :return: rezultatul sumei, un numar complex (de tip dictionar)
    """
    initialReal = getRealPart(numberList[0])
    initialImaginary = getImaginaryPart(numberList[0])

    for number in numberList[1:]:
        initialReal += getRealPart(number)
        initialImaginary += getImaginaryPart(number)

    return makeNumber(initialReal, initialImaginary)

def calculateProduct(numberList: list)-> dict:
    """
    Calculeaza produsul numerelor complexe dintr-o secventa (lista)
    :param numberList: secventa de numere complexe (lista)
    :return: rezultatul produsului, un numar complex (de tip dictionar)
    """
    initialReal = getRealPart(numberList[0])
    initialImaginary = getImaginaryPart(numberList[0])

    for number in numberList[1:]:
        newReal = initialReal * getRealPart(number) - initialImaginary * getImaginaryPart(number)
        newImaginary = initialReal * getImaginaryPart(number) + initialImaginary * getRealPart(number)

        initialReal = newReal
        initialImaginary = newImaginary

    return makeNumber(initialReal, initialImaginary)

def sortDescending(numberList: list)-> list:
    """
    Creeaza o copie shallow a listei de numere complexe, iar apoi o sorteaza descrescator in functie de valorile partii imaginare
    :param numberList: lista de numere complexe
    :return: lista sortata descrescator
    """
    listCopy = numberList.copy()
    n = len(listCopy)
    for i in range (0, n-1):
        for j in range (i+1, n):
            if getImaginaryPart(listCopy[i]) <= getImaginaryPart(listCopy[j]):
                aux = listCopy[j]
                listCopy[j] = listCopy[i]
                listCopy[i] = aux

    return listCopy

def copyListOfDicts(numberList: list) -> list:
    """
    Creeaza o copie a unei liste de dictionare
    :param numberList: lista de dictionare
    :return: o noua lista care contine noi elemente (dictionare) cu aceleasi valori
            ca si cele din lista initiala
            postconditii: id(lst) != id(lista returnata), oricare i, i = 0..len(lst)-1
                          id(lst[i]) != id(lista_returnata[i])
    """
    new_list = []
    for dictionary in numberList:
        new_dictionary = {}
        for key, value in dictionary.items():
            new_dictionary[key] = value
        new_list.append(new_dictionary)
    return new_list

def undo(undoList: list, numberList: list):
    """
    Anuleaza ultima operatie efectuata (operatie care modifica lista)
    :param numberList: lista de dictionare
    :param undoList: lista de undo
    :return: -
    """
    if len(undoList) == 0:
        raise ValueError("Nu se mai poate face undo.")

    #se face un "revert" la ultima stare a listei de dinaintea
    #efectuarii operatiei la care se face undo
    lista_anterioara = undoList.pop()
    numberList.clear()
    numberList.extend(lista_anterioara)

def addToUndoList(undoList: list, listaCopiata: list)-> None:
    """
    :param undoList: lista de undo
    :param listaCopiata: lista copiata a listei initiale de numere complexe
    :return -; se adauga in lista de undo lista de numere complexe inainte de ultima operatie efectuata
    """
    undoList.append(listaCopiata)