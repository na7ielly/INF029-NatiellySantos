/*
QUESTÃO 02:
Crie um programa que tenha uma função subtrai e a função main. A função main deve 
ler três valores, enviar para a função subtrair. A função subtrai deve realizar a 
subtração dos três valores (primeiro menos o segundo menos o terceiro) e retornar 
o valor. A função main deve imprimir o resultado da subtração.
*/

#include "prototipos.h"

int main(){

    int x, y, z;

    printf("Informe o primeiro número que deseja subtrair: ");
    scanf("%d", &x);
    printf("Informe o segundo número que deseja subtrair: ");
    scanf("%d", &y);
    printf("Informe o terceiro número que deseja subtrair: ");
    scanf("%d", &z);

    int resultado = subtrair(x, y, z);

    printf("\nResultado: %d\n", resultado);
}

int subtrair(int a, int b, int c){
    
    int resultado;
    resultado = a - b - c;
    return resultado;
}