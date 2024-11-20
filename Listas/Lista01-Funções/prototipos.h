#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constantes.h"

//Structs
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[MAXNOME];
    Data dataNascimento;
    char cpf[MAXCPF];
    char sexo;
} Cliente;

//Protótipos das funções usadas nas questões
int somar(int x, int y);
int subtrair(int a, int b, int c);
int fatorial (int num);
void lerTresNumeros (int numeros[]);
struct Numeros lerQuatroNumeros();
void lerTresLetras (char letras[]);
void lerTresPalavras(char palavras[][MAX_LETRAS]);
Cliente cadastrarCliente();
int validarNome (char nome[]);
int validarSexo(char sexo);
int validarCPF(char cpf[]);
int validarNascimento(int dia, int mes, int ano);

#endif
