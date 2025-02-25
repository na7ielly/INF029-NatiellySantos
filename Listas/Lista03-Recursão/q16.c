#include <stdio.h>

// 16) A função fatorial duplo é definida como o produto de todos os números naturais ímpares
// de 1 até algum número natural ímpar N. Assim, o fatorial duplo de 5 é 5!! = 1 * 3 * 5 = 15 
// Faça uma função recursiva que receba um número inteiro positivo impar N e retorne o fatorial duplo desse número. 

#include <stdio.h>

int fatorialDuplo(int n) {
    if (n == 1) { 
        return 1; // Caso base: 1!! = 1
    }
    return n * fatorialDuplo(n - 2); // Chamada recursiva reduzindo de 2 em 2
}

int main() {
    int n;
    printf("Digite um número inteiro positivo ímpar: ");
    scanf("%d", &n);

    if (n > 0 && n % 2 == 1) {
        printf("Fatorial duplo de %d é: %d\n", n, fatorialDuplo(n));
    } else {
        printf("Número inválido! Digite um número ímpar positivo.\n");
    }

    return 0;
}
