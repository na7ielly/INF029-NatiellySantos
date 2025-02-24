#include <stdio.h>

// 5) Crie uma função recursiva que receba um número inteiro positivo N e calcule o
// somatório dos números de 1 a N.

int somatorio(int n) {
    if (n == 1) {
        return 1;
    }
    return n + somatorio(n - 1);
}
