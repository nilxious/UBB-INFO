"""Lab 3 – Fundamentele programării
    
        Se predă în săptămâna 3
    
    Scrieti o aplicatie care are interfata utilizator tip consolă cu un meniu:
    1 Citirea unei liste de numere intregi
    2,3 Gasirea secventelor de lungime maxima care respectă o proprietatea dată. Fiecare student primeste 2 proprietati din lista
    de mai jos.
    4 Iesire din aplicatie.
    Documentatia să contină:
        Scenarii de rulare pentru cele două cerinte primite (vezi curs 1 – scenarii de rulare)
        Cazuri de testare pentru cele doua cerinte în format tabelar (vezi curs 1 – cazuri de testare)
    
    4. Conține doar numere prime
    8. Au toate elementele în intervalul [0, 10] dat
"""

# Definirea meniului - Afișează opțiunile utilizatorului
def menu():
    print("1 - Citește lista de numere intregi")
    print("2 - Găsește secvențele de lungime maximă care au toate elementele numere prime")
    print("3 - Găsește secvențele de lungime maximă care au toate elementele in intervalul [0,10]")
    print("4 - Găsește secvențele de lungime maximă care au p=1 sau in oricare 3 elemente consecutive o valoare egala")
    print("5 - Ieșire din aplicație")
    print()

# Proprietatea 4. Conține doar numere prime
# Verifică dacă un număr este prim
def condition4(number):
    if number <= 1: return False
    if number == 2: return True
    if number % 2 == 0: return False
    # Verificăm doar divizorii impari până la sqrt(number)
    for divisor in range(3, int(number ** 0.5)+1, 2):
        if number % divisor == 0: return False
    return True

# Proprietatea 8. Au toate elementele în intervalul [0, 10] dat
# Verifică dacă un număr se află în intervalul [0, 10]
def condition8(number):
    return 0 <= number <= 10

def condition9(subList):
    if len(subList) < 3 : return False
    return subList[0] == subList[1] or subList[0] == subList[2] or subList[1] == subList[2]

# Citirea unei liste de numere întregi
# Citește o listă de numere întregi de la utilizator, toate introduse pe o linie
def readList():
    numList = [] # Lista pentru stocarea numerelor
    numOfElements = int(input("Numărul de elemente ale listei: "))

    # Verificăm dacă numărul de elemente este valid (minim 1 element)
    if numOfElements <= 0:
        print("Lista trebuie să conțină cel puțin un element.")
        print()
        return readList() # Reapelăm funcția dacă nu e valid

    # Citim numerele de pe o singură linie, separate prin spațiu
    numbers = input(f"Introduceți cele {numOfElements} numere, separate prin spațiu: ").split()

    # Convertim fiecare număr din string în int și adăugăm în listă
    numList = [int(number) for number in numbers]
    return numList

# Aflarea secvențelor de lungime maximă care verifică o anumită condiție
def getSequences(numList, condition):
    maxLength = - 1
    sequences = [] # Listă pentru stocarea secvențelor
    startPos = 0 # Poziția de start a secvenței curente
    endPos = 0 # Poziția de sfârșit a secvenței curente

    for number in numList:
        if condition(number):
            if not condition(numList[startPos]):
                startPos += 1
            endPos += 1
        else:
            sequence = numList[startPos:endPos]
            if len(sequence) > maxLength and endPos != startPos:
                sequences = []
                maxLength = len(sequence)
                sequences.append(sequence)
            # Resetăm pozițiile pentru o nouă secvență
            elif len(sequence) == maxLength and endPos != startPos:
                sequences.append(sequence)
            startPos = endPos + 1
            endPos = startPos
    if len(numList[startPos:endPos]) >= maxLength and endPos != startPos:
        sequence = numList[startPos:endPos]
        sequences.append(sequence)

    return sequences

# Problema 9
def problema9(numList, condition):
    maxLength = -1
    sequences = []
    startPos = 0
    endPos = 0

    while endPos < len(numList):
        if endPos - startPos + 1 >= 3:
            if condition9(numList[endPos-2:endPos+1]):
                print()
                endPos += 1
            else:
                sequence = numList[startPos:endPos]
                if len(sequence) >= 3:
                    if len(sequence) > maxLength:
                        sequences = [sequence]
                        maxLength = len(sequence)
                    elif len(sequence) == maxLength:
                        sequences.append(sequence)
                startPos += 1
        else:
            endPos += 1

    if endPos - startPos >= 3:
        sequence = numList[startPos:endPos]
        if len(sequence) > maxLength:
            sequences = [sequence]
        elif len(sequence) == maxLength:
            sequences.append(sequence)

    return sequences


#testare
def testare():
    assert(getSequences([14, 9, 9, 9, 22, 5, 4, 9, 8, 44, 44, 10, 10, 10, 10], condition8)) == [[5, 4, 9, 8], [10, 10, 10, 10]]
    assert(getSequences([28, 28, 28, 28, 28, 28, 28], condition4)) == []
    assert(getSequences([0, 2, 5, 7, 13, 99, 3, 3, 3, 3], condition4)) == [[2, 5, 7, 13], [3, 3, 3, 3]]
    assert(getSequences([5, 5, 5, 5, 5], condition8)) == [[5, 5, 5, 5, 5]]
    assert(problema9([1, 2, 1, 2, 5, 6 ,7 ,8 ,9, 4, 5, 4, 5], condition9)) == [[1,2,1,2],[4,5,4,5]]
    print("Testele au mers")

# Program principal
def main():
    numList = None # Inițial lista nu există
    menu() # Afișăm meniul utilizatorului
    while True:
        # Citim comanda utilizatorului
        command = input("Alege una dintre comenzi: ")

        # Opțiunea 1: Citirea listei de numere întregi
        if command == "1":
            numList = readList()

        # Opțiunea 2: Găsirea secvențelor cu numere prime
        elif command == "2":
            if numList is None:
                print("Încă nu ai creat lista")
            else:
                sequences = getSequences(numList, condition4)
                if sequences == []:
                    print("Nu s-a găsit nici o secvență")
                else:
                    print("Secvențele găsite:", sequences)

        # Opțiunea 3: Găsirea secvențelor care sunt în intervalul [0,10]
        elif command == "3":
            if numList is None:
                print("Încă nu ai creat lista")
            else:
                sequences = getSequences(numList, condition8)
                if sequences == []:
                    print("Nu s-a găsit nici o secvență")
                else:
                    print("Secvențele găsite:", sequences)

        elif command == "4":
            if numList is None:
                print("Încă nu ai creat lista")
            else:
                sequences = problema9(numList, condition9)
                if sequences == []:
                    print("Nu s-a găsit nici o secvență")
                else:
                    print("Secvențele găsite:", sequences)
        # Opțiunea 5: Ieșirea din aplicație
        elif command == "5":
            print("Ieșire din aplicație.")
            break

        # Dacă utilizatorul introduce o comandă greșită
        else:
            print("Tastă incorectă. Te rog să alegi din nou.")
            print()
            menu() # Reafișăm meniul

# Executăm programul principal
testare()
main()