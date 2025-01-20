#ifndef FUNCOESGERAIS_H
#define FUNCOESGERAIS_H

#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"
#include "constantes.h"

// Algoritmo de ordenação Quick Sort

int particiona(int *vetor, int inicio, int fim)
{
    // 1° passo: média entre a posição de inicio, fim e média entre início e fim.
    int pivo = (vetor[inicio] + vetor[fim] + vetor[(inicio+fim)/2]) /3;

    while(inicio < fim)
    {
        /* Procurando um elemento maior que o pivô (que DEVE estar no meio do vetor) do lado esquerdo do vetor; 
        enquanto o elemento for menor ou igual ao pivô, vai pulando para a próxima posição até encontrar um elemento 
        maior que pivô e interromper o laço
                                         ------------->                     
        Pensando no vetor com elementos: 47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61
        Nesse caso o pivô é = 54 
        O valor da posição início = 4 */
        while(inicio < fim && vetor[inicio] <= pivo){
            inicio++;
        }
        /* Procurando um elemento menor (que o pivô) que esteja do lado direito (que deve conter os valores maiores), 
        enquanto for maior ele vai passando para o lado esquerdo até acha o pivô:
                                                                                  <------------- 
        Pensando no vetor com elementos: 47, 35, 12, 49, 56, 25, 71, 83, 5, 3, 1, 70, 99, 10, 61
        O valor da posição fim = 13 */
        while(inicio < fim && vetor[fim] > pivo){
            fim--;
        }
        /*Fazer a troca dos valores da posição inicio e fim, ou seja: vetor [posição inicio] = 10, 
        vetor [posição fim] = 56 */
        int aux = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = aux;
    }
    return inicio; // Quando a retição terminar, significa que a posição de inicio é igual ao fim.  
}

void quickSort(int *vetor, int inicio, int fim) // Logo no início, posição inicio = 0, posição fim = 14
{
    if(inicio < fim){
        int pos = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pos - 1);
        quickSort(vetor, pos, fim);
    }
}


#endif  // FUNCOESGERAIS_H