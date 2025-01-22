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
printf("Sem memória disponível");
}

}


