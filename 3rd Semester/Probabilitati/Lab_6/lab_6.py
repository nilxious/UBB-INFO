from scipy.stats import norm
from numpy import mean, std, linspace
from matplotlib.pyplot import show, hist, grid, legend, xticks, plot

#i)
# m = 165 (val. medie teoretica)
# sigma = 10 (dev. standard. teoretica)
data = norm.rvs(loc=165,scale=10,size=5000)

hist(data, bins=14, density = True,range=(130,200),label='frecvențe relative')

x = linspace(130,200,1000)
# functia de densitate -> norm.pdf
plot(x,norm.pdf(x,loc=165,scale=10),'r-',label='funcția de densitate')

xticks(range(130,200,5))
legend(loc='upper right')
grid()
show()

#ii)
print("Valorea medie", data.mean(), "Deviatia standard", data.std())

print("Proportia de valori in [160, 170], valoarea medie:", mean((160<=data)&(data<=170)), "deviatai standard", norm.cdf(170,loc=165,scale=10)-norm.cdf(160,loc=165,scale=10), "proportia de valori", sum((160<=data)&(data<=170))/5000)


# Problema 2

from scipy.stats import expon, uniform
from numpy import mean, std

n = 5000
lambdaa = 1/5
p = uniform.rvs(size = n)
timp = expon.rvs(loc=0,scale=1/lambdaa,size=n)*(p<0.4)+uniform.rvs(loc=4,scale=2,size=n)*(p>=0.4)

#valoarea medie -> mean
#deviatie standard estimata -> std
print("Valoarea medie:", timp.mean(), "Deviatia standard:", timp.std())

# 0,4 * F1(5) + 0,6 * F2(5)
# F1(5) = expon.ccdf(5,loc=0.scale=1/lambdaa)
# F2(5) = uniform.cdf(5,loc=a,scale=b-a)
# a = 4
# b = 6
# b - a = 2
print("Valorea medie", mean(timp<5), 0.4*expon.cdf(5,loc=0,scale=1/lambdaa)+0.6*uniform.cdf(5,loc=4,scale=2))

from numpy import exp

print("Probabilitatea teoretica pentru b) ", 0.4*(1-exp(-1))+0.6*0.5)

# Problema 3

from scipy.stats import uniform
from numpy import exp, mean
from scipy.integrate import quad

n=5000
u = uniform.rvs(loc=-1,scale=4,size=n)   #  scale=4 (b-a)  adica (3-(-1))
g = lambda x : exp(-x**2)

print("Prima aproximare", mean(4*g(u)))

print("Aproximare (cuadratura)", quad(g,-1,3))