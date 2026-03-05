import math
from random import sample
from math import factorial, perm, comb
from itertools import permutations, combinations
from itertools import combinations_with_replacement

# a) afisati o lista cu toate permutarile cuvantului word
# b) afisati numarul total al permutarilor cuvantului word
# c) afisati o permutare aleatoare a cuvantului word


cuvant = "word"

lista = []

# a)
for pairs in permutations(cuvant):
    print(''.join(pairs))

# b)
nr_perm=factorial(len(cuvant))
print(f"numarul total al permutarilor cuvantului word este {nr_perm}")

# c) aleatorie
print(''.join(sample(cuvant,len(cuvant))))

# permutations(lista,k)  ->  arnjamente de n luate cate k
# combinations(lista, k)
# perm(n,k) aranjamente de n luate cate k
# comb(n,k) combinari de n luate cate k

# 3)
# aranjamente
nr_total_aranjamente=0
print("\nAranjamente:")
for i in range(1, len(cuvant) + 1):
    for p in permutations(cuvant, i):
        print(''.join(p))
    print(f"Numar aranjamente de {i}: {perm(len(cuvant), i)}")
    nr_total_aranjamente+=perm(len(cuvant),i)
    print("Exemplu aranjament aleator:", ''.join(sample(cuvant, i)))
    print()

print(f"Numar total de aranjamente {nr_total_aranjamente}")

# combinatii
nr_total_combinatii = 0
print("Combinatii:")
for i in range(1, len(cuvant) + 1):
    for c in combinations(cuvant, i):
        print(''.join(c))
    print(f"Numar combinații de {i}: {comb(len(cuvant), i)}")
    nr_total_combinatii += comb(len(cuvant), i)
    print("Exemplu combinatie aleatoare:", ''.join(sample(cuvant, i)))
    print()

print(f"Numar total de combinari {nr_total_combinatii}")

# 4) Afisati toate combinarile cu repetitie de 4 elemente din grupul de litere ABCDE folosind
# from itertools import combinations_with_replacement

litere="ABCDE"

combinatii_cu_repetitie = [''.join(c) for c in combinations_with_replacement(litere, 4)]

print("Toate combinatiile cu repetitie de 4 elemente din ABCDE:")
for c in combinatii_cu_repetitie:
    print(c)

print(f"\nNumărul total de combinatii cu repetitie: {len(combinatii_cu_repetitie)}")

#5
rez=math.perm(8, 5)
print(rez)