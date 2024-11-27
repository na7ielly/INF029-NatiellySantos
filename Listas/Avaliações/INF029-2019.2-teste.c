/*
Faça uma programa que defina um vetor de 10 posições no main(). Deve existir (pelo menos) três funções, conforme
determinado a seguir:
I) preencherVetor(…), que interage com o usuário para preencher os dados no vetor;
II) descobreMaiorMenor(…), que identifica o maior e menor valor existente no vetor;
III) imprimeMaiorMenor(…) que imprime os valores maior e menor identificados na função anterior.
Todas as três funções devem ser chamadas apenas a partir do main().
*/

#include <stdio.h>

#define TAM 10

void preencherVetor(int vetor[])
{
    int num;
    printf("Digite os 10 números para adicionar ao vetor:\n");

    for(int i = 0; i < TAM; i++){
        printf("N° %d: ", i + 1);
        scanf("%d", &num);
        vetor[i] = num;
    }
}

typedef struct
{
    int elementos[TAM];
    int maior;
    int menor;
} VetorNumeros;

VetorNumeros descobreMaiorMenor (VetorNumeros lista){

    //Inicializando com o primeiro elemento
    lista.maior = lista.elementos[0];
    lista.menor = lista.elementos[0];

    for(int i = 0; i < TAM; i++)
    {
        if(lista.elementos[i] > lista.maior)
        {
            lista.maior = lista.elementos[i];
        }
        if(lista.elementos[i] < lista.menor)
        {
            lista.menor = lista.elementos[i];
        }
    }
    return lista;
}

void imprimeMaiorMenor (VetorNumeros elemento){
    printf("\nO maior numero é: %d\n", elemento.maior);
    printf("O menor numero é: %d\n", elemento.menor);
}

int main(){
    VetorNumeros numeros;

    preencherVetor(numeros.elementos);
    numeros = descobreMaiorMenor(numeros);
    imprimeMaiorMenor(numeros);

    return 0;
}


