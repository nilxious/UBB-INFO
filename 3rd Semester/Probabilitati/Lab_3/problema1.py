import random

# 1. Participati la un concurs televizat si vi se ofera posibilitatea sa elegeti dintre 3 usi:
# in spatele uneia se afla o masina, iar in spatele celorlalte se alfa cate o capra. Dupa ce ati ales
#moderatorul (care stie ce se afla in spatele usilor) deschide o alta usa, in spatele careia se afla o capra
# apoi va ofera posibilitatea sa ramaneti cu usa aleasa sau sa o alegeti pe cealalta.

# a) Realizati simulari pentru fiecare situatie

# i Realizati simulari pt fiecare situatie: sa se genereze o pozitionare aleatoare a masinii
# si caprelor in spatele usilor

# ii sa se aleaga aleator o usa;

# iii sa se aleaga (aleator sau nu) o usa care ascunde o capra;

# iv dupa caz, sa se schimbe sau nu usa

# b) Estimati probabilitatea de a castiga masina, pentru fiecare situatie

def Monty_HalL_Simulations(nr_simulari, schimba_usa=False,alegere=False):
    count=0
    for _ in range(nr_simulari):
        # i. pozitionare aleatoare masina + capre
        asezare = ["c","c","c"]
        masina,capra1,capra2=random.sample([0,1,2],3)
        asezare[masina] = "m"

        # ii. jucatorul alege o usa aleator
        prima_alegere = random.randint(0,2)

        # iii. prezentatorul deschide o usa cu capra
        if ( prima_alegere == masina):
            #alegere_prezentator -> aleator intre c1 si c2
            alegere_prezentator=random.choice([capra1,capra2])
        elif(prima_alegere == capra1):
            #alegere_prezentator -> capra2
            alegere_prezentator=capra2
        else:
            #alegere_prezentator -> capra1'
            alegere_prezentator=capra1

        # iv. schimba sau nu usa
        if schimba_usa:
            # alegem usa ramasa (nu prima si nu prezentatorul)
            for usa in [0, 1, 2]:
                if usa != prima_alegere and usa != alegere_prezentator:
                    alegere_finala = usa
                    break
        else:
            alegere_finala = prima_alegere

        # verificam daca jucatorul castiga
        if asezare[alegere_finala] == "m":
            count += 1

    return count / nr_simulari

print("Fara schimbare:", Monty_HalL_Simulations(10000, schimba_usa=False))
print("Cu schimbare:", Monty_HalL_Simulations(10000, schimba_usa=True))