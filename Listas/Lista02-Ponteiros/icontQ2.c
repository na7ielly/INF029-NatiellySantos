/*2) A figura abaixo mostra uma lista duplamente encadeada circular, onde cada nó possui o
ponteiro para o anterior, o ponteiro para o próximo e um valor. O ponteiro inicio indica
o inicio da lista (aponta para NULO se a lista for vazia). Apresente, ou em C, ou em
pseudo-linguagem, um passo a passo adequado para:
a) Inserir um novo nó, de forma ordenada (ex: o nó de valor 5 tem que ficar antes do
de valor 6 e depois do de valor 4);
b) Buscar um elemento com um dado valor val retornando o mesmo ou indicar que o
elemento não existe na lista.
*/

//a)
void inserirOrdenado(No **inicio, int valor) {
    No *novoNo = criarNo(valor);

    // Caso lista vazia
    if (*inicio == NULL) {
        novoNo->proximo = novoNo->anterior = novoNo;
        *inicio = novoNo;
        return;
    }

    No *atual = *inicio;

    // Inserção no início
    if (valor <= (*inicio)->valor) {
        while (atual->proximo != *inicio)
            atual = atual->proximo;
        novoNo->proximo = *inicio;
        novoNo->anterior = atual;
        atual->proximo = novoNo;
        (*inicio)->anterior = novoNo;
        *inicio = novoNo;
        return;
    }

    // Procurar posição para inserir
    while (atual->proximo != *inicio && atual->proximo->valor < valor)
        atual = atual->proximo;

    // Inserir entre atual e atual->proximo
    novoNo->proximo = atual->proximo;
    novoNo->anterior = atual;
    atual->proximo->anterior = novoNo;
    atual->proximo = novoNo;
}

//b)
No* buscarElemento(No *inicio, int valor) {
    if (inicio == NULL) return NULL;

    No *atual = inicio;
    do {
        if (atual->valor == valor)
            return atual;
        atual = atual->proximo;
    } while (atual != inicio);

    return NULL;
}
