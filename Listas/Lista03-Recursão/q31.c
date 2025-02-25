#include <stdio.h>

int somaSerie(int i, int j, int k) {
    if (i > j) { 
        return 0; // Caso base: se i ultrapassar j, a soma termina
    }
    return i + somaSerie(i + k, j, k); // Soma i e chama recursivamente com incremento k
}

int main() {
    int i, j, k;
    
    printf("Digite os valores de i, j e k: ");
    scanf("%d %d %d", &i, &j, &k);

    if (k > 0 && i <= j) {
        printf("A soma da série é: %d\n", somaSerie(i, j, k));
    } else {
        printf("Erro! Certifique-se de que i ≤ j e k > 0.\n");
    }

    return 0;
}
