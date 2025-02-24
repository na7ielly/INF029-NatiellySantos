#include <stdio.h>

// 9) Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a N.

int somatorio(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + somatorio(n - 1);
    }
}