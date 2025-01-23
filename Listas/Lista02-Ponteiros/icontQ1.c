/*1) Apresente a implementação de duas filas circulares em um vetor de 20 posições, de 0 a
19. A primeira fila deve utilizar as posições de 0 a 9, a segunda fila deve utilizar as
posições de 10 a 19. Cada fila circular deve ter as operações incluir na lista, pesquisar
na lista e excluir da lista um valor pesquisado.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define TOTAL 20

typedef struct {
    int itens[TAM];   // Armazena os elementos da fila
    int inicio, fim;  // Índices de início e fim da fila
    int tamanho;      // Quantidade de elementos na fila
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->tamanho == TAM;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

// Insere um valor na fila
void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível inserir %d.\n", valor);
        return;
    }
    f->fim = (f->fim + 1) % TAM;  // Incrementa o índice do fim de forma circular
    f->itens[f->fim] = valor;     // Adiciona o valor no final da fila
    f->tamanho++;
}

// Remove um valor da fila
int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Nada para remover.\n");
        return -1;
    }
    int valor = f->itens[f->inicio];     // Pega o valor no início
    f->inicio = (f->inicio + 1) % TAM;  // Incrementa o índice do início de forma circular
    f->tamanho--;
    return valor;
}

// Busca um valor na fila
int buscar(Fila *f, int valor) {
    for (int i = 0, idx = f->inicio; i < f->tamanho; i++, idx = (idx + 1) % TAM) {
        if (f->itens[idx] == valor) {
            return idx;  // Retorna a posição do valor
        }
    }
    return -1;  // Valor não encontrado
}

// Exibe os elementos da fila
void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0, idx = f->inicio; i < f->tamanho; i++, idx = (idx + 1) % TAM) {
        printf("%d ", f->itens[idx]);
    }
    printf("\n");
}

// Função principal
int main() {
    Fila fila1, fila2;
    inicializarFila(&fila1);
    inicializarFila(&fila2);

    printf("Operações na Fila 1 (posições 0-9):\n");
    enfileirar(&fila1, 10);
    enfileirar(&fila1, 20);
    enfileirar(&fila1, 30);
    exibirFila(&fila1);
    printf("Removendo: %d\n", desenfileirar(&fila1));
    exibirFila(&fila1);
    printf("Buscando 20: posição %d\n", buscar(&fila1, 20));

    printf("\nOperações na Fila 2 (posições 10-19):\n");
    enfileirar(&fila2, 40);
    enfileirar(&fila2, 50);
    exibirFila(&fila2);
    printf("Removendo: %d\n", desenfileirar(&fila2));
    exibirFila(&fila2);

    return 0;
}
