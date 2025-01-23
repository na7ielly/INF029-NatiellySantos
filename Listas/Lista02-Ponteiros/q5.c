/*
QUESTÃO 05:
Faça um programa que monte uma lista encadeada dinâmica com valores inteiros informados pelo usuário. 
Deve ter uma função insere, que recebe um ponteiro para o primeiro elemento da lista e insere o valor 
na lista já ordenado.
*/

#include "funcoesGerais.h"

typedef struct no{
    int conteudo;
    struct no *proximo;
}No;

//Procedimento: inserir no início da fila.
void inserirNoInicio (No **lista, int conteudoInserido){

    No *novoNo;
    novoNo = (No *)malloc(sizeof(No));

    if (novoNo){
        novoNo->conteudo = conteudoInserido;
        novoNo->proximo = *lista;
        *lista = novoNo;
    }else{
        printf("Sem memória disponível!");
    }
}

//Procedimento: inserir no fim da lista.
void inserirNoFim (No **lista, int conteudoInserido){

    No *novoNo = malloc(sizeof(No));
    No *aux = malloc(sizeof(No));

    if(novoNo){

        novoNo->conteudo = conteudoInserido;
        novoNo->proximo = NULL;

        //Considerando se o nó é o primeiro 
        if(*lista == NULL){
            *lista = novoNo;
        }else{
            aux = *lista;
            while(aux->proximo != NULL){
            aux = aux->proximo;
            }
            aux->proximo = novoNo;
        }

    } else {
        printf("Sem memória disponível!");
    }
}

void inserirNoMeio(No **lista, int conteudoInserido, int anterior) {
    // Alocar memória para o novo nó
    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->conteudo = conteudoInserido;
    novoNo->proximo = NULL;

    // Verificar se a lista está vazia
    if (*lista == NULL) {
        printf("A lista está vazia. Não foi possível encontrar o nó anterior.\n");
        free(novoNo);
        return;
    }

    // Procurar o nó com o conteúdo igual a 'anterior'
    No *atual = *lista;
    while (atual != NULL && atual->conteudo != anterior) {
        atual = atual->proximo;
    }

    // Verificar se o nó 'anterior' foi encontrado
    if (atual == NULL) {
        printf("O nó com valor %d não foi encontrado.\n", anterior);
        free(novoNo);
        return;
    }

    // Inserir o novo nó após o nó encontrado
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
}

//Procedimento: inserir ordenado na lista.
void inserirOrdenado(No **lista, int conteudoInserido) {
    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->conteudo = conteudoInserido;
    novoNo->proximo = NULL;

    // Caso a lista esteja vazia ou o novo valor seja menor que o primeiro nó
    if (*lista == NULL || (*lista)->conteudo >= conteudoInserido) {
        novoNo->proximo = *lista;
        *lista = novoNo;
        return;
    }

    // Percorrer a lista até encontrar a posição correta
    No *atual = *lista;
    while (atual->proximo != NULL && atual->proximo->conteudo < conteudoInserido) {
        atual = atual->proximo;
    }

    // Inserir o novo nó na posição encontrada
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
}

// Função para imprimir a lista
void imprimirLista(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->conteudo);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função principal para teste
int main() {
    No *lista = NULL;

    // Inserir elementos ordenados
    inserirOrdenado(&lista, 20);
    inserirOrdenado(&lista, 10);
    inserirOrdenado(&lista, 30);
    inserirOrdenado(&lista, 25);
    inserirOrdenado(&lista, 15);

    // Imprimir a lista
    printf("Lista ordenada:\n");
    imprimirLista(lista);

    // Liberar memória alocada
    while (lista != NULL) {
        No *temp = lista;
        lista = lista->proximo;
        free(temp);
    }

    return 0;
}