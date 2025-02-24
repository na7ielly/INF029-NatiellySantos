#include <stdio.h>

// 3) Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321

int inverter (int n){
    
    static int invertido = 0;
    static int negativo = 1;

    if (n < 0){
        negativo = -1;
        return inverter(-n);
    }

    if (n == 0){
        int resultado = invertido * negativo;
        invertido = 0;
        negativo = 1;
        return resultado;
    }

    invertido = invertido * 10 + n % 10;
    return inverter(n / 10);
}