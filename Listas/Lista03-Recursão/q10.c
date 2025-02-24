#include <stdio.h>

// 10) Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um número natural N. 
// Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.

int contaDigitos(int n, int k) {
    if (n == 0){ 
        return 0;
    }
    
    if (n % 10 == k){ // Verifica o último dígito
        return 1 + contaDigitos(n / 10, k); // Se for igual a k, soma 1 e chama a função novamente para o resto do número
    }
    
    return contaDigitos(n / 10, k); // Se for diferente, apenas chama a função novamente para o resto do número sem somar
}