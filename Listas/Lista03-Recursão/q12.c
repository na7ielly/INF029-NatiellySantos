#include <stdio.h>

// 12) Faça uma função recursiva que receba um número inteiro positivo N e imprima 
// todos os números naturais de 0 até N em ordem crescente. 

void imprimirNumero(int n) {
    if (n < 0) { 
        return; // 
    }

    if (n > 0) {
        imprimirNumero(n - 1);
    }

    printf("%d ", n); // Impressão após a recursão para manter ordem crescente
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