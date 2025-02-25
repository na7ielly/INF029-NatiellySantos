#include <stdio.h>

/* 38) Escreva uma função recursiva que calcule a soma de dois números naturais, 
através de incrementos sucessivos (Ex.: 3 + 2 = ++(++3)).  */

int somaRecursiva(int a, int b) {
    if (b == 0) {
        return a; // Caso base: se b for 0, retorna a
    }
    return somaRecursiva(a + 1, b - 1); // Incrementa a e decrementa b
}

int main() {
    int x, y;

    printf("Digite dois números naturais: ");
    scanf("%d %d", &x, &y);

    if (x < 0 || y < 0) {
        printf("Erro! Os números devem ser naturais (maiores ou iguais a zero).\n");
    } else {
        printf("A soma de %d + %d é: %d\n", x, y, somaRecursiva(x, y));
    }

    return 0;
}
