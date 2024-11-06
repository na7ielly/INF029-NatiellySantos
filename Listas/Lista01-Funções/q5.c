/*
QUESTÃO 05:
Crie um programa que tenha uma função ler 4 Números. Essa função deve ler
quatro números do usuário e retornar os quatro números. A função main deve
imprimir esses quatro números. Utilize struct para fazer o retorno.
*/

#include <stdio.h>
#include "prototipos.h"

typedef struct Numeros {
    int num1;
    int num2;
    int num3;
    int num4;
} Numeros;

int main() {
    struct Numeros numeros = lerQuatroNumeros();

    printf("Os quatro números são: %d, %d, %d, %d\n", numeros.num1, numeros.num2, numeros.num3, numeros.num4);
    
    return 0;
}

struct Numeros lerQuatroNumeros() {
    struct Numeros numero;

    printf("Digite quatro números:\n");
    printf("Número 1: ");
    scanf("%d", &numero.num1);
    printf("Número 2: ");
    scanf("%d", &numero.num2);
    printf("Número 3: ");
    scanf("%d", &numero.num3);
    printf("Número 4: ");
    scanf("%d", &numero.num4);
    
    return numero; // Retorna a struct com os 4 números
}