/*
QUESTÃO 04:
Faça um programa que monte uma pilha dinâmica com valores inteiros informados pelo usuário. 
Deve ter uma função insere, que recebe um ponteiro para o topo da pilha e insere o valor no topo.
*/

#include "funcoesGerais.h"

typedef struct no{
    int dado;
    struct no *proximo;    
}No;

No* push(No * topo)
{
    No *novoNo = malloc(sizeof(No));

    if(novoNo) /*Teste para ver se a memória foi alocada com sucesso.*/
    {
        printf("Insira um valor: ");
        int valor;
        scanf("%d", &valor);
        novoNo->dado = valor;
        novoNo->proximo = topo;
        return novoNo;
    }
    else
    {
        printf("\nErro ao alocar memória\n");
        return NULL;
    }
}

No *pop(No **topo)
{
    if (*topo != NULL)
    {
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
    {
        printf("\nPilha vazia!\n");
    }
    return NULL;    
}

void imprimirPilha(No *topo)
{
    printf("\n------- PILHA -------\n");

    while(topo)
    {
        printf(" %d, ", topo->dado);
        topo = topo->proximo;
    }

    printf("\n------- FINAL DA PILHA -------\n");
}

int main()
{
    No *topo = NULL;
    No *remover = NULL;
    int opcao;

    do
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            topo = push(topo);
            break;

        case 2:
            remover = pop(&topo);

            if(remover)
            {
                printf("Elemento removido: %d", remover->dado);
            }
            else
            {
                printf("Sem nó a remover");
            }
            break;
        
        case 3:
            imprimirPilha(topo);
            break;
        
        default:
            printf("\nOpção inválida!");
            break;
        }

    } while (opcao != 0);
    
}