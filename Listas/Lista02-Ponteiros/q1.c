/*
QUESTÃO 01:
Crie um programa que defina variáveis do tipo int, char, string [10 posições], float, double. 
Deve ser definido também uma variável ponteiro para cada um dos tipos acima. Faça leituras (scanf) e 
escrita (printf) das variáveis primitivas e depois faça o mesmo utilizando ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    char b;
    char c[10];
    float d;
    double e;

    int *pA  = &a;
    char *pB = &b;
    char *pC = c;  //Para strings, o nome do array já é o endereço do primeiro caractere (não precisa colocar "&"), tal como para um vetor de inteiros.
    float *pD = &d;
    double *pE = &e;

    //Printf e scanf dos tipos primitivos
    printf("int: ");
    scanf("%d", &a);

    printf("char: ");
    scanf(" %c", &b);

    printf("string[10-1]: ");
    scanf("%9s", c);

    printf("float: ");
    scanf("%f", &d);

    printf("double: ");
    scanf("%lf", &e);

    printf("\nPrintf primitivo e conteúdo do ponteiro:\n");

    printf("int: %d", a);
    printf("\nint: %d", *pA);

    printf("\nchar: %c", b);
    printf("\nchar: %c", *pB);

    printf("\nstring[10-1]: %s", c);
    printf("\nstring[10-1]: %s", pC);

    printf("\nfloat: %f", d);
    printf("\nfloat: %f", *pD);

    printf("\ndouble: %lf", e);
    printf("\ndouble: %lf", *pE);

    printf("\n");
}
