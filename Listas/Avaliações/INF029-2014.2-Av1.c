/*
1. (Valor 2.0) Defina modularização no contexto de software. Apresente seu objetivo e suas
vantagens.
*/

/*
2. (Valor 3.0) Faça um programa em C que contenha:

    a. uma função “multiplica” que receba como parâmetros dois números inteiros e retorne o
resultado da multiplicação;

    b. uma função “soma” que receba como parâmetros dois números inteiros e retorne o
resultado da soma;

    c. A função main deve fazer o seguinte: solicitar quatro valores inteiros A, B, C e D.
Chamar a função de multiplicação duas vezes, com (A, B) e com (C, D). Depois chame a
função “soma” para somar os dois resultados retornados pela função “multiplica”. No
final apresente o resultado do retorno da soma.
*/

#include <stdio.h>
#include <stdbool.h>

#define TAM 10 //Questão 03

int multiplicar(int a, int b){
    return a * b;
}

int somar(int x, int y){
    return x + y;
}

//Função main:
/*
int main(){

    int a, b, c, d;

    printf("Digite os quatro números: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int resultado1 = multiplicar(a, b);
    int resultado2 = multiplicar(c, d);

    int resultadoSoma = somar(resultado1, resultado2);

    printf("Resultado: %d", resultadoSoma);

    return 0;
}
*/

/*
3. (Valor 5.0) Crie um programa que tenha um vetor de caracteres. Esse vetor deve ter um
tamanho máximo TAM = 10. Nenhum parâmetro pode ser global. O programa deve ter:

    a. uma função “insere caractere”. Ela deve solicitar o caractere ao usuário, e inserir no
vetor, na primeira posição vazia, se ainda tiver espaço. Deve retornar se foi inserido ou
não.

    b. Uma função “troca caractere”. Essa função solicita um novo caractere ao usuário. A
função deve procurar no vetor o primeiro caractere que é maior que o caractere
informado, quando achar, fazer a troca. A função deve retornar se houve a troca ou não.
Quando houver a troca, a função principal (main) deve ser capaz de imprimir qual foi o
caractere que saiu do vetor.

    c. Uma função para remover caracteres. A remoção deve ser lógica, no final do vetor.
Basta nesse caso decrementar o topo.

    d. Uma função para listar os caracteres.
*/

int inserirCaractere(char string[], int *topo){
    char c;

    printf("Digite o caractere: ");
    scanf(" %c", &c);

    //Inserir no vetor na primeira posição vazia, se tiver espaço.
    if (*topo < TAM) {
        string[*topo] = c;
        (*topo)++;
        printf("Caractere inserido com sucesso!\n");
        return 1;
    } else {
        printf("Vetor cheio, caractere não inserido!\n");
        return 0;
    }
}

char trocarCaractere(char string[], int topo) {
    char c;
    printf("Digite o caractere: ");
    scanf(" %c", &c);

    for (int i = 0; i < topo; i++) {
        if (string[i] > c) {
            char aux = string[i];
            string[i] = c;
            printf("Troca realizada!\n");
            return aux;
        }
    }

    printf("Troca não realizada!\n");
    return '\0';
}

void removerCaractere(char string[], int *topo) {
    if (*topo > 0) {
        (*topo)--;
        string[*topo] = '\0';
        printf("Remoção feita com sucesso!\n");
    } else {
        printf("A string está vazia!\n");
    }
}

void listarCaracteres(char string[], int topo) {
    if (topo == 0) {
        printf("O vetor está vazio.\n");
    } else {
        printf("Caracteres no vetor: ");
        for (int i = 0; i < topo; i++) {
            printf("%c ", string[i]);
        }
        printf("\n");
    }
}

int obtemOpcao() {
    int opcao;
    printf("\nOpções:\n");
    printf("0: Sair\n");
    printf("1: Inserir caractere\n");
    printf("2: Trocar caractere\n");
    printf("3: Remover caractere\n");
    printf("4: Listar caracteres\n");

    scanf("%d", &opcao);
    return opcao;
}

//Função main:
/*
int main() {
    char stringMain[TAM] = {'\0'}; //Inicializa com todas as posições contendo '\0'
    int topo = 0;  // Índice do próximo caractere livre
    bool sair = false;

    while (!sair) {
        switch (obtemOpcao()) {
            case 0: {
                sair = true;
                break;
            }
            case 1: {
                inserirCaractere(stringMain, &topo);
                break;
            }
            case 2: {
                char aux = trocarCaractere(stringMain, topo);
                if (aux != '\0') {
                    printf("Caractere que saiu do vetor: %c\n", aux);
                }
                break;
            }
            case 3: {
                removerCaractere(stringMain, &topo);
                break;
            }
            case 4: {
                listarCaracteres(stringMain, topo);
                break;
            }
            default: {
                printf("Opção inválida!\n");
                break;
            }
        }
    }

    return 0;
}
*/