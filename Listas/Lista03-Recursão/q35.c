#include <stdio.h>

/* 35) Dado um número n na base decimal, escreva uma função recursiva em C que converte este número para binário. */

void decimalParaBinario(int n) {
    if (n == 0) {
        return; // Caso base: quando n chega a 0, a recursão para
    }

    decimalParaBinario(n / 2); // Chamada recursiva para imprimir os bits mais significativos primeiro
    printf("%d", n % 2); // Imprime o bit menos significativo após a recursão
}

int main() {
    int n;
    
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro! O número deve ser positivo.\n");
    } else {
        printf("O número %d em binário é: ", n);
        if (n == 0) {
            printf("0"); // Caso especial para n = 0
        } else {
            decimalParaBinario(n);
        }
        printf("\n");
    }

    return 0;
}
