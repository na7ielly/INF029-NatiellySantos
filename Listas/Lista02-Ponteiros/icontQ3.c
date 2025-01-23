/*3) A figura abaixo mostra uma lista simplesmente encadeada, onde cada nó possui o
ponteiro para o próximo e um valor. O ponteiro inicio indica o inicio da lista (aponta
para NULO se a lista for vazia). Apresente os algoritmos corretos para:
a) Inserir um novo nó;
b) Buscar um elemento com um dado valor val retornando o mesmo ou indicar que o
elemento não existe na lista;
c) Apagar um nó existente.*/

// a) Inserir um novo nó;
void inserirNo(No **inicio, int valor) {
    No *novoNo = criarNo(valor);
    novoNo->proximo = *inicio;
    *inicio = novoNo;
}


// b) Buscar um elemento com um dado valor val retornando o mesmo ou indicar que o
No* buscarSimples(No *inicio, int valor) {
    while (inicio != NULL) {
        if (inicio->valor == valor)
            return inicio;
        inicio = inicio->proximo;
    }
    return NULL;
}

//c) Apagar um nó existente.
void apagarNo(No **inicio, int valor) {
    No *atual = *inicio, *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Valor não encontrado.\n");
        return;
    }

    if (anterior == NULL) { // Remover o primeiro nó
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);
}

