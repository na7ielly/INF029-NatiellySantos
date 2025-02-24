#include <stdio.h>

// 1) Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.

int fatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}
