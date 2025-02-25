#include <stdio.h>

// 13) Faça uma função recursiva que receba um número inteiro positivo N e imprima todos os números naturais 
// de 0 até N em ordem decrescente. 

#include <stdio.h>

void imprimirNumero(int n) {
    if (n < 0) { 
        return;
    }

    printf("%d ", n); // Imprime primeiro para garantir ordem decrescente
    imprimirNumero(n - 1); // Chamada recursiva com n-1
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n >= 0) {
        imprimirNumero(n);
    } else {
        printf("Número inválido!\n");
    }

    return 0;
}