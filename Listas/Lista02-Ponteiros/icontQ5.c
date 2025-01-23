/*5) Uma palavra é um palíndromo se tem a mesma seqüência de letras, quer seja lida da
esquerda para a direita ou da direita para a esquerda (exemplo: raiar). Utilizando uma
pilha, proponha um algoritmo que teste se uma palavra é palíndromo (dicas: uma parte
da palavra será empilhada e comparada a outra parte da palavra, ainda, observar que
palavras com tamanho par tem tratamento um pouco diferente de palavras de tamanho
impar).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da Pilha
typedef struct {
    char *itens;  // Vetor para armazenar os elementos da pilha
    int topo;     // Índice do topo da pilha
    int capacidade; // Capacidade máxima da pilha
} Pilha;

// Função para inicializar a pilha
Pilha* criarPilha(int capacidade) {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->itens = (char *)malloc(capacidade * sizeof(char));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

// Função para verificar se a pilha está cheia
int pilhaCheia(Pilha *pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

// Função para empilhar um elemento
void empilhar(Pilha *pilha, char elemento) {
    if (pilhaCheia(pilha)) {
        printf("Pilha cheia! Não é possível empilhar.\n");
        return;
    }
    pilha->itens[++pilha->topo] = elemento;
}

// Função para desempilhar um elemento
char desempilhar(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return '\0';
    }
    return pilha->itens[pilha->topo--];
}

// Função para liberar a memória da pilha
void liberarPilha(Pilha *pilha) {
    free(pilha->itens);
    free(pilha);
}

// Função para verificar se uma palavra é um palíndromo
int ehPalindromo(char *palavra) {
    int tamanho = strlen(palavra);
    Pilha *pilha = criarPilha(tamanho / 2);

    // Empilhar a primeira metade da palavra
    for (int i = 0; i < tamanho / 2; i++) {
        empilhar(pilha, palavra[i]);
    }

    // Determinar o ponto de início da segunda metade
    int inicioSegundaMetade = (tamanho % 2 == 0) ? tamanho / 2 : (tamanho / 2) + 1;

    // Comparar a segunda metade com os elementos desempilhados
    for (int i = inicioSegundaMetade; i < tamanho; i++) {
        if (palavra[i] != desempilhar(pilha)) {
            liberarPilha(pilha);
            return 0;  // Não é palíndromo
        }
    }

    liberarPilha(pilha);
    return 1;  // É palíndromo
}

// Função principal
int main() {
    char palavra[100];

    printf("Digite uma palavra para verificar se é palíndromo: ");
    scanf("%s", palavra);

    if (ehPalindromo(palavra)) {
        printf("A palavra '%s' é um palíndromo.\n", palavra);
    } else {
        printf("A palavra '%s' não é um palíndromo.\n", palavra);
    }

    return 0;
}
