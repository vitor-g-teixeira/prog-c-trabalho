import matplotlib.pyplot as plt

# Tamanhos de entrada
sizes = [10000, 50000, 100000, 200000]

# Dados: tempos médios
bubble_best = [0.009631, 0.010016, 0.010496, 0.011565]
bubble_worst = [0.270061, 6.213826, 24.808929, 104.555890]
bubble_medium = [0.310803, 8.742995, 34.892848, 136.339141]

selection_best = [0.283647, 2.425385, 9.079489, 35.185354]
selection_worst = [0.155527, 2.292089, 9.224061, 36.373338]
selection_medium = [0.295471, 2.417847, 8.935236, 35.075533]

# Plot
plt.figure(figsize=(12, 7))
plt.plot(sizes, bubble_best, label='Bubble Sort - Best Case', marker='o')
plt.plot(sizes, bubble_medium, label='Bubble Sort - Medium Case', marker='o')
plt.plot(sizes, bubble_worst, label='Bubble Sort - Worst Case', marker='o')

plt.plot(sizes, selection_best, label='Selection Sort - Best Case', marker='x')
plt.plot(sizes, selection_medium, label='Selection Sort - Medium Case', marker='x')
plt.plot(sizes, selection_worst, label='Selection Sort - Worst Case', marker='x')

plt.title('Desempenho dos Algoritmos Bubble Sort e Selection Sort')
plt.xlabel('Tamanho da entrada (n)')
plt.ylabel('Tempo médio de execução (segundos)')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.yscale('log')  # Escala log para melhor visualização
plt.show()
