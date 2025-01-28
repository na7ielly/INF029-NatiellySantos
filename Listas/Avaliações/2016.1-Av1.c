#include <stdio.h>
#include <stdbool.h>
#define TAM 100

/* Questão 01:
Se você pensar em um papel como um plano e uma letra como uma marcação neste plano, então
estas letras dividem o plano em regiões. Por exemplo, as letras A, D e O dividem o plano em 2 pois possuem
um espaço confinado em seu desenho, ou um “buraco”. Outras letras como B possuem 2 buracos e letras
como C e E não possuem buracos. Deste modo podemos considerar que o número de buracos em um texto
é igual a soma dos buracos nas palavras dele. A sua tarefa é, dado um texto qualquer, encontre a quantidade
de buracos nele. Seu programa deve ter pelo menos as seguintes funções:
a. qtdBuracosEmLetra -> esta função recebe uma letra e retorna a quantidade de buracos nela
b. qtdBuracosEmTexto -> esta função recebe um texto e retorna a quantidade de buracos nele. Ela
deve usar qtdBuracosEmLetra
c. a função main, deve solicitar o texto do usuário e informar quantos buracos tem no texto.
*/

int qtdBuracosEmLetra(char c) {
    if (c == 'A' || c == 'D' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || 
        c == 'a' || c == 'b' || c == 'd' || c == 'e' || c == 'g' || c == 'o' || 
        c == 'p' || c == 'q') {
        return 1;
    }
    if (c == 'B') {
        return 2;
    }
    return 0;  // Todas as outras letras não têm buracos
}

int qtdBuracosEmTexto(char string[]) {
    int totalBuracos = 0, i = 0;

    while (string[i] != '\0') {
        totalBuracos += qtdBuracosEmLetra(string[i]);
        i++;
    }
    return totalBuracos;
}

int calcularTamanho(char string[]) {
    int tamanho = 0;
    while (string[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

void removerNovaLinha(char string[]) {
    int tamanho = calcularTamanho(string);
    if (tamanho > 0 && string[tamanho - 1] == '\n') {
        string[tamanho - 1] = '\0';
    }
}

/*int main() {
    char string[TAM];

    printf("Digite o texto: ");
    fgets(string, sizeof(string), stdin);

    // Remover o '\n' se presente
    removerNovaLinha(string);

    int totalBuracos = qtdBuracosEmTexto(string);
    printf("Total de buracos: %d\n", totalBuracos);

    return 0;
}
*/


/* Questão 02:
Crie um programa que tenha um vetor de caracteres. Esse vetor deve ter um tamanho máximo
TAM = 10. Nenhum parâmetro pode ser global. O programa deve ter:

a. A função menu com as opções: insere caractere, troca caractere, sair

b. uma função “insere caractere”. Ela deve solicitar o caractere ao usuário, e inserir no vetor, na primeira
posição vazia, se ainda tiver espaço. Deve retornar se foi inserido ou não.

c. Uma função “troca caractere”. Essa função solicita um novo caractere ao usuário. A função deve
procurar no vetor o primeiro caractere que é maior que o caractere informado, quando achar, fazer a
troca. A função deve retornar se houve a troca ou não. Quando houver a troca, a função principal
(main) deve ser capaz de imprimir qual foi o caractere que saiu do vetor.
*/

int obtemOpcao() {
    int opcao;
    printf("\nOpções:\n");
    printf("0: Sair\n");
    printf("1: Inserir caractere\n");
    printf("2: Trocar caractere\n");

    scanf("%d", &opcao);
    return opcao;
}

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

/*int main() {
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
            default: {
                printf("Opção inválida!\n");
                break;
            }
        }
    }

    return 0;
}
*/