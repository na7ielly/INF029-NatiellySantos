/*
QUESTÃO 03:
Faça um programa que tenha uma função ordena que recebe um vetor de inteiros e ordene os valores. 
A função main deve ler do usuário os valores (ex. 5 valores), chamar a função ordena, e depois imprimir 
os valores ordenados.
*/

#include "funcoesGerais.h"

int main()
{
    int tamanho;

    printf("Vetor: \n");
    printf("Tamanho: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++)
    {
        printf("Posição %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    quickSort(vetor, 0, (tamanho -1));
    
    for (int j = 0; j < tamanho; j++)
    {
        if (j == tamanho - 1)
            printf("%d\n", vetor[j]); // Último elemento sem vírgula
        else
            printf("%d, ", vetor[j]);
    }

    free(vetor); 
}
