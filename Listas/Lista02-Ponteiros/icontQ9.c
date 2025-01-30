/*9) Implemente 2 filas, uma de menor e uma de maior prioridade. Ao inserir um valor deve
ser perguntado qual fila utilizar. Ao pedir a retirada de um valor, retirar da fila de maior
prioridade, caso esta esteja vazia, então deve-se utilizar a de menor prioridade.*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

// Estrutura para representar uma fila
typedef struct {
    int dados[TAMANHO_MAX];
    int inicio;
    int fim;
} Fila;

// Função para inicializar uma fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *f) {
    return f->fim < f->inicio;
}

// Função para inserir um valor na fila
void inserir(Fila *f, int valor) {
    if (f->fim < TAMANHO_MAX - 1) {
        f->dados[++(f->fim)] = valor;
    } else {
        printf("Fila cheia! Não é possível inserir.\n");
    }
}

// Função para remover um valor da fila
int remover(Fila *f) {
    if (!filaVazia(f)) {
        return f->dados[(f->inicio)++];
    } else {
        printf("Fila vazia! Não é possível remover.\n");
        return -1; // Retorno inválido para indicar que a fila está vazia
    }
}

// Função para mostrar o estado das filas
void mostrarFilas(Fila *maior, Fila *menor) {
    printf("Fila de maior prioridade: ");
    for (int i = maior->inicio; i <= maior->fim; i++) {
        printf("%d ", maior->dados[i]);
    }
    printf("\n");

    printf("Fila de menor prioridade: ");
    for (int i = menor->inicio; i <= menor->fim; i++) {
        printf("%d ", menor->dados[i]);
    }
    printf("\n");
}

int main() {
    Fila maiorPrioridade, menorPrioridade;
    inicializarFila(&maiorPrioridade);
    inicializarFila(&menorPrioridade);

    int opcao, valor;
    char prioridade;

    while (1) {
        printf("\n1. Inserir valor\n");
        printf("2. Remover valor\n");
        printf("3. Mostrar filas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a prioridade ('M' para maior, 'm' para menor): ");
                scanf(" %c", &prioridade); // Espaço antes do %c para evitar problemas com o buffer

                if (prioridade == 'M' || prioridade == 'm') {
                    if (prioridade == 'M') {
                        inserir(&maiorPrioridade, valor);
                    } else {
                        inserir(&menorPrioridade, valor);
                    }
                } else {
                    printf("Prioridade inválida! Use 'M' ou 'm'.\n");
                }
                break;

            case 2:
                if (!filaVazia(&maiorPrioridade)) {
                    valor = remover(&maiorPrioridade);
                    printf("Valor removido da fila de maior prioridade: %d\n", valor);
                } else if (!filaVazia(&menorPrioridade)) {
                    valor = remover(&menorPrioridade);
                    printf("Valor removido da fila de menor prioridade: %d\n", valor);
                } else {
                    printf("Ambas as filas estão vazias!\n");
                }
                break;

            case 3:
                mostrarFilas(&maiorPrioridade, &menorPrioridade);
                break;

            case 4:
                printf("Saindo...\n");
                exit(0);

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}