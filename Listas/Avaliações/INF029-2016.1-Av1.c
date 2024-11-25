#include <stdio.h>
#define TAM 100

int qtdBuracosEmLetra(char c) {
    if (c == 'A' || c == 'D' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || 
        c == 'a' || c == 'b' || c == 'd' || c == 'e' || c == 'g' || c == 'o' || 
        c == 'p' || c == 'q') {
        return 1;
    }
    if (c == 'B') {
        return 2;
    }
    return 0;  // Todas as outras letras não têm buracos
}

int qtdBuracosEmTexto(char string[]) {
    int totalBuracos = 0, i = 0;

    while (string[i] != '\0') {
        totalBuracos += qtdBuracosEmLetra(string[i]);
        i++;
    }
    return totalBuracos;
}

int calcularTamanho(char string[]) {
    int tamanho = 0;
    while (string[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

void removerNovaLinha(char string[]) {
    int tamanho = calcularTamanho(string);
    if (tamanho > 0 && string[tamanho - 1] == '\n') {
        string[tamanho - 1] = '\0';
    }
}

int main() {
    char string[TAM];

    printf("Digite o texto: ");
    fgets(string, sizeof(string), stdin);

    // Remover o '\n' se presente
    removerNovaLinha(string);

    int totalBuracos = qtdBuracosEmTexto(string);
    printf("Total de buracos: %d\n", totalBuracos);

    return 0;
}