#include <stdio.h>

// 6) Crie um programa em C, que contenha uma função recursiva que receba dois inteiros positivos k e n e calcule k^n. 
// Utilize apenas multiplicações. O programa principal deve solicitar ao usuário os valores de k e n e imprimir o 
// resultado da chamada da função.

int potencia(int k, int n) {
    if (n == 0) {
        return 1;
    }
    return k * potencia(k, n - 1);
}
