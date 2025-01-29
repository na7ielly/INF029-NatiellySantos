#include <stdio.h>
#include <stdlib.h>

/*1)(Valor 0.5) Defina a estrutura (Nome: Elemento) para criar os elementos da lista encadeada. A
estrutura deve conter no mínimo o valor do elemento e a quantidade de vezes que ele aparece.*/

// Definindo a estrutura Elemento
struct Elemento {
    int valor;               // Valor do elemento
    int quantidade;          // Quantidade de vezes que o valor aparece
    struct Elemento* proximo; // Ponteiro para o próximo elemento
};

/*2) (Valor 5.0) faça uma função que cria uma lista encadeada ordenada sem números repetidos a
partir dos valores existentes nos vetores e retorne um ponteiro para o primeiro elemento da lista.
(Nome da função: listaOrdenada). Ao encontrar um número repetido deve ser incrementado no
elemento já existente.*/

// Função para criar uma lista encadeada ordenada sem repetições
struct Elemento* listaOrdenada(int vetor1[], int tamanho1, int vetor2[], int tamanho2) {
    struct Elemento* cabeca = NULL; // Cabeça da lista (inicialmente vazia)

    // Percorrer o primeiro vetor
    for (int i = 0; i < tamanho1; i++) {
        int valor = vetor1[i];

        // Verificar se o valor já existe na lista
        struct Elemento* atual = cabeca;
        struct Elemento* anterior = NULL;

        while (atual != NULL && atual->valor < valor) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual != NULL && atual->valor == valor) {
            // Se o valor já existe, incrementa a quantidade
            atual->quantidade++;
        } else {
            // Se o valor não existe, cria um novo elemento
            struct Elemento* novo = (struct Elemento*)malloc(sizeof(struct Elemento));
            novo->valor = valor;
            novo->quantidade = 1;
            novo->proximo = atual;

            if (anterior == NULL) {
                // Inserir no início da lista
                cabeca = novo;
            } else {
                // Inserir no meio ou final da lista
                anterior->proximo = novo;
            }
        }
    }

    // Percorrer o segundo vetor (mesmo processo)
    for (int i = 0; i < tamanho2; i++) {
        int valor = vetor2[i];

        struct Elemento* atual = cabeca;
        struct Elemento* anterior = NULL;

        while (atual != NULL && atual->valor < valor) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual != NULL && atual->valor == valor) {
            atual->quantidade++;
        } else {
            struct Elemento* novo = (struct Elemento*)malloc(sizeof(struct Elemento));
            novo->valor = valor;
            novo->quantidade = 1;
            novo->proximo = atual;

            if (anterior == NULL) {
                cabeca = novo;
            } else {
                anterior->proximo = novo;
            }
        }
    }

    return cabeca; // Retorna o ponteiro para o primeiro elemento da lista
}

/*3) (Valor 1.0) Faça uma função que imprima a lista encadeada. (Nome da função: imprimeLista)*/

// Função para imprimir a lista encadeada
void imprimeLista(struct Elemento* cabeca) {
    struct Elemento* atual = cabeca;

    while (atual != NULL) {
        printf("Valor: %d, Quantidade: %d\n", atual->valor, atual->quantidade);
        atual = atual->proximo;
    }
}

/*4) (Valor 1.5) Faça uma função para liberar os espaços de memória criados. (Nome da função:
destroiLista)*/

// Função para liberar a memória da lista
void destroiLista(struct Elemento* cabeca) {
    struct Elemento* atual = cabeca;

    while (atual != NULL) {
        struct Elemento* proximo = atual->proximo; // Salva o próximo elemento
        free(atual); // Libera o elemento atual
        atual = proximo; // Move para o próximo elemento
    }
}