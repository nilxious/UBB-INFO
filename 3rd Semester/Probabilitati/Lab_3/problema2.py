# 2. Se simuleaza aruncarea unui zar de 500 de ori. Afisati histograma frecventelor relative ale numerelor
# obtinute si barele corespunzatoare probabilitatilor teoretice, inlocuind semnele de intrebare din codul urmator


from random import randrange
from matplotlib.pyplot import bar, hist, grid, show, legend

# 500 aruncari de zar (de la  1 la 6)
data = [randrange(1, 7) for _ in range(500)]

# bin-uri pentru histograma
bin_edges = [k + 0.5 for k in range(1, 7)]

# plot histogrm de frecvente relative
hist(data, bins=bin_edges, density=True, rwidth=0.9, color='green', edgecolor='black',
     alpha=0.5, label='frecvente relative')

# probabilitati teoretice pentru un zar
distribution = dict([(i, 1/6) for i in range(1, 7)])

# plot la probabilitati teoretice ca si bari rosii
bar(list(distribution.keys()), list(distribution.values()), width=0.85, color='red', edgecolor='black',
    alpha=0.6, label='probabilitati')

legend(loc='lower left')
grid()
show()
