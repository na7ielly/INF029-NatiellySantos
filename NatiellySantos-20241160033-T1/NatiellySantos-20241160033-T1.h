// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Dados do Aluno -----
//  Nome: Natielly Santos
//  Email: 20241160033@ifba.edu.br
//  Matrícula: 20241160033
//  Semestre: 2024.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################
#ifndef TRABALHO1_NATIELLYSANTOS20241160033_H
#define TRABALHO1_NATIELLYSANTOS20241160033_H

typedef struct DQ
{
    int iDia; 
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

int somar(int x, int y); //função utilizada para testes
int fatorial(int x); //função utilizada para testes
int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);

//FUNÇÕES PARA RESOLUÇÃO DE QUESTÕES
DataQuebrada quebraData(char data[]);
int ehBissexto(int ano);
int validaDiaMesAno(int dia, int mes, int ano);
int diasNoMes(int mes, int ano);
char removeAcento(char c);

#endif  // TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H