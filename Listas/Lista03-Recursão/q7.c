#include <stdio.h>

// 7) Crie um programa em C que receba um vetor de números reais com 100 elementos.
// Escreva uma função recursiva que inverta ordem dos elementos presentes no vetor.

void inverteVetor(float *vetor, int inicio, int fim) {
    if (inicio < fim) {
        float aux = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = aux;
        inverteVetor(vetor, inicio + 1, fim - 1);
    }
}
