/*Considere o trabalho II da disciplina. Neste trabalho o aluno teve que implementar um programa para a
questão de vetores com ponteiros para vetores, conforme Figura	1.

1. (Valor 4.0) Crie uma função void somaEspecial(...). Essa função deve ter dois somatórios somaA e somaB.
- somaA deve ser a soma de todos os elementos pares dos vetores ímpares – a soma de todos os elementos
ímpares dos vetores pares. Para definir vetor par e impar, considere a numeração dos vetores de 1 a 10. No
exemplo da Figura 1 acima, seria: (4 + 6 + 18 + -16) – (5 + 3 + -1) = 12 – 7 = 5
- somaB deve ser a soma de todos os elementos dos vetores que têm pelo menos dois elementos negativos.
No exemplo da Figura 1 acima, seria: -1 + 18 + -16 = 1.
A função main, que chama essa função, deve imprimir os dois resultados: somaA e somaB.
*/

void somaEspecial(int *somaA, int *somaB) {
    *somaA = 0;
    *somaB = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] == NULL) continue;

        int negativos = 0;
        int somaTemp = 0;

        for (int j = 0; j < vetorPrincipal[i]->ocupados; j++) {
            int valor = vetorPrincipal[i]->valores[j];

            if (valor < 0) negativos++;

            // Índices são baseados na posição do vetor (1 a 10)
            if ((i + 1) % 2 == 1 && valor % 2 == 0) { 
                *somaA += valor; // Vetores ímpares, pegar pares
            } else if ((i + 1) % 2 == 0 && valor % 2 != 0) { 
                *somaA -= valor; // Vetores pares, pegar ímpares
            }

            somaTemp += valor;
        }

        if (negativos >= 2) {
            *somaB += somaTemp;
        }
    }
}

/*. (Valor 4.0) Faça uma função montarListaEncadeada(...) que monta uma lista encadeada já ordenada (não
deve chamar função de ordenação) do menor para o maior elemento de todos os elementos dos vetores. A
função deve retornar um ponteiro para o primeiro elemento da lista. Use a estrutura a seguir.

struct no {
 int num;
 struct no *prox;
};

Para o exemplo da Figura	1, a lista resultante seria:
-16 -> -1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 18 -> 23 -> 35
*/

typedef struct No {
    int num;
    struct No *prox;
} No;

No* montarListaEncadeada() {
    No *inicio = NULL, *atual, *anterior, *novo;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] == NULL) continue;

        for (int j = 0; j < vetorPrincipal[i]->ocupados; j++) {
            int valor = vetorPrincipal[i]->valores[j];

            // Criar um novo nó
            novo = (No*)malloc(sizeof(No));
            novo->num = valor;
            novo->prox = NULL;

            // Caso a lista esteja vazia
            if (inicio == NULL) {
                inicio = novo;
            } else {
                atual = inicio;
                anterior = NULL;

                // Encontrar a posição correta de inserção
                while (atual != NULL && atual->num < valor) {
                    anterior = atual;
                    atual = atual->prox;
                }

                // Inserir no início
                if (anterior == NULL) {
                    novo->prox = inicio;
                    inicio = novo;
                }
                // Inserir no meio ou fim
                else {
                    anterior->prox = novo;
                    novo->prox = atual;
                }
            }
        }
    }
    return inicio;
}

