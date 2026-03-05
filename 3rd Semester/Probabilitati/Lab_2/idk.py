from random import randint
from matplotlib.pyplot import plot, grid, title, show, axis
from random import random
import math

# a) same_bithrday_simulations
# fn(A) = rn(A)/n
# rn(A) -> nr de realizari ale evenimentului A in n incercari

def same_birthday_simulations(n, nr_sims):
    count = 0
    for _ in range(nr_sims):
        # birthdays -> genereaza n nr. aleatoare intre 1 si 365 folosing randint
        birthdays = [randint(1,365) for _ in range(n)]
        if len(birthdays) != len(set(birthdays)):
            count+=1
    return count/nr_sims


# b) consideram evenimentul contrar
# A' : "Toate persoanele au zile de mastere diferite"
# Daca p1 are ziua de nastere intr o zi "x",
# p2 va avea 364 posibilitati pt ziua de nastere,
# p3 -||- 363
# pn -||- 365-n+1
# p(A') = 365/365 * 364/365 * ... * (365-n+1)/365
# p(A) = 1 - p(A')
def same_birthday_two_people(n):
    p = 1
    for i in range(n):
        p *= (365-i)/365
    return 1-p

# c)
n = range(2,51)
y1=[same_birthday_simulations(x,1000) for x in n]
y2=[same_birthday_two_people(x) for x in n]

plot(n, y1, 'r*', label='Simulare')
plot(n, y2, 'b*', label='Doua persoane')
grid(True)
title("Plot test")
show()

#2 Consideram patratul ABCD cu l=1 si A(0,0), B(1,0)
# C(1,1), D(0,1), centrul cercului este E(1/2, 1/2)

# (i) d(E, P) < R; R = raza cercului, R = 1/2

def dist(a, b):
    return ((a[0] - b[0])**2 + (a[1] - b[1])**2) ** 0.5


def punct_patrat(nr_puncte, cerinta):
    axis('square')
    axis((0,1,0,1))
    contor = 0
    A,B,C,D,E = [0,0], [1,0], [1,1], [0,1], [0.5,0.5]
    match cerinta:
        case 1:
            count = 0
            for _ in range(nr_puncte):
                P = [random(), random()]
                if dist(E,P) < 0.5:
                    count += 1
                    plot(P[0],P[1], 'r*')
                else:
                    plot(P[0], P[1], '')
            show()
            return count/nr_puncte
        case 2:
            count = 0
            for _ in range(nr_puncte):
                P = [random(), random()]
                if dist(E,P) < min(dist(P,A), dist(P,B), dist(P,C), dist(P,D)):
                    count += 1
                    plot(P[0], P[1], 'b*')
                else:
                    plot(P[0], P[1], '')
            show()
            return count / nr_puncte
        case 3:
            count = 0
            for _ in range(nr_puncte):
                P = [random(), random()]
                tri = (dist(P,D)**2 + dist(P,A)**2 < 1 )+ (dist(P,A)**2 +dist(P,B)**2 < 1) + (dist(P,B)**2 + dist(P,C)**2 < 1) + (dist(P,C)**2 + dist(P,D)**2 < 1 )
                if tri == 2:
                    count += 1
                    plot(P[0], P[1], 'g*')
                else:
                    plot(P[0], P[1], '')
            show()
            return count / nr_puncte

#ii) dist(P,E) < min([dist(P,A), dist(P,B), dist(P,C), dist(P,D)])

#iii) a^2 = b^2 + c^2 -2*b*c*cosA
# PD^2 + PA^2 < AD^2 = 1
# PA^2+PB^2 < 1
# pb^2 + pc^2 < 1
# PD^2 + PC^2 < 1

# tri = (PD^2+PA^2 < 1 ) +
#       (PA^2+PB^2 < 1 ) +
#       (PB^2+PC^2 < 1 ) +
#       (PC^2+PD^2 < 1 )
# if tri == 2

p1 = math.pi/4 # (Arie cerc / Arie patrat)
p2 = 1/2 # ( Arie romb / Arie patrat)
p3 = math.pi/2-1

prob1 = punct_patrat(1000,1)
print(prob1)
print(f"i) Probabilitatea geometrica: {p1}")
prob2 = punct_patrat(1000,2)
print(prob2)
print(f"Probabilitatea geometrica: {p2}")
prob3 = punct_patrat(1000,3)
print(prob3)
print(f"Probabilitatea geometrica: {p3}")

