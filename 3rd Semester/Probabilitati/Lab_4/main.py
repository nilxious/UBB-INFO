
# 1.
# a)
import numpy as np

from scipy.stats import bernoulli
import matplotlib.pyplot as plt

def random_walk_line(num_steps, p):
    x = bernoulli.rvs(p, size=num_steps)  # 0 sau 1
    poz_initial = 0
    lista_pozitii = [poz_initial]

    for pas in x:
        step = 2*int(pas) - 1  # 0->-1, 1->+1
        poz_initial += step
        lista_pozitii.append(poz_initial)

    lista_pozitii = [int(p) for p in lista_pozitii]
    return lista_pozitii

# a) exemplu
positions = random_walk_line(20, 0.6)
print("Pozitii random walk:", positions)

from math import comb
# b)
from math import comb
import matplotlib.pyplot as plt


def random_walk_line_simulated_hist(num_steps, p, num_simulations=1000):
    final_positions = []

    # simulare
    for _ in range(num_simulations):
        final_positions.append(random_walk_line(num_steps, p)[-1])

    # histograma simulata
    plt.figure(figsize=(8, 5))
    plt.hist(final_positions, bins=range(min(final_positions), max(final_positions) + 2),
             density=True, alpha=0.6, edgecolor='black', label="Simulata")

    # histograma teoretica
    positions = []
    probabilities = []
    for k in range(num_steps + 1):
        pos = 2 * k - num_steps
        prob = comb(num_steps, k) * (p ** k) * ((1 - p) ** (num_steps - k))
        positions.append(pos)
        probabilities.append(prob)

    plt.bar(positions, probabilities, alpha=0.4, color='red', edgecolor='black', label="Teoretica")

    plt.xlabel("Pozitia finala")
    plt.ylabel("Frecventa relativa / Probabilitate")
    plt.title(f"Histograma pozitiilor finale (simulata vs teoretica)")
    plt.grid(True)
    plt.legend()
    plt.show()


# Exemplu de apel

random_walk_line_simulated_hist(num_steps=20, p=0.6)

# c)
# Random walk pe cerc folosind bernoulli
def random_walk_circle(num_steps, p, n):
    x = bernoulli.rvs(p, size=num_steps)  # 0 sau 1
    poz_initial = 0
    positions = [poz_initial]

    for pas in x:
        step = 2 * int(pas) - 1  # 0 -> -1, 1 -> +1
        poz_initial = (poz_initial + step) % n
        positions.append(poz_initial)

    return positions


# Exemplu: random walk pe cerc cu 10 noduri
positions_circle = random_walk_circle(num_steps=20, p=0.6, n=10)
print("Pozitii random walk pe cerc:", positions_circle)


# Histograma pozitii finale dupa mai multe simulari
def random_walk_circle_simulated_hist(num_steps, p, n, num_simulations=1000):
    final_positions = []

    # simulare
    for _ in range(num_simulations):
        final_positions.append(random_walk_circle(num_steps, p, n)[-1])

    plt.figure(figsize=(8,5))

    # Histograma simulata
    plt.hist(final_positions, bins=range(n+1), density=True, alpha=0.6, edgecolor='black',
             label="Simulata", align='left')

    # Histograma teoretica
    pos_prob = {i: 0 for i in range(n)}
    for k in range(num_steps + 1):
        pos = (2*k - num_steps) % n
        prob = comb(num_steps, k) * (p**k) * ((1-p)**(num_steps - k))
        pos_prob[pos] += prob  # adunam probabilitatile care coincid pe cerc

    positions = list(pos_prob.keys())
    probabilities = list(pos_prob.values())

    plt.bar(positions, probabilities, alpha=0.4, color='red', edgecolor='black', label="Teoretica")

    plt.xlabel("Pozitia finala (pe cerc)")
    plt.ylabel("Frecventa relativa / Probabilitate")
    plt.title(f"Histograma pozitiilor finale pe cerc (simulata vs teoretica, n={n})")
    plt.grid(True)
    plt.legend()
    plt.show()



# Exemplu histogramă
random_walk_circle_simulated_hist(num_steps=20, p=0.6, n=10)

# -------------------------------------------------------------------------------------------------

# 2)

from scipy.stats import hypergeom

from scipy.stats import hypergeom, geom

def loto_sim(num_simulations=100000):
    M, n, N = 49, 6, 6

    total_tickets = 0
    total_successes = 0
    counts_until_success = []

    for _ in range(num_simulations):
        count = 0
        while True:
            total_tickets += 1
            k = hypergeom.rvs(M, n, N)
            if k >= 3:  # bilet castigator
                total_successes += 1
                break
            count += 1
        counts_until_success.append(count)

    estimated_prob = total_successes / total_tickets
    return counts_until_success, estimated_prob


# Simulare
counts, estimated_prob = loto_sim(num_simulations=10000)
print("Exemple de numar de bilete necastigatoare:", counts[:10])
print("Probabilitate estimata bilet castigator:", estimated_prob)

# Probabilitatea teoretica
M, n, N = 49, 6, 6
p_success = sum([hypergeom.pmf(k, M, n, N) for k in range(3, 7)])
print("Probabilitate teoretica bilet castigator:", p_success)

# Probabilitatea ca sa fie cel putin 10 bilete necastigatoare succesive
prob_at_least_10 = geom.sf(9, p_success)
print("Probabilitate cel putin 10 bilete necastigatoare:", prob_at_least_10)

# Estimare probabilitate cel putin 10 bilete necastigatoare succesive
count_10_or_more = sum(1 for c in counts if c >= 10)
prob_estimated_10_or_more = count_10_or_more / len(counts)

print("Probabilitate estimata cel putin 10 bilete necastigatoare consecutive:", prob_estimated_10_or_more)
