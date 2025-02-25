#include <stdio.h>

void imprimirPares(int n) {
    if (n < 0) { 
        return; 
    }

    imprimirPares(n - 2); // Chamada recursiva primeiro para manter a ordem crescente

    printf("%d ", n); // Imprime apenas depois da recursão
}

int main() {
    int n;
    printf("Digite um número inteiro positivo par: ");
    scanf("%d", &n);

    if (n >= 0 && n % 2 == 0) {
        imprimirPares(n);
    } else {
        printf("Número inválido! Digite um número par.\n");
    }

    return 0;
}
