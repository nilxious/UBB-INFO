# Verifica daca numarul e prim
def checkPrime(number):
    primeValue = True
    for divider in range(2, number):
        if number % divider == 0:
            primeValue = False
            break
    return primeValue


# Primul numar prim mai mare decat numar
def primeBigger(number):
    number = number + 1
    if number <= 1:
        return 2
    while True:
        if checkPrime(number):
            return number
        else:
            number = number + 1


# Citire numar
n = int(input('Citeste un numar: '))
print(primeBigger(n))