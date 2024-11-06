/*
QUESTÃO 04:
Crie um programa que tenha uma função ler 3 Números. Essa função deve ler três
números do usuário e retornar os três números. A função main deve imprimir esses 
três números. Utilize vetor para fazer o retorno.
*/

#include "prototipos.h"

int main(){
    int numeros[3];

    lerTresNumeros(numeros);

    printf("Os três números são:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", numeros[i]);
    }
    return 0;
}

void lerTresNumeros (int numeros[]){
    
    printf("Digite os três números:\n");
    for (int i = 0; i < 3; i++){
        printf("%d° número: ", i + 1);
        scanf ("%d", &numeros[i]);
    }
}