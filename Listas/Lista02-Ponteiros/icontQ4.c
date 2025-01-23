/*4) Altere os algoritmos propostos na questão 4 para que os mesmos mantenham a lista
ordenada. A busca deve ser otimizada (ex: se busca o elemento 10, a busca deve
terminar se o elemento lido for superior a 10, mesmo que a lista não tenha sido
totalmente percorrida).*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista simplesmente encadeada
typedef struct No {
    int valor;
    struct No *proximo;
} No;

//Essa função insere um nó de forma que a lista permaneça ordenada.
void inserirOrdenado(No **inicio, int valor) {
    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    // Caso lista vazia ou valor menor que o primeiro nó
    if (*inicio == NULL || (*inicio)->valor >= valor) {
        novoNo->proximo = *inicio;
        *inicio = novoNo;
        return;
    }

    // Procurar a posição correta
    No *atual = *inicio;
    while (atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }

    // Inserir o novo nó
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
}

//A busca para de percorrer a lista quando encontra um valor maior que o procurado.
No* buscarOtimizado(No *inicio, int valor) {
    while (inicio != NULL) {
        if (inicio->valor == valor) {
            return inicio; // Valor encontrado
        }
        if (inicio->valor > valor) {
            break; // Parar se o valor atual for maior que o procurado
        }
        inicio = inicio->proximo;
    }
    return NULL; // Valor não encontrado
}

//Essa função remove um nó de forma que a lista permaneça ordenada.
void removerNo(No **inicio, int valor) {
    No *atual = *inicio, *anterior = NULL;

    // Caso a lista esteja vazia
    if (*inicio == NULL) {
        printf("Lista vazia. Nada para remover.\n");
        return;
    }

    // Caso o valor esteja no primeiro nó
    if ((*inicio)->valor == valor) {
        No *temp = *inicio;
        *inicio = (*inicio)->proximo;
        free(temp);
        return;
    }

    // Procurar o nó a ser removido
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Valor não encontrado
    if (atual == NULL) {
        printf("Valor %d não encontrado.\n", valor);
        return;
    }

    // Remover o nó
    anterior->proximo = atual->proximo;
    free(atual);
}

//Essa função imprime a lista.
void imprimirLista(No *inicio) {
    while (inicio != NULL) {
        printf("%d -> ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("NULL\n");
}
