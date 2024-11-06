/*
QUESTÃO 08:
Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler
os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados 
cliente. A função main deve imprimir os dados do cliente.
*/

#include <stdio.h>
#include "prototipos.h"

Cliente cadastrarCliente() {
    Cliente cliente;

    printf("Nome: ");
    scanf("%s", cliente.nome);

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &cliente.dataNascimento.dia, &cliente.dataNascimento.mes, &cliente.dataNascimento.ano);

    printf("CPF (apenas números): ");
    scanf("%s", cliente.cpf);  // CPF como string

    printf("Sexo (M/F): ");
    scanf(" %c", &cliente.sexo);  // Inclui um espaço antes para capturar corretamente

    return cliente;
}

int main() {
    Cliente cliente = cadastrarCliente();

    printf("Nome: %s\n", cliente.nome);
    printf("Data de nascimento: %02d/%02d/%04d\n", cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano);
    printf("CPF: %s\n", cliente.cpf);  // Imprime o CPF como string
    printf("Sexo: %c\n", cliente.sexo);

    return 0;
}
