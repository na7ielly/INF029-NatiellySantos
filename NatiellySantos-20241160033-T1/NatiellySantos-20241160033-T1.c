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
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "NatiellySantos-20241160033-T1.h" 
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
    int datavalida = 1;

    // Quebrar a string data em strings sDia, sMes, sAno
    DataQuebrada dq = quebraData(data);

    // Verifica se a data quebrada é válida
    if (dq.valido == 0) {
        datavalida = 0;
    
    } else { //Outras validções
        
        // Valida o ano
        if (dq.iAno < 1) {
            datavalida = 0;
        }
        // Valida o mês
        if (dq.iMes < 1 || dq.iMes > 12) {
            datavalida = 0;
        }

        if (datavalida) {
            // Verificação se o ano é bissexto
            int ehBissexto = (dq.iAno % 4 == 0 && (dq.iAno % 100 != 0 || dq.iAno % 400 == 0));

            // Valida o dia com base no mês e no ano, distingue quando é bissexto
            int diasNoMes[] = {31, ehBissexto ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (dq.iDia < 1 || dq.iDia > diasNoMes[dq.iMes - 1]) {
                datavalida = 0;
            }
        }
    }
    return datavalida;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma = {0, 0, 0, 1}; // Inicializa os valores, assumindo retorno 1 para sucesso

    // Valida as datas usando a função q1
    if (q1(datainicial) == 0) {
        dma.retorno = 2; // Retorno 2 -> data inicial inválida
        return dma;
    
    } else if (q1(datafinal) == 0) {
        dma.retorno = 3; // Retorno 3 -> data final inválida
        return dma;
    
    } else {
        DataQuebrada dqInicial = quebraData(datainicial);
        DataQuebrada dqFinal = quebraData(datafinal);

        // Verifica se a data final < data inicial
        if ((dqFinal.iAno < dqInicial.iAno) ||
            (dqFinal.iAno == dqInicial.iAno && dqFinal.iMes < dqInicial.iMes) ||
            (dqFinal.iAno == dqInicial.iAno && dqFinal.iMes == dqInicial.iMes && dqFinal.iDia < dqInicial.iDia)) {
            dma.retorno = 4; // Retorno 4 -> data final < inicial
            return dma;
        }

        //calcule a distancia entre as datas
        dma.qtdAnos = dqFinal.iAno - dqInicial.iAno;
        dma.qtdMeses = dqFinal.iMes - dqInicial.iMes;
        dma.qtdDias = dqFinal.iDia - dqInicial.iDia;

        // Ajuste se os dias forem negativos
        if (dma.qtdDias < 0) {
            dma.qtdMeses--; // Subtrai um mês

            // Adiciona os dias do mês anterior à data final
            dma.qtdDias += diasNoMes(dqFinal.iMes - 1, dqFinal.iAno); 

            // Se o mês anterior for janeiro, ajusta para dezembro do ano anterior
            if (dqFinal.iMes == 1) {
                dma.qtdDias += diasNoMes(12, dqFinal.iAno - 1);
            }
        }

        // Ajuste se os meses forem negativos
        if (dma.qtdMeses < 0) {
            dma.qtdAnos--; 
            dma.qtdMeses += 12; 
        }
        
        //se tudo der certo
        dma.retorno = 1; 
        return dma;
    }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
    int qtdOcorrencias = 0;

    if (strlen(texto) > 250) {
        return 0;
    }

    // Converter o caractere de busca, se necessário
    if (!isCaseSensitive) {
        c = paraMinusculo(removeAcento(c));
    }

    for (int i = 0; texto[i] != '\0'; i++) {
        char atualChar = texto[i];

        if (!isCaseSensitive) {
            atualChar = paraMinusculo(removeAcento(atualChar));
        }

        if (atualChar == c) {
            qtdOcorrencias++;
        }
    }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. 
    Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido 
    com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de 
    fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas 
    posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", 
    e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se 
    armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
    Observe que o índice da posição no texto deve começar ser contado a partir de 1.
    O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    char *ptr = strTexto;
    int buscaLen = strlen(strBusca);

    if (strlen(strTexto) > 250) {
        return 0;
    }

    while ((ptr = strstr(ptr, strBusca)) != NULL) {
        // Calcular as posições de início e fim baseadas em 1
        posicoes[qtdOcorrencias * 2] = (ptr - strTexto) + 1;
        posicoes[qtdOcorrencias * 2 + 1] = (ptr - strTexto) + buscaLen;

        qtdOcorrencias++;
        ptr += buscaLen;  // Avançar o ponteiro para continuar a busca
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */
int q5(int num)
{
    int invertido = 0;
    int negativo = 0;

    // Caso negativo
    if (num < 0) {
        negativo = 1; // Número original negativo
        num = -num;  
    }

    // Inverter o número
    while (num > 0) {
        invertido = invertido * 10 + (num % 10); // Extrai o último dígito e inverte
        num /= 10; // Remove o último dígito do número original
    }

    // Volta o sinal se o número original era negativo
    if (negativo) {
        invertido = -invertido;
    }

    return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int auxBase, auxBusca;

    // Determina o valor do multiplicador para igualar o número de dígitos do número de busca
    int multiplicador = 1;
    while (numerobusca / multiplicador >= 10) {
        multiplicador *= 10;
    }

    // Percorre todos os dígitos de numerobase
    while (numerobase > 0) {
        auxBase = numerobase; // Armazena o valor atual de numerobase
        auxBusca = numerobusca;
        int var = 1; // Inicializa var como verdadeiro, se var = 0 significa que não tem correspondência

        // Enquanto houver dígitos em numerobusca...
        while (auxBusca > 0) {

            if (auxBase == 0) {
                var = 0; 
                break;
            }
            // Compara o último dígito de auxBase e auxBusca
            if (auxBase % 10 != auxBusca % 10) {
                var = 0; 
                break;
            }
            auxBase /= 10; // Remove o último dígito de numerobase
            auxBusca /= 10; // Remove o último dígito de numerobusca
        }
        // Se encontrar uma correspondência, aumenta a quantidade de ocorrências
        if (var && auxBusca == 0) {
            qtdOcorrencias++;

            // Avança duas casas
            numerobase /= multiplicador * 10;
        } else {
            // Remove apenas um dígito
            numerobase /= 10;
        }
    }
    return qtdOcorrencias;
}


//FUNÇÕES PARA RESOLUÇÃO DE QUESTÕES
DataQuebrada quebraData(char data[]) {
    DataQuebrada dq;
    dq.valido = 1; // Define como válido por padrão

    char sDia[3], sMes[3], sAno[5];
    int i = 0, j = 0;

    // Extrai o dia
    for (i = 0; data[i] != '/' && data[i] != '\0'; i++) {
        sDia[i] = data[i];
    }
    sDia[i] = '\0';

    if (i != 1 && i != 2) {
        dq.valido = 0;
        return dq;
    }

    // Extrai o mês
    i++;
    for (j = 0; data[i] != '/' && data[i] != '\0'; i++, j++) {
        sMes[j] = data[i];
    }
    sMes[j] = '\0';

    if (j != 1 && j != 2) {
        dq.valido = 0;
        return dq;
    }

    // Extrai o ano
    i++;
    for (j = 0; data[i] != '\0'; i++, j++) {
        sAno[j] = data[i];
    }
    sAno[j] = '\0';

    if (j != 2 && j != 4) {
        dq.valido = 0;
        return dq;
    }

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);

	dq.valido = 1;
    
  return dq;
}

int ehBissexto(int ano) {
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

int validaDiaMesAno(int dia, int mes, int ano) {
    if (dia < 1 || dia > 31) return 0; // Dias fora do intervalo 1-31

    // Dias máximos por mês, ajustando para fevereiro bissexto
    int diasNoMes[] = {31, ehBissexto(ano) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    return dia <= diasNoMes[mes - 1];
}

int diasNoMes(int mes, int ano) {
    if (mes < 1 || mes > 12) {
        return 0; // Mês inválido
    }
    
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
                return 29; // Ano bissexto
            } else {
                return 28;
            }
        default:
            return 0;
    }
}

//Q3
char removeAcento(char c) {
    // Lista manual de substituições
    char acentuados[] = "ÀÁÂÃÄÅàáâãäåÈÉÊËèéêëÌÍÎÏìíîïÒÓÔÕÖØòóôõöøÙÚÛÜùúûü";
    char semAcento[] = "AAAAAAaaaaaaEEEEeeeeIIIIiiiiOOOOOOooooooUUUUuuuu";

    for (int i = 0; acentuados[i] != '\0'; i++) {
        if (c == acentuados[i]) {
            return semAcento[i];
        }
    }
    return c; // Retorna o caractere original se não estiver na lista
}

char paraMinusculo(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}