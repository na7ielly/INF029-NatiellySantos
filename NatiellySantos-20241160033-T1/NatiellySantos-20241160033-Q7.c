#include "NatiellySantos-20241160033-Q7.h"

int main() {
    char tabuleiro[TAM][TAM] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int jogador = 1, jogadas = 0;
    char entrada[3], linha;
    int coluna;

    while (1) {
        exibirTabuleiro(tabuleiro);
        printf("Jogador %d (%c), informe sua jogada (ex: B2): ", jogador, jogador == 1 ? 'X' : 'O');
        scanf("%s", entrada);

        linha = toupper(entrada[0]); //Função para aceitar letras minúsculas: toupper; pega o primeiro caractere digitado pelo usuário (equivalente a linha)
        coluna = entrada[1] - '0'; //Pega o segundo caractere; Converte o caractere numérico ('1', '2', '3') para um número inteiro correspondente

        if (linha >= 'A' && linha <= 'C' && coluna >= 1 && coluna <= 3 && tabuleiro[linha - 'A'][coluna - 1] == ' ') {
            tabuleiro[linha - 'A'][coluna - 1] = jogador == 1 ? 'X' : 'O';
            jogadas++;

            if (verificarVencedor(tabuleiro)) {
                exibirTabuleiro(tabuleiro);
                printf("Jogador %d venceu!\n", jogador);
                break;
            }

            if (jogadas == 9) {
                exibirTabuleiro(tabuleiro);
                printf("Empate! Nenhum jogador venceu.\n");
                break;
            }

            jogador = 3 - jogador; // Alterna entre 1 e 2
        } else {
            printf("Jogada inválida! Tente novamente.\n");
        }
    }

    return 0;
}

// Funções:
void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("   1   2   3\n");
    for (int i = 0; i < TAM; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAM - 1) printf("|");
        }
        printf("\n");
        if (i < TAM - 1) printf("  ---|---|---\n");
    }
}

int verificarVencedor(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return 1;
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return 1;
    }
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return 1;
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return 1;

    return 0;
}