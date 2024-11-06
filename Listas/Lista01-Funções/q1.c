/*
QUESTÃO 01:
Crie um programa que tenha uma função soma e a função main. A função main deve ler 
dois valores, enviar para a função soma. A função soma deve realizar a soma e retornar 
o valor. A função main deve imprimir o resultado da soma.
*/

#include <stdio.h>
#include "prototipos.h" // Onde está armazenado os protótipos para o compilador reconhecer a função ao executar o main

int main(){

    int x, y;

    printf("Informe o primeiro número que deseja somar: ");
    scanf("%d", &x);
    printf("Informe o segundo número que deseja somar: ");
    scanf("%d", &y);

    int resultado = somar(x, y);

    printf("\nResultado: %d\n", resultado);
}

int somar(int x, int y){
    
    int resultado;
    resultado = x + y;
    return resultado;
}