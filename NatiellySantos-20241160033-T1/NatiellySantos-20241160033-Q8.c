#include "NatiellySantos-20241160033-Q8.h"

// Configuração global de navios
int tamanhos_navios[] = {4, 3, 2, 2, 1, 1, 1}; // Navios predefinidos
int num_navios = sizeof(tamanhos_navios) / sizeof(tamanhos_navios[0]);

int main() {
    Jogador jogador1, jogador2;
    inicializarTabuleiro(jogador1.tabuleiro);
    inicializarTabuleiro(jogador1.visao_oponente);
    inicializarTabuleiro(jogador2.tabuleiro);
    inicializarTabuleiro(jogador2.visao_oponente);

    // Inicializa os navios restantes como a soma total de células ocupadas
    jogador1.navios_restantes = jogador2.navios_restantes = 0;
    for (int i = 0; i < num_navios; i++) {
        jogador1.navios_restantes += tamanhos_navios[i];
        jogador2.navios_restantes += tamanhos_navios[i];
    }

    printf("\nJogador 1, posicione seus navios:\n");
    for (int i = 0; i < num_navios; i++) posicionarNavio(&jogador1, tamanhos_navios[i]);

    printf("\nJogador 2, posicione seus navios:\n");
    for (int i = 0; i < num_navios; i++) posicionarNavio(&jogador2, tamanhos_navios[i]);

    int turno = 1;

    while (1) {
        printf("\nTurno do Jogador %d\n", turno);
        if (turno == 1) {
            exibirTabuleiro(jogador1.visao_oponente);
            realizarTiro(&jogador1, &jogador2);
        } else {
            exibirTabuleiro(jogador2.visao_oponente);
            realizarTiro(&jogador2, &jogador1);
        }

        // Verificação de vitória
        if (jogador1.navios_restantes == 0) {
            printf("\nJogador 2 venceu!\n");
            break;
        } else if (jogador2.navios_restantes == 0) {
            printf("\nJogador 1 venceu!\n");
            break;
        }

        turno = 3 - turno; // Alterna entre 1 e 2
    }

    return 0;
}

// Funções auxiliares:
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = ' ';
}

void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) 
        printf(" %d ", i);
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            printf("[%c]", tabuleiro[i][j]);
        printf("\n");
    }
}

int validarPosicao(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int tamanho, char orientacao) {
    if (orientacao == 'h') {
        if (y + tamanho > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x][y + i] != ' ') return 0;
        }
    } else if (orientacao == 'v') {
        if (x + tamanho > TAMANHO_TABULEIRO) return 0;
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y] != ' ') return 0;
        }
    } else {
        return 0;
    }
    return 1;
}

void validarEntrada(int *linha, int *coluna, char *orientacao) {
    while (1) {
        printf("Digite a linha, coluna e orientação (H/h para horizontal, V/v para vertical): ");
        if (scanf("%d %d %c", linha, coluna, orientacao) != 3) {
            printf("Entrada inválida!\n");
            while (getchar() != '\n');
            continue;
        }
        if (*linha < 0 || *linha >= TAMANHO_TABULEIRO || *coluna < 0 || *coluna >= TAMANHO_TABULEIRO) {
            printf("Coordenadas fora do intervalo! Tente novamente.\n");
            continue;
        }
        *orientacao = tolower(*orientacao);
        if (*orientacao != 'h' && *orientacao != 'v') {
            printf("Orientação inválida! Tente novamente.\n");
            continue;
        }
        break;
    }
}

void posicionarNavio(Jogador *jogador, int tamanho) {
    int x, y;
    char orientacao;

    while (1) {
        printf("\nPosicione um navio de tamanho %d\n", tamanho);
        exibirTabuleiro(jogador->tabuleiro);
        validarEntrada(&x, &y, &orientacao);
        if (validarPosicao(jogador->tabuleiro, x, y, tamanho, orientacao)) {
            if (orientacao == 'h') {
                for (int i = 0; i < tamanho; i++) 
                    jogador->tabuleiro[x][y + i] = 'N';
            } else {
                for (int i = 0; i < tamanho; i++) 
                    jogador->tabuleiro[x + i][y] = 'N';
            }
            break;
        } else {
            printf("Posição inválida! Tente novamente.\n");
        }
    }
}

int realizarTiro(Jogador *atirador, Jogador *alvo) {
    int x, y;
    printf("Informe a linha e coluna para atirar (linha coluna): ");
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= TAMANHO_TABULEIRO || y < 0 || y >= TAMANHO_TABULEIRO) {
        printf("Coordenadas inválidas! Perdeu o turno.\n");
        return 0;
    }

    if (alvo->tabuleiro[x][y] == 'N') {
        printf("Acertou!\n");
        alvo->tabuleiro[x][y] = '0';
        atirador->visao_oponente[x][y] = '0';
        alvo->navios_restantes--;
        return 0;
    } else if (alvo->tabuleiro[x][y] == ' ') {
        printf("Errou!\n");
        atirador->visao_oponente[x][y] = 'X';
        return 0;
    } else {
        printf("Você já atirou aqui!\n");
        return 0;
    }
}