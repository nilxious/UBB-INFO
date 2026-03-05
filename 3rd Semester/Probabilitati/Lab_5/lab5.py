from scipy.stats import uniform


# problema 1
def generare_nr_pseudoaleatoare_discret(valori, probabilitati,N):
    X=[]
    U = uniform.rvs(size=N)
    for i in range(N):
        pozitie = 0
        sum_prob = probabilitati[0]
        while U[i] > sum_prob:         #  U[i] <= sum_prob
            pozitie+=1
            sum_prob+=probabilitati[pozitie]
        X.append(valori[pozitie])      # atunci X.append(valori[pozitie-1])
    return X


from matplotlib.pyplot import bar, show, hist, grid, legend, xticks, yticks

valori, probabilitati = range(4), (0.46, 0.40, 0.10, 0.04)

data = generare_nr_pseudoaleatoare_discret(valori,probabilitati,1000)
bin_edges = [i+0.5 for i in range(-1,4)]
hist(data, bin_edges, density = True, rwidth=0.9, color ='green',
     edgecolor='black', alpha = 0.5, label='frecvente relative')

distribution = dict([(k,probabilitati[k]) for k in range(4)])
bar(distribution.keys(),distribution.values(), width=0.85,color='red',
    edgecolor='black',alpha=0.6, label='probabilitati')

xticks(ticks=range(4),labels=("0","A","B","AB"))
yticks([k/100 for k in range(0,55,5)])
legend(loc='upper right')
grid()
show()

#problema 2

from math import log
from scipy.stats import expon
from matplotlib.pyplot import plot


def my_exp_rand_vals(alpha,N):
    U = uniform.rvs(size=N)
    X = [-1/alpha*log(1-U[i]) for i in range(N)]
    return X

alpha = 1/12

data = my_exp_rand_vals(alpha,2000)
#or data = expon.rvs(loc=0,scale=12,size=1000)
hist(data, bins=12, density = True,range=(0,60))

x = range(60)
plot(x,expon.pdf(x,loc=0,scale=1/alpha),'r-')

xticks(range(0,60,5))
grid()
show()




