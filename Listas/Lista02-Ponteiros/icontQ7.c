/*7) Suponha que temos duas pilhas ordenadas de forma crescente, P1 e P2. Desempilhe os
elementos destas pilhas e empilhe em P3, de modo que os elementos fiquem ordenados
de forma decrescente. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

int pop(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    return p->itens[(p->topo)--];
}

int topo(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    return p->itens[p->topo];
}

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

void exibePilha(Pilha *p) {
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Pilha p1, p2, p3;

    inicializaPilha(&p1);
    inicializaPilha(&p2);
    inicializaPilha(&p3);

    push(&p1, 8);
    push(&p1, 4);
    push(&p1, 1);

    push(&p2, 9);
    push(&p2, 7);
    push(&p2, 6);
    push(&p2, 2);

    printf("P1 inicial: ");
    exibePilha(&p1);

    printf("P2 inicial: ");
    exibePilha(&p2);

    mergePilhas(&p1, &p2, &p3);

    printf("P3 (decrescente): ");
    exibePilha(&p3);

    return 0;
}
