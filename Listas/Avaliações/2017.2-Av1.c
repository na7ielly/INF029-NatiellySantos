//1) Crie um programa que tenha um vetor de caracteres. Esse vetor deve ter um tamanho máximo
//TAM = 10. Nenhum parâmetro pode ser global. Utilize boas práticas de modularização.

/*O programa deve ter:
a. a função main, responsável por interagir com o usuário, informando os resultados das operações
das demais funções
b. uma função “insere caractere”. Ela deve solicitar o caractere ao usuário, e inserir no vetor, na
primeira posição vazia, se ainda tiver espaço. Deve retornar se foi inserido ou não.
c. Uma função “troca caractere”. Essa função solicita um novo caractere ao usuário. A função deve
procurar no vetor o primeiro caractere que é maior que o caractere informado, quando achar, fazer
a troca. A função deve retornar se houve a troca ou não. Quando houver a troca, a função principal
(main) deve ser capaz de imprimir qual foi o caractere que saiu do vetor.
d. Uma função para remover caracteres. A remoção deve ser lógica, no final do vetor. Basta nesse
caso decrementar o topo.
e. Uma função para listar os caracteres.
f. uma função que imprime cada um dos caracteres distintos e a quantidade de vezes que ele
aparece no vetor*/

#include <stdio.h>

#define TAM 10

// Função para contar caracteres distintos
void contarCaracteres(char vetor[TAM], int qtd) {
    int contagem[256] = {0}; // Array para contar caracteres ASCII (256 valores possíveis)

    // Conta cada caractere no vetor
    for (int i = 0; i < qtd; i++) {
        contagem[(unsigned char)vetor[i]]++;
    }

    // Exibe a contagem dos caracteres presentes
    printf("Frequencia dos caracteres:\n");
    for (int i = 0; i < 256; i++) {
        if (contagem[i] > 0) {
            printf("'%c' -> %d vez(es)\n", i, contagem[i]);
        }
    }
}

// Função de menu
int menu() {
    int op;
    printf("\nDigite a opcao:\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Trocar caracter\n");
    printf("3 - Remover\n");
    printf("4 - Listar\n");
    printf("5 - Contar caracteres\n");
    scanf("%d", &op);
    return op;
}

// Função para inserir caracteres
int insereCaracteres(char vetor[TAM], int qtd) {
    char c;
    if (qtd < TAM) {
        printf("Digite um caractere:\n");
        scanf(" %c", &c); // Corrigido o scanf para lidar com espaço em branco
        vetor[qtd] = c;
        return 1;
    } else {
        return 0;
    }
}

// Função para trocar caracteres
void trocarCaracter(char vetor[TAM], int qtd) {
    char c;
    int i;
    int trocado = 0;
    
    printf("Digite um caractere para troca:\n");
    scanf(" %c", &c); // Lê o caractere a ser trocado

    for (i = 0; i < qtd; i++) {
        if (vetor[i] != c) {
            vetor[i] = c;
            trocado = 1;
            break;
        }
    }

    if (trocado) {
        printf("Caractere trocado com sucesso.\n");
    } else {
        printf("Nao foi possivel realizar a troca.\n");
    }
}

// Função para remover um caractere
int removeCaracter(char vetor[TAM], int qtd) {
    if (qtd > 0) {
        // Desloca os caracteres para "remover" o último
        vetor[qtd - 1] = '\0';
        return qtd - 1;
    }
    return qtd;
}

// Função para listar caracteres
void listarCaracteres(char vetor[TAM], int qtd) {
    printf("Caracteres no vetor:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%c\n", vetor[i]);
    }
}

// Função principal
int main() {
    int qtd = 0;
    char vetor[TAM];
    int sair = 0;
    int op, retorno;

    while (!sair) {
        op = menu(); // Chama o menu e pega a opção do usuário
        switch (op) {
            case 0: {
                sair = 1; // Sair do programa
                break;
            }
            case 1: {
                // Inserir caractere
                retorno = insereCaracteres(vetor, qtd);
                if (retorno == 1) {
                    printf("Caractere inserido com sucesso.\n");
                    qtd++;
                } else {
                    printf("Nao foi possivel inserir. Vetor cheio.\n");
                }
                break;
            }
            case 2: {
                // Trocar caractere
                trocarCaracter(vetor, qtd);
                break;
            }
            case 3: {
                // Remover caractere
                qtd = removeCaracter(vetor, qtd);
                printf("Caractere removido. Tamanho atual: %d\n", qtd);
                break;
            }
            case 4: {
                // Listar caracteres
                listarCaracteres(vetor, qtd);
                break;
            }
            case 5: {
                // Contar caracteres
                contarCaracteres(vetor, qtd);
                break;
            }
            default: {
                printf("Opcao invalida.\n");
            }
        }
    }

    printf("Saindo do programa...\n");
    return 0;
}
