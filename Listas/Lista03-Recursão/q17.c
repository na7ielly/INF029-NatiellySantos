#include <stdio.h>

/* 17) O fatorial quádruplo de um número N é dado por:
        (2n)! / n!                */        

// Faça uma função recursiva que receba um número inteiro positivo N e retorne o fatorial quádruplo desse número. 

// Função recursiva para calcular o fatorial de um número
long long fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base: 0! = 1 e 1! = 1
    }
    return n * fatorial(n - 1); // Chamada recursiva para calcular o fatorial
}

// Função para calcular o fatorial quádruplo
long long fatorialQuadruplo(int n) {
    return fatorial(2 * n) / fatorial(n); // Fórmula: (2n)! / n!
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n >= 0) {
        printf("Fatorial quádruplo de %d é: %lld\n", n, fatorialQuadruplo(n));
    } else {
        printf("Número inválido! Digite um número positivo.\n");
    }

    return 0;
}
