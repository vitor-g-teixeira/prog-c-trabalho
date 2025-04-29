import subprocess
import time
import os

# Configurações
ARQUIVO_C = "bubbleSortR.c"
EXECUTAVEL = "bubbleSortR.exe"
NUM_EXECUCOES = 30

def compilar_c(arquivo_c, executavel):
    print("Compilando...")
    resultado = subprocess.run(["gcc", arquivo_c, "-o", executavel], capture_output=True, text=True)
    if resultado.returncode != 0:
        print("Erro na compilação:")
        print(resultado.stderr)
        exit(1)

def medir_execucao(executavel):
    inicio = time.perf_counter()
    subprocess.run([executavel], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    fim = time.perf_counter()
    return fim - inicio

def main():
    compilar_c(ARQUIVO_C, EXECUTAVEL)

    tempos = []
    for _ in range(NUM_EXECUCOES):
        tempo = medir_execucao(EXECUTAVEL)
        tempos.append(tempo)

    tempo_medio = sum(tempos) / NUM_EXECUCOES
    melhor_tempo = min(tempos)
    pior_tempo = max(tempos)

    print(f"Executado {NUM_EXECUCOES} vezes")
    print(f"Tempo médio: {tempo_medio:.6f} segundos")
    print(f"Melhor tempo (mais rápido): {melhor_tempo:.6f} segundos")
    print(f"Pior tempo (mais lento): {pior_tempo:.6f} segundos")

    # Opcional: limpa o executável
    os.remove(EXECUTAVEL)

if __name__ == "__main__":
    main()
