#include <stdio.h>
#include <stdlib.h>

/* Questão 01:

Ana e suas amigas estão fazendo um trabalho de geometria para o colégio, em que precisam 
formar vários triângulos, numa cartolina, com algumas varetas de comprimentos diferentes. 
Logo elas perceberam que não dá para formar triângulos com três varetas de comprimentos 
quaisquer. Se uma das varetas for muito grande em relação às outras duas, não dá para formar 
o triângulo. Ana fez uma pesquisa na internet e aprendeu que com três varetas é possível 
formar um triângulo quando, para todas as varetas, vale a seguinte relação: o comprimento 
da vareta é menor do que a soma dos comprimentos das outras duas varetas. Por exemplo, 
se os comprimentos forem 6, 9 e 5, vai dar para formar o triângulo, pois a relação vale 
para as três varetas: 6 < 9 + 5, 9 < 6 + 5 e 5 < 6 + 9. Mas, se os comprimentos forem, 
por exemplo, 4, 10 e 3, não vai dar para formar um triângulo, porque a relação não vale 
para uma das varetas (pois 10 não é menor do que 3 + 4). 

Entrada: A entrada é composta por apenas uma linha contendo quatro números inteiros separados 
por traços. Saída: Caso a entrada seja válida, seu programa deve produzir uma linha contendo 
o caractere ‘S’, caso seja possível formar o triângulo; ou o caractere ‘N’, caso não seja 
possível formar o triângulo. Caso a entrada seja inválida, por algum motivo, ele deve informar 
ao usuário: Entrada Inválida. 
Restrições: 
a) O valor dos quatro números está entre 1 e 100; 
b) Não pode ter variável global; 
c) A única função que deve fazer print é a função main; 
d) A entrada de dados deve ser obrigatoriamente feita com uma leitura de uma única string. 
Não pode ser feito uso do scanf com caracteres especiais para separar os traços. 

Seu programa deve ter no mínimo as seguintes funções: 
- Função que monta o menu de opções, com as seguintes opções: 
1. Verificar varetas; 
2. Imprimir três varetas que forma triângulo. 
3. Sair. 

- Função validaEntrada. Esta função deve receber como parâmetro a entrada (String), e retornar 
de alguma forma a informação se é válido ou não. Se for válido, essa função deve retornar, de 
alguma forma, os 4 valores inteiros informados pelo usuário. Na função main, deve ser impresso, 
entrada válida ou entrada inválida.  

- Função verificaVaretas. Esta função recebe quatro números (das varetas) e informa se é 
possível ou não formar um triângulo. Se for, deve retornar, de alguma forma três valores 
possíveis para as varetas. Não deve imprimir os valores. Isso será feito quando o usuário 
selecionar a opção 2 do menu. Função imprimeVaretas, essa função deve imprimir as três 
varetas que formam o triângulo. Ela só deve ser chamada se existir essas três varetas. 
Se não existir, o usuário deve ser informado: entrada inválida ou não existe varetas que 
formam um triângulo. Ao digitar a opção 1 do menu, o programa deve chamar validaEntrada. 
Se a entrada for válida, chamar a opção verificaVaretas.  

*/

#define TAM 50

int opcoesMenu() {
    int opcao;
    printf("Insira a opção desejada:\n");
    printf("1. Verificar varetas\n");
    printf("2. Imprimir 3 varetas que formam um triângulo\n");
    printf("3. Sair\n");

    scanf("%d", &opcao);
    getchar(); // Limpa o buffer
    
    return opcao;
}

int ehDigito(char c) {
    return c >= '0' && c <= '9';
}

int validaEntrada(char entrada[], int vetor[]) {
    int i = 0, j = 0, numero = 0, qtdNumeros = 0;

    // Processa a string de entrada
    while (entrada[i] != '\0' && entrada[i] != '\n') {
        if (ehDigito(entrada[i])) {
            numero = numero * 10 + (entrada[i] - '0');
        } else if (entrada[i] == '-') {
            if (numero > 0 && numero <= 100) {
                vetor[j++] = numero;
                numero = 0;
                qtdNumeros++;
            } else {
                return 0; // Número fora do intervalo ou inválido
            }
        } else {
            return 0; // Caractere inválido
        }
        i++;
    }

    // Adiciona o último número
    if (numero > 0 && numero <= 100) {
        vetor[j++] = numero;
        qtdNumeros++;
    }

    return (qtdNumeros == 4); // Valida se há exatamente 4 números
}

int verificarVaretas(int vetor[], int resultado[]) {
    // Verifica todos os trios possíveis para formar um triângulo
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (vetor[i] < vetor[j] + vetor[k] &&
                    vetor[j] < vetor[i] + vetor[k] &&
                    vetor[k] < vetor[i] + vetor[j]) {
                    resultado[0] = vetor[i];
                    resultado[1] = vetor[j];
                    resultado[2] = vetor[k];
                    return 1; // Triângulo encontrado
                }
            }
        }
    }
    return 0; // Nenhum triângulo possível
}

void imprimeVaretas(int resultado[]) {
    printf("Conjunto de varetas que formam um triângulo: {%d, %d, %d}\n", 
           resultado[0], resultado[1], resultado[2]);
}

int main() {
    char varetas[TAM];
    int vetor[4] = {-1, -1, -1, -1};
    int vetorResultado[3] = {-1, -1, -1};

    while (1) {
        int opcao = opcoesMenu();

        if (opcao == 3) {
            return 0;
        }

        if (opcao == 1) {
            printf("Tamanho varetas (xxx-xxx-xxx-xxx): ");
            fgets(varetas, sizeof(varetas), stdin);

            if (!validaEntrada(varetas, vetor)) {
                printf("Entrada inválida!\n");
            } else {
                if (verificarVaretas(vetor, vetorResultado)) {
                    printf("Entrada válida. Triângulo possível!\n");
                } else {
                    printf("Entrada válida. Não é possível formar um triângulo.\n");
                }
            }
        }

        if (opcao == 2) {
            if (vetorResultado[0] != -1) {
                imprimeVaretas(vetorResultado);
            } else {
                printf("Não existe um conjunto de varetas que formam um triângulo.\n");
            }
        }
    }
}
