#include <stdio.h>

/* 34) Escreva, usando a linguagem C, uma função recursiva, ImprimeSerie(i,j,k: inteiro), 
que imprime na tela a série de valores do intervalo [i,j], com incremento k.  */

void imprimeSerie(int i, int j, int k) {
    if (i > j) { 
        return; // Caso base: se i ultrapassar j, a função para
    }
    
    printf("%d ", i); // Imprime o valor atual
    imprimeSerie(i + k, j, k); // Chamada recursiva com incremento
}

int main() {
    int i, j, k;
    
    printf("Digite os valores de i, j e k: ");
    scanf("%d %d %d", &i, &j, &k);

    if (k > 0 && i <= j) {
        printf("Série: ");
        imprimeSerie(i, j, k);
        printf("\n");
    } else {
        printf("Erro! Certifique-se de que i ≤ j e k > 0.\n");
    }

    return 0;
}
