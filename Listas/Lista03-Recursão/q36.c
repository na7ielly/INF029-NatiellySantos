#include <stdio.h>

/* 36) Um palíndromo é uma string que é lida da mesma maneira da esquerda para a direita e da direita para a esquerda. 
Alguns exemplos de palíndromo são radar e a bola da loba (se os espaços forem ignorados) Escreva uma função recursiva 
que retorna 1 se a string armazenada no array for um palíndromo e 0, caso contrário. O método deve ignorar espaços e pontuação 
na string.  */

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int ehValido(char c) {
    return isalnum(c); // Retorna 1 se for alfanumérico, 0 caso contrário
}


int ehPalindromo(char str[], int esquerda, int direita) {
    // Caso base: quando os índices se cruzam ou são iguais
    if (esquerda >= direita) {
        return 1; // É um palíndromo
    }

    // Ignorar caracteres não alfanuméricos
    if (!ehValido(str[esquerda])) {
        return ehPalindromo(str, esquerda + 1, direita);
    }
    if (!ehValido(str[direita])) {
        return ehPalindromo(str, esquerda, direita - 1);
    }

    // Comparar caracteres (ignorando maiúsculas/minúsculas)
    if (tolower(str[esquerda]) != tolower(str[direita])) {
        return 0; // Não é um palíndromo
    }

    // Chamada recursiva para os próximos caracteres
    return ehPalindromo(str, esquerda + 1, direita - 1);
}

int main() {
    char str[1000];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover o '\n' da entrada
    str[strcspn(str, "\n")] = '\0';

    if (ehPalindromo(str, 0, strlen(str) - 1)) {
        printf("A string é um palíndromo!\n");
    } else {
        printf("A string NÃO é um palíndromo!\n");
    }

    return 0;
}
