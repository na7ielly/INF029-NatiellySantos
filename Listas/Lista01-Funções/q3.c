/*
QUESTÃO 03:
Faça um programa que tenha uma função que recebe um número inteiro e retorne
o fatorial deste número. Esta função deve ainda verificar se é possível calcular
o fatorial, se não for, ela deve de alguma forma retornar para a main que deu algum
erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, ou
se não é possível calcular o fatorial.
*/

#include <stdio.h>
#include "prototipos.h"

int main(){
    int x;

    printf("Informe o número: ");
    scanf("%d", &x);

    int resultado = fatorial(x);

    if (resultado == 0){
        printf ("Não é possível calcular o fatorial.");
    }
    else{
        printf ("Resultado: %d\n", resultado);
    }
}

int fatorial (int num){
    int resultado = 1;
    int i;

    if (num < 0){
        return 0;
    }
    else if (num == 0 || num == 1){
        resultado = 1;
    }
    else{
        for (i = num; i > 1; i--){
            resultado *= i;
        }
    }
    return resultado;
}