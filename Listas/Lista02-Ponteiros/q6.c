/*
QUESTÃO 06:
Faça um programa que monte uma lista duplamente encadeada dinâmica com valores inteiros informados 
pelo usuário. Deve ter uma função insere, que recebe um ponteiro para o primeiro elemento da lista e 
insere o valor na lista já ordenado.
*/

#include "funcoesGerais.h"

// Estrutura do nó
typedef struct No {
    int valor;
    struct No *anterior;
    struct No *proximo;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para inserir valores de forma ordenada na lista
void inserirOrdenado(No **inicio, int valor) {
    No *novoNo = criarNo(valor);

    // Caso a lista esteja vazia
    if (*inicio == NULL) {
        *inicio = novoNo;
        return;
    }

    No *atual = *inicio;

    // Inserção no início (antes do primeiro elemento)
    if (valor <= atual->valor) {
        novoNo->proximo = atual;
        atual->anterior = novoNo;
        *inicio = novoNo;
        return;
    }

    // Procurar posição correta para inserir
    while (atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }

    // Inserção no meio ou no final
    novoNo->proximo = atual->proximo;
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novoNo;
    }
    atual->proximo = novoNo;
    novoNo->anterior = atual;
}

// Função para imprimir a lista na ordem direta
void imprimirListaDireta(No *inicio) {
    printf("Lista em ordem direta: ");
    No *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para imprimir a lista na ordem inversa
void imprimirListaInversa(No *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    // Ir até o último elemento
    No *atual = inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    // Imprimir de trás para frente
    printf("Lista em ordem inversa: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->anterior;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    No *lista = NULL;
    int valor;

    printf("Digite valores inteiros para inserir na lista (digite -1 para encerrar):\n");
    while (1) {
        printf("Informe um valor: ");
        scanf("%d", &valor);
        if (valor == -1) break; // Sair do loop ao digitar -1
        inserirOrdenado(&lista, valor);
    }

    // Exibir a lista em ordem direta e inversa
    imprimirListaDireta(lista);
    imprimirListaInversa(lista);

    // Liberar memória da lista
    while (lista != NULL) {
        No *temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    return 0;
}