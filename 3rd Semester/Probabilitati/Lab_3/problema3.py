# 3. Intr-o urna sunt 6 bile cu cifra 1 inscriptionata si 4 bile cu cifra 0. Se extrag aleator cu returnare
# 5 bile din urna. Fie X variabila aleatoare care indica suma numerelor de pe bilele extrase.

# a) Generati o lista de 1000 valori pentru X.
# b) Afisati histograma frecventelor relative si barele corespunzatoare valorilor teoretice.
# c) Estimati probabilitatea P(2< X <= 5) si afisati valoarea teoretica.
# Folositi metodele rvs, pmf, cdf ale clasei binom:
# from scipy.stats import binom
# help('scipy.statsbinom')

import random
from matplotlib.pyplot import bar, hist, grid, show, legend
from scipy.stats import binom

# urna: 6 bile cu 1, 4 bile cu 0; extragem 5 bile cu returnare
p = 6 / 10  # probabilitatea de a extrage 1
n = 5       # numărul de extrageri

# a) Generăm 1000 valori ale variabilei X (suma numerelor extrase)
X = [sum(random.choices([1,0], weights=[6,4], k=n)) for _ in range(1000)]

# b) histogramă a frecvențelor relative și probabilități teoretice
bin_edges = [-0.5 + i for i in range(n+2)]  # marginile bin-urilor: de la -0.5 la n+0.5
hist(X, bins=bin_edges, density=True, rwidth=0.9, color='green', edgecolor='black',
     alpha=0.5, label='frecvente relative')

# probabilități teoretice
x_vals = list(range(n+1))  # valorile posibile ale lui X: 0,1,2,3,4,5
pmf_vals = [binom.pmf(k, n, p) for k in x_vals]

# afișăm probabilitățile teoretice sub formă de bare roșii
bar(x_vals, pmf_vals, width=0.6, color='red', edgecolor='black', alpha=0.6, label='probabilitati teoretice')
legend(loc='upper right')
grid()
show()

# c) estimăm probabilitatea P(2 < X <= 5)
sim_prob = sum(1 for x in X if 2 < x <= 5) / len(X)  # simulare
theor_prob = binom.cdf(5, n, p) - binom.cdf(2, n, p)  # teoretic

print(f"Probabilitate simulată P(2 < X <= 5): {sim_prob:.4f}")
print(f"Probabilitate teoretică P(2 < X <= 5): {theor_prob:.4f}")
