/*
QUESTÃO 07:
Crie um programa que tenha uma função para ler 3 Palavras. Essa função deve ler
três palavras do usuário e retornar as três palavras. A função main deve imprimir
essas três palavras.
*/

#include <stdio.h>
#include "prototipos.h"

#define MAX_LETRAS 20

int main() {
    char palavras[3][MAX_LETRAS];  // Vetor de strings para armazenar 3 palavras

    lerTresPalavras(palavras);

    printf("As três palavras são:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", palavras[i]);
    }

    return 0;
}

void lerTresPalavras(char palavras[][MAX_LETRAS]) {
    printf("Digite 3 palavras:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d° palavra: ", i + 1);
        scanf("%s", palavras[i]);  // Lê a palavra e armazena na posição do vetor
    }
}