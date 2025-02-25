#include <stdio.h>

/* 18) O superfatorial de um número N é definida pelo produto dos N primeiros fatoriais de N. 
Assim, o superfatorial de 4 é sf(4) = 1! * 2! * 3! * 4! = 288 Faça uma função recursiva que receba 
um número inteiro positivo N e retorne o superfatorial desse número. */


long long fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base: 0! = 1 e 1! = 1
    }
    return n * fatorial(n - 1); // Chamada recursiva para calcular o fatorial
}


long long superfatorial(int n) {
    if (n == 1) {
        return 1; // Caso base: sf(1) = 1! = 1
    }
    return fatorial(n) * superfatorial(n - 1); // Multiplica o fatorial de n pelo superfatorial de n-1
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Superfatorial de %d é: %lld\n", n, superfatorial(n));
    } else {
        printf("Número inválido! Digite um número positivo.\n");
    }

    return 0;
}