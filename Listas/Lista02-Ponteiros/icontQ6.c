/*6) Suponha que temos duas pilhas ordenadas de forma crescente, P1 e P2. Desempilhe os
elementos destas pilhas e empilhe em P3, de modo que os elementos fiquem ordenados
de forma decrescente.
Exemplo: P1 = {1, 4, 8} e P2 = {2, 6, 7, 9}, onde o topo de P1 é 1 e o topo de P2 é 2.
P3 será {9, 8, 7, 6, 4, 2, 1}*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Estrutura da Pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Inicializa uma pilha
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Empilha um elemento
void push(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

// Desempilha um elemento
int pop(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    return p->itens[(p->topo)--];
}

// Consulta o elemento do topo
int topo(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    return p->itens[p->topo];
}

// Função para mesclar pilhas em ordem decrescente diretamente
void mergePilhas(Pilha *p1, Pilha *p2, Pilha *p3) {
    while (!pilhaVazia(p1) || !pilhaVazia(p2)) {
        if (!pilhaVazia(p1) && !pilhaVazia(p2)) {
            if (topo(p1) > topo(p2)) {
                push(p3, pop(p1));
            } else {
                push(p3, pop(p2));
            }
        } else if (!pilhaVazia(p1)) {
            push(p3, pop(p1));
        } else {
            push(p3, pop(p2));
        }
    }
}

// Função para exibir uma pilha
void exibePilha(Pilha *p) {
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

// Programa principal
int main() {
    Pilha p1, p2, p3;

    // Inicializa as pilhas
    inicializaPilha(&p1);
    inicializaPilha(&p2);
    inicializaPilha(&p3);

    // Preenche as pilhas P1 e P2 (crescente)
    push(&p1, 8);
    push(&p1, 4);
    push(&p1, 1);

    push(&p2, 9);
    push(&p2, 7);
    push(&p2, 6);
    push(&p2, 2);

    // Exibe as pilhas iniciais
    printf("P1 inicial: ");
    exibePilha(&p1);

    printf("P2 inicial: ");
    exibePilha(&p2);

    // Mescla as pilhas em P3
    mergePilhas(&p1, &p2, &p3);

    // Exibe P3
    printf("P3 (decrescente): ");
    exibePilha(&p3);

    return 0;
}
