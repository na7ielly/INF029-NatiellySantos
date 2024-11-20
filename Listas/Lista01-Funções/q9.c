/*
QUESTÃO 09:
Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. 
Cada validação deve ser feita em uma função diferente, conforme lista abaixo. A função 
cadastrarCliente deve chamar cada uma dessas funções. A função main deve imprimir se o 
cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:

* função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
* função validarSexo: recebe o sexo digitado, e valida é um sexo válido 
(opções: m e M para masculino; f e F para feminino, o e O para outro).
* função validarCPF: recebe o cpf digitado, e valida se é um cpf válido;
* função validarNacimento: recebe a data digitada, e valida se é uma data válida.

*/

#include "prototipos.h"
#include "constantes.h"

Cliente cadastrarCliente() {
    Cliente cliente;
    int validaCadastro = 1;

    printf("Nome: ");
    scanf("%s", cliente.nome);

    if (!validarNome(cliente.nome)) {
        validaCadastro = 0;
    }

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &cliente.dataNascimento.dia, &cliente.dataNascimento.mes, &cliente.dataNascimento.ano);

    if (!validarNascimento(cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano)) {
        validaCadastro = 0;
    }

    printf("CPF (apenas números): ");
    scanf("%s", cliente.cpf);

    if (!validarCPF(cliente.cpf)) {
        validaCadastro = 0;
    }

    printf("Sexo (M/F/O): ");
    scanf(" %c", &cliente.sexo);  // Inclui um espaço antes para capturar corretamente

    if (!validarSexo(cliente.sexo)) {
        validaCadastro = 0;
    }

    if (validaCadastro == 1) {
        printf("Cadastro foi realizado com sucesso.\n");
    } else {
        printf("Cadastro não realizado.\nMotivos:\n");
        if (!validarNome(cliente.nome)) {
            printf(" - Nome inválido\n");
        }
        if (!validarNascimento(cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano)) {
            printf(" - Data de nascimento inválida\n");
        }
        if (!validarCPF(cliente.cpf)) {
            printf(" - CPF inválido\n");
        }
        if (!validarSexo(cliente.sexo)) {
            printf(" - Sexo inválido\n");
        }
    }

    return cliente;
}

int main() {
    Cliente cliente = cadastrarCliente();

    printf("Nome: %s\n", cliente.nome);
    printf("Data de nascimento: %02d/%02d/%04d\n", cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano);
    printf("CPF: %s\n", cliente.cpf);
    printf("Sexo: %c\n", cliente.sexo);

    return 0;
}

int validarNome(char nome[MAXNOME]) {
    if (strlen(nome) > MAXNOME) {
        return 0;
    }
    return 1;
}

int validarSexo(char sexo) {
    if (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f' && sexo != 'O' && sexo != 'o') {
        return 0;
    }
    return 1;
}

int validarCPF(char cpf[MAXCPF]) {
    if ((strlen(cpf) > MAXCPF) || (strlen(cpf) < MAXCPF)) {
        return 0;
    }
    return 1;
}

int validarNascimento(int dia, int mes, int ano) {
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano > 0)) {
        return 1;
    }
    return 0;
}