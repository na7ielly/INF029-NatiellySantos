#include <stdio.h>

// 4) Faça uma função recursiva que permita somar os elementos de um vetor de
// inteiros.

int somarVetor (int *vetor, int tamanho){

    if (tamanho == 0){
        return vetor[tamanho];
    }

    return vetor[tamanho] + somarVetor(vetor, tamanho - 1);
}