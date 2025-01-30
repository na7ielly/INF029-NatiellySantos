/*1) (Valor 1.5) )A função processaDados possui três variáveis locais inteiras de nomes val_a, val_b e 
val_c. Você precisa na função main ter acesso aos valores dessas três variáveis. Complemente os três 
quadros abaixo utilizando recursos diferentes para que seja possível acessar os dados na função main.
Você não precisa fazer includes nem colocar o cabeçalho da função no topo do arquivo.*/

#include <stdio.h>
#include <stdlib.h>

// Primeira forma: Utilizando struct

typedef struct {
    int val_A;
    int val_B;
    int val_C;
} Estrutura;

Estrutura processaDados1(){
    int val_a = 1, val_b = 2, val_c = 3;

    Estrutura aux;

    aux.val_A = val_a;
    aux.val_B = val_b;
    aux.val_C = val_c;

    return aux;
}

/*int main(){
    Estrutura dados = processaDados();

    printf("Valores: %d %d %d\n", dados.val_A, dados.val_B, dados.val_C);

    return 0;
}*/

// Segunda forma: Utilizando ponteiros

void processaDados2(int *val_A, int *val_B, int *val_C){
 
    int val_a = 1, val_b = 2, val_c = 3;

    *val_A = val_a;
    *val_B = val_b;
    *val_C = val_c;
}

/*int main(){
    int val_A, val_B, val_C;

    processaDados(&val_A, &val_B, &val_C);

    printf("Valores: %d %d %d\n", val_A, val_B, val_C);

    return 0;
}*/

// Terceira forma: Utilizando vetor

void processaDados3(int *array){
 
    int val_a = 1, val_b = 2, val_c = 3;

    array[0] = val_a;
    array[1] = val_b;
    array[2] = val_c;
}

/*int main(){

    int array[3];

    processaDados(array);

    printf("Valores: %d %d %d\n", array[0], array[1], array[2]);

    return 0;
}*/

/*2.1) (Valor 5.0) faça uma função que cria uma lista encadeada ordenada (Nome da função: 
listaOrdenada), a partir dos valores existentes nos vetores que atendem a seguinte regra: só deve ser 
incluído na lista se o elemento de um vetor for maior ou igual a média de todos os elementos deste 
mesmo vetor.*/

typedef struct no{
    int valor;
    struct no *prox;
}No;

typedef struct{
    int *valores;
    int tamanho;
    int ocupados;
}EstruturaAuxiliar;

// Função para calcular a média de um vetor
float calcularMedia(int *vetor, int tamanho) {
    if (tamanho == 0) return 0; // Evita divisão por zero
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return (float)soma / tamanho;
}

// Função para criar a lista encadeada ordenada
No* listaOrdenada(EstruturaAuxiliar *vetorPrincipal[], int TAM) {
    No *inicio = NULL; // Cabeçote da lista encadeada

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->ocupados > 0) {
            int *vetor = vetorPrincipal[i]->valores;
            int tamanho = vetorPrincipal[i]->ocupados;
            float media = calcularMedia(vetor, tamanho);

            // Inserir elementos que são maiores ou iguais à média
            for (int j = 0; j < tamanho; j++) {
                if (vetor[j] >= media) {
                    // Criar um novo nó
                    No *novoNo = (No *)malloc(sizeof(No));
                    novoNo->valor = vetor[j];
                    novoNo->prox = NULL;

                    // Inserir o nó na lista de forma ordenada
                    if (inicio == NULL || inicio->valor >= novoNo->valor) {
                        novoNo->prox = inicio;
                        inicio = novoNo;
                    } else {
                        No *atual = inicio;
                        while (atual->prox != NULL && atual->prox->valor < novoNo->valor) {
                            atual = atual->prox;
                        }
                        novoNo->prox = atual->prox;
                        atual->prox = novoNo;
                    }
                }
            }
        }
    }

    return inicio;
}

// Função para liberar a memória da lista encadeada
void destroiLista(No **inicio) {
    No *atual = *inicio;
    No *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL; // Garante que o ponteiro de início seja nulo após a destruição
}