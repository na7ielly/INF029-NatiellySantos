/*
QUESTÃO 02:
Faça um programa que tenha uma função troca que recebe dois parâmetros inteiros e troque o valor 
das variáveis um pelo outro. A função main deve ler do usuário os dois valores, chamar a função troca, 
e depois imprimir os valores trocados.
*/

#include "funcoesGerais.h"

void troca(int *valor1, int *valor2)
{
    int aux = *valor1;
    *valor1 = *valor2;
    *valor2 = aux;
}

int main()
{
    int valor1, valor2;
    
    printf("Valor 1: ");
    scanf("%d", &valor1);

    printf("Valor 2: ");
    scanf("%d", &valor2);

    printf("\nAntes da troca:\n");
    printf("Valor 1: %d\n", valor1);
    printf("Valor 2: %d\n", valor2);

    troca(&valor1, &valor2);

    printf("\nDepois da troca:\n");
    printf("Valor 1: %d\n", valor1);
    printf("Valor 2: %d\n", valor2);

    return 0;
}