/*
QUESTÃO 06:
Crie um programa que tenha uma função ler 3 Letras. Essa função deve ler três
letras do usuário e retornar as três letras. A função main deve imprimir essas três letras.
*/

#include <stdio.h>
#include "prototipos.h"

int main(){
    char letras[3];

    // Chama a função para ler as 3 letras
    lerTresLetras(letras);

    // Imprime as 3 letras lidas
    printf("As três letras são:\n");
    for (int i = 0; i < 3; i++) {
        printf("%c ", letras[i]);
    }
    return 0;
}

void lerTresLetras(char letras[]) {
    printf("Digite 3 letras:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d° letra: ", i + 1);
        scanf(" %c", &letras[i]);
    }
}