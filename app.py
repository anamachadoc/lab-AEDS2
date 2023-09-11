import numpy as np
import matplotlib.pyplot as plt 
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
x = []
y = []

with open('output.txt', 'r') as f:
    for line in f:
        cols = line.split()
        if float(cols[2]) != 0.0:
            x.append(int(cols[0]))
            y.append(float(cols[4]))
            
plt.legend()
plt.plot(x,y, 'o',color='black',markersize=1,label='Dados Originais')
plt.xlabel('Número de Pontos')
plt.ylabel('Tempo de Execução(s)')
plt.xlim(0,1000)
plt.ylim(0,0.02)
plt.title('Algoritmo Polinomial')
plt.show()