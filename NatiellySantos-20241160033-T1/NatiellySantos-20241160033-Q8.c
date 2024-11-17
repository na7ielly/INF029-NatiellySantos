#include "NatiellySantos-20241160033-Q8.h"

// Configuração global de navios
int tamanhos_navios[] = {4, 3, 2, 2, 1, 1, 1}; // Aumentar conforme necessário
int num_navios = sizeof(tamanhos_navios) / sizeof(tamanhos_navios[0]); // Calcula o número total de navios

int main() {
    Jogador jogador1, jogador2;
    inicializarTabuleiro(jogador1.tabuleiro);
    inicializarTabuleiro(jogador1.visao_oponente);
    inicializarTabuleiro(jogador2.tabuleiro);
    inicializarTabuleiro(jogador2.visao_oponente);

    jogador1.navios_restantes = jogador2.navios_restantes = num_navios;

    printf("\nJogador 1, posicione seus navios:\n");
    for (int i = 0; i < num_navios; i++) posicionarNavio(&jogador1, tamanhos_navios[i]);

    printf("Jogador 2, posicione seus navios:\n");
    for (int i = 0; i < num_navios; i++) posicionarNavio(&jogador2, tamanhos_navios[i]);

    int turno = 1;
    
    while (jogador1.navios_restantes > 0 && jogador2.navios_restantes > 0) {
        printf("Turno do Jogador %d\n", turno);
        if (turno == 1) {
            exibirTabuleiro(jogador1.visao_oponente);
            realizarTiro(&jogador1, &jogador2);
        } else {
            exibirTabuleiro(jogador2.visao_oponente);
            realizarTiro(&jogador2, &jogador1);
        }
        turno = 3 - turno; // Alterna entre 1 e 2
    }

    if (jogador1.navios_restantes == 0)
        printf("Jogador 2 venceu!\n");
    else
        printf("Jogador 1 venceu!\n");

    return 0;
}

// Funções:
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            tabuleiro[i][j] = ' ';
}

void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   "); // Espaço inicial para alinhar com os números das linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) 
        printf(" %d ", i); // Exibe os números das colunas com espaço adequado
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Exibe o número da linha alinhado
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
            printf("[%c]", tabuleiro[i][j]); // Exibe as células do tabuleiro
        printf("\n");
    }
}

int validarPosicao(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int tamanho, char orientacao) {
    if (orientacao == 'h') {
        // Verifica se o navio cabe horizontalmente
        if (y + tamanho > TAMANHO_TABULEIRO) return 0; // Se ultrapassar o limite da coluna

        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x][y + i] != ' ') { // Verifica se a célula já está ocupada
                return 0;
            }
        }
    } else if (orientacao == 'v') {
        // Verifica se o navio cabe verticalmente
        if (x + tamanho > TAMANHO_TABULEIRO) return 0; // Se ultrapassar o limite da linha

        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y] != ' ') { // Verifica se a célula já está ocupada
                return 0;
            }
        }
    } else {
        return 0; // Caso a orientação seja inválida
    }

    return 1; // Se todas as verificações passarem, a posição é válida
}

void inicializarJogador(Jogador *jogador) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            jogador->tabuleiro[i][j] = ' ';
        }
    }
    jogador->navios_restantes = 0; // Inicializa o contador
}

void validarEntrada(int *linha, int *coluna, char *orientacao) {
    while (1) {
        printf("Digite a linha, coluna e orientação (H/h para horizontal, V/v para vertical): ");
        
        // Lê a entrada e verifica se os três elementos foram fornecidos corretamente
        if (scanf("%d %d %c", linha, coluna, orientacao) != 3) {
            printf("Entrada inválida!\n");
            while (getchar() != '\n'); // Limpa o buffer do teclado
            continue;
        }

        // Verifica se a linha e a coluna estão dentro do intervalo permitido
        if (*linha < 0 || *linha > 9 || *coluna < 0 || *coluna > 9) {
            printf("Coordenadas fora do intervalo! Linha e coluna devem estar entre 0 e 9.\n");
            continue;
        }

        // Converte a orientação para minúscula e valida
        *orientacao = tolower(*orientacao);
        if (*orientacao != 'h' && *orientacao != 'v') {
            printf("Orientação inválida! Use 'H' ou 'h' para horizontal; 'V' ou 'v' para vertical.\n");
            continue;
        }

        // Se todas as validações passarem, sai do loop
        break;
    }
}

void posicionarNavio(Jogador *jogador, int tamanho) {
    int x, y;
    char orientacao;

    // Exibe o tabuleiro inicial para o jogador
    printf("\nTabuleiro atual:\n");
    exibirTabuleiro(jogador->tabuleiro);

    while (1) { // Loop até o jogador posicionar corretamente
        printf("Posicione um navio de tamanho %d\n", tamanho);

        // Obtém entrada validada do jogador
        validarEntrada(&x, &y, &orientacao);

        // Verifica se a posição e orientação são válidas
        if (validarPosicao(jogador->tabuleiro, x, y, tamanho, orientacao)) {
            // Posiciona o navio no tabuleiro
            if (orientacao == 'h' || orientacao == 'H') {
                for (int i = 0; i < tamanho; i++) 
                    jogador->tabuleiro[x][y + i] = 'N';
            } else {
                for (int i = 0; i < tamanho; i++) 
                    jogador->tabuleiro[x + i][y] = 'N';
            }

            jogador->navios_restantes += tamanho;

            // Exibe o tabuleiro atualizado uma única vez após o posicionamento
            printf("\nNavio posicionado com sucesso! Tabuleiro atualizado:\n");
            exibirTabuleiro(jogador->tabuleiro);
            break; // Sai do loop
            
        } else {
            // Mensagem de erro sem exibir novamente o tabuleiro
            printf("Posição inválida ou fora do tabuleiro! Tente novamente.\n");
        }
    }
}

int realizarTiro(Jogador *atirador, Jogador *alvo) {
    int x, y;
    printf("Informe a linha e coluna para atirar (formato: linha coluna): ");
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= TAMANHO_TABULEIRO || y < 0 || y >= TAMANHO_TABULEIRO) {
        printf("Coordenadas inválidas!\n");
        return 0;
    }

    if (alvo->tabuleiro[x][y] == 'N') {
        printf("Acertou!\n");
        alvo->tabuleiro[x][y] = '0'; // Marca como atingido
        atirador->visao_oponente[x][y] = '0'; // Atualiza a visão do atirador
        alvo->navios_restantes--; // Reduz o número de células restantes para o jogador alvo

        // Verifica se todas as células de navios foram destruídas
        if (alvo->navios_restantes == 0) {
            printf("Todos os navios do oponente foram afundados! Você venceu!\n");
            return 1; // Indica que o jogo terminou
        }
        return 0;
    } else if (alvo->tabuleiro[x][y] == ' ') {
        printf("Errou!\n");
        atirador->visao_oponente[x][y] = 'X'; // Marca como erro
        return 0;
    } else {
        printf("Você já atirou aqui!\n");
        return 0;
    }
}