/*QUESTÃO 01: Considere uma lista encadeada. Cada nó da lista deve conter (no mínimo) um número inteiro e
um ponteiro para o próximo elemento inserido na lista. O último elemento da lista deve apontar
para NULL.

Desenvolva um programa no computador, que contenha as funções:*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;


/*a. (Valor 0.5) Inserir elemento no final (int inserir(){}). A função deve solicitar o elemento ao
usuário. Deve retornar se foi inserido ou não (caso o novo elemento não possa ser
criado com a função malloc). A função main deve imprimir se foi ou não inserido;*/

int inserir(No **lista)
{
    // Alocar memória para o novo nó
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        return 0; // Falha na alocação
    }

        printf("Digite o valor a ser inserido: ");
        scanf("%d", &novo->valor);
        novo->proximo = NULL;

    // Se a lista estiver vazia, o novo nó será o primeiro
    if (*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        // Percorrer até o final da lista
        No *aux = *lista;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novo; // Adicionar o novo nó no final
    }

    return 1; // Sucesso
}

/*b. (Valor 1.5) Inserir elemento ordenado (int inserirOrdenado(){}). Colocar o elemento antes
do primeiro elemento maior que ele. A função deve solicitar o elemento ao usuário. A
função main deve imprimir se foi ou não inserido; */

int inserirOrdenado(No **lista)
{
    // Alocar memória para o novo nó
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        return 0; // Falha na alocação
    }

    // Solicitar o valor do novo elemento ao usuário
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &novo->valor);
    novo->proximo = NULL;

    // Caso a lista esteja vazia ou o novo valor seja menor que o primeiro elemento
    if (*lista == NULL || (*lista)->valor >= novo->valor)
    {
        novo->proximo = *lista; // Insere no início
        *lista = novo;
    }
    else
    {
        // Percorrer a lista para encontrar a posição correta
        No *aux = *lista;
        while (aux->proximo != NULL && aux->proximo->valor < novo->valor)
        {
            aux = aux->proximo;
        }

        // Inserir o novo nó na posição encontrada
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }

    return 1; // Sucesso
}

/*c. (Valor 1.5) Excluir elemento (int removerElemento(){}). A função deve solicitar o
elemento ao usuário, e retornar se foi removido. A função main deve imprimir se foi ou
não inserido, e qual foi o elemento removido. Caso julgue necessário, você pode colocar
um parâmetro extra na função;*/

int remover(){
    No *aux = *lista;
    No *anterior = NULL;
    int valor;

    printf("Digite o valor a ser removido: ");
    scanf("%d", &valor);

    // Percorrer a lista até encontrar o valor ou o final da lista
    while (aux != NULL && aux->valor != valor)
    {
        anterior = aux;
        aux = aux->proximo;
    }

    // Se o valor não foi encontrado
    if (aux == NULL)
    {
        return 0; // Falha
    }

    // Se o valor está no início da lista
    if (anterior == NULL)
    {
        *lista = aux->proximo;
    }
    else
    {
        anterior->proximo = aux->proximo;
    }

    free(aux); // Liberar a memória do nó removido
    return 1; // Sucesso
}

/*d. (Valor 2.0) Duplicar elementos pares ou ímpares com valores de sinais invertidos (void
duplicarElementos()). A função deve perguntar se é para duplicar os elementos pares ou
ímpares. Se for par, duplicar elementos pares, se ímpar, duplicar os ímpares.

Ex: 2, -4, 7, 6, -9 -> duplicar pares: 2, -2, -4, 4, 7, 6, -6, -9 /
 duplicar ímpares: 2, -4, 7, -7, 6, -9, 9
*/

void duplicarElementos(No **lista)
{
    if (*lista == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    int opcao;
    printf("Digite 0 para duplicar elementos pares ou 1 para duplicar elementos ímpares: ");
    scanf("%d", &opcao);

    No *aux = *lista;

    while (aux != NULL)
    {
        if ((opcao == 0 && aux->valor % 2 == 0) || (opcao == 1 && aux->valor % 2 != 0))
        {
            // Criar o novo nó com o valor invertido
            No *novo = (No *)malloc(sizeof(No));
            if (novo == NULL)
            {
                printf("Erro de memória ao tentar duplicar o elemento.\n");
                return;
            }
            novo->valor = -(aux->valor);
            novo->proximo = aux->proximo;

            // Inserir o novo nó após o nó atual
            aux->proximo = novo;

            // Avançar para o próximo elemento original (pular o duplicado)
            aux = novo->proximo;
        }
        else
        {
            // Avançar para o próximo elemento
            aux = aux->proximo;
        }
    }

    printf("Elementos duplicados com sucesso.\n");
}

/*e. (Valor 0.5) Imprimir elementos (void imprimir())*/

void imprimir(No *lista)
{
    if (lista == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Elementos da lista: ");
    No *aux = lista;
    while (aux != NULL)
    {
        printf("%d -> ", aux->valor);
        aux = aux->proximo;
    }
    printf("NULL\n");
}


/*f. (Valor 2.0) Imprimir ordenado (void imprimirOrdenado()). Nessa função você deve criar
uma nova lista com os elementos ordenados, imprimir a lista, e no final liberar todo o
espaço de todos os elementos dessa nova lista.*/

void imprimirOrdenado(No *lista)
{
    if (lista == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    // Criar uma nova lista para armazenar os elementos em ordem
    No *listaOrdenada = NULL;

    // Copiar elementos da lista original para a nova lista
    No *aux = lista;
    while (aux != NULL)
    {
        // Inserir cada elemento na nova lista de forma ordenada
        inserirOrdenado(&listaOrdenada, aux->valor);
        aux = aux->proximo;
    }

    // Imprimir a lista ordenada
    printf("Lista ordenada: ");
    aux = listaOrdenada;
    while (aux != NULL)
    {
        printf("%d -> ", aux->valor);
        aux = aux->proximo;
    }
    printf("NULL\n");

    // Liberar a memória da nova lista
    aux = listaOrdenada;
    while (aux != NULL)
    {
        No *temp = aux;
        aux = aux->proximo;
        free(temp);
    }
}
