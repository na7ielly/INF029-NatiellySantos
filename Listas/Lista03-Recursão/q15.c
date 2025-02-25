#include <stdio.h>

// 15) Faça uma função recursiva que receba um número inteiro positivo par N e imprima todos
// os números pares de 0 até N em ordem decrescente. 

#include <stdio.h>

void imprimirPares(int n) {
    if (n < 0) { 
        return; 
    }

    printf("%d ", n); // Primeiro imprime o número para manter a ordem decrescente
    imprimirPares(n - 2); // Depois chama a recursão para o próximo número par menor
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
