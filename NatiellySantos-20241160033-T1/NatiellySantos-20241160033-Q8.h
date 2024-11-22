#ifndef Q8_NATIELLYSANTOS20241160033_H
#define Q8_NATIELLYSANTOS20241160033_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_TABULEIRO 10
#define NUMERO_MINIMO_NAVIOS 7

// Estrutura para representar um jogador
typedef struct {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    char visaoOponente[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int naviosRestantes;
} Jogador;

void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
int validarPosicao(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int tamanho, char orientacao);
void inicializarJogador(Jogador *jogador);
void validarEntrada(int *linha, int *coluna, char *orientacao);
void posicionarNavio(Jogador *jogador, int tamanho);
int realizarTiro(Jogador *atirador, Jogador *alvo);

#endif