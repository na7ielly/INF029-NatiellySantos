#include <stdio.h>

/* 33) Crie um programa em C, que contenha uma função recursiva para encontrar o menor elemento em um vetor. 
A leitura dos elementos do vetor e impressão do menor elemento devem ser feitas no programa principal.  */

int menorElemento(int vetor[], int tamanho, int indice) {
    if (indice == tamanho - 1) {
        return vetor[indice]; // Caso base: último elemento do vetor
    }

    int menorRestante = menorElemento(vetor, tamanho, indice + 1); // Chamada recursiva
    return (vetor[indice] < menorRestante) ? vetor[indice] : menorRestante; // Retorna o menor valor
}

int main() {
    int n;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("O tamanho do vetor deve ser maior que zero.\n");
        return 1;
    }

    int vetor[n];
    
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("O menor elemento do vetor é: %d\n", menorElemento(vetor, n, 0));

    return 0;
}
