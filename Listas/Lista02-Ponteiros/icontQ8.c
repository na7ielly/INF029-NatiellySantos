/*8) Implemente duas pilhas em um único vetor de 100 posições. Da posição 0 até a posição
49 é a pilha A, da posição 50 até a posição 99 é a pilha B. Apresente as operações de
push e pop para ambas as pilhas.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define METADE MAX / 2

// Estrutura para gerenciar as pilhas
typedef struct {
    int itens[MAX]; // Vetor que armazena os elementos de ambas as pilhas
    int topoA;      // Topo da pilha A
    int topoB;      // Topo da pilha B
} DuasPilhas;

// Inicializa as pilhas
void inicializaDuasPilhas(DuasPilhas *p) {
    p->topoA = -1;                   // Pilha A começa em -1 (vazia)
    p->topoB = MAX;                  // Pilha B começa no limite superior (vazia)
}

// Função para verificar se a pilha A está vazia
int pilhaAVazia(DuasPilhas *p) {
    return p->topoA == -1;
}

// Função para verificar se a pilha B está vazia
int pilhaBVazia(DuasPilhas *p) {
    return p->topoB == MAX;
}

// Função para verificar se as pilhas estão cheias
int pilhasCheias(DuasPilhas *p) {
    return p->topoA + 1 == p->topoB; // As pilhas compartilham espaço, topoA + 1 == topoB indica falta de espaço
}

// Push na pilha A
void pushA(DuasPilhas *p, int valor) {
    if (pilhasCheias(p)) {
        printf("Erro: Pilhas cheias!\n");
        return;
    }
    p->itens[++(p->topoA)] = valor; // Insere o elemento na próxima posição disponível da pilha A
}

// Push na pilha B
void pushB(DuasPilhas *p, int valor) {
    if (pilhasCheias(p)) {
        printf("Erro: Pilhas cheias!\n");
        return;
    }
    p->itens[--(p->topoB)] = valor; // Insere o elemento na próxima posição disponível da pilha B
}

// Pop na pilha A
int popA(DuasPilhas *p) {
    if (pilhaAVazia(p)) {
        printf("Erro: Pilha A está vazia!\n");
        exit(1);
    }
    return p->itens[(p->topoA)--]; // Remove o elemento do topo da pilha A
}

// Pop na pilha B
int popB(DuasPilhas *p) {
    if (pilhaBVazia(p)) {
        printf("Erro: Pilha B está vazia!\n");
        exit(1);
    }
    return p->itens[(p->topoB)++]; // Remove o elemento do topo da pilha B
}

// Exibe os elementos da pilha A
void exibePilhaA(DuasPilhas *p) {
    printf("Pilha A: ");
    for (int i = 0; i <= p->topoA; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

// Exibe os elementos da pilha B
void exibePilhaB(DuasPilhas *p) {
    printf("Pilha B: ");
    for (int i = MAX - 1; i >= p->topoB; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    DuasPilhas pilhas;

    // Inicializa as pilhas
    inicializaDuasPilhas(&pilhas);

    // Operações na pilha A
    pushA(&pilhas, 10);
    pushA(&pilhas, 20);
    pushA(&pilhas, 30);
    exibePilhaA(&pilhas);

    // Operações na pilha B
    pushB(&pilhas, 100);
    pushB(&pilhas, 200);
    pushB(&pilhas, 300);
    exibePilhaB(&pilhas);

    // Remover elementos das pilhas
    printf("Pop A: %d\n", popA(&pilhas));
    printf("Pop B: %d\n", popB(&pilhas));

    // Exibe as pilhas após remoção
    exibePilhaA(&pilhas);
    exibePilhaB(&pilhas);

    return 0;
}
