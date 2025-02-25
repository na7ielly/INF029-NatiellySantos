#include <stdio.h>
#include <math.h> 

/* 19) O hiperfatorial de um número N, escrito H(n), é definido por:

        H(n) = 1^1 * 2^2 * 3^3 * ...(n-1)^n-1 * n^n 

Faça uma função recursiva que receba um número inteiro positivo N e retorne o hiperfatorial desse número.  */


long long hiperfatorial(int n) {
    if (n == 1) {
        return 1; // Caso base: H(1) = 1^1 = 1
    }
    return pow(n, n) * hiperfatorial(n - 1); // Multiplica n^n pelo hiperfatorial de (n-1)
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Hiperfatorial de %d é: %lld\n", n, hiperfatorial(n));
    } else {
        printf("Número inválido! Digite um número positivo.\n");
    }

    return 0;
}

// Sem usar pow
/* 

long long potencia(int base, int expoente) {
    long long resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

// Função recursiva para calcular o hiperfatorial
long long hiperfatorial(int n) {
    if (n == 1) {
        return 1; // Caso base: H(1) = 1^1 = 1
    }
    return potencia(n, n) * hiperfatorial(n - 1); // Multiplica n^n pelo hiperfatorial de (n-1)
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Hiperfatorial de %d é: %lld\n", n, hiperfatorial(n));
    } else {
        printf("Número inválido! Digite um número positivo.\n");
    }

    return 0;
}
 */