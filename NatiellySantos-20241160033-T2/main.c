#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();

void dobrar(int *x);

int menu() {
    int op;
    printf("Digite a opção desejada:\n");
    printf("0 - Sair\n");
    printf("1 - Criar estrutura auxiliar\n");
    printf("2 - Inserir número na estrutura auxiliar\n");
    printf("3 - Listar todas as estruturas\n");
    printf("4 - Listar os números ordenados para cada estrutura auxiliar\n");
    printf("5 - Listar todos os números de forma ordenada\n");
    printf("6 - Excluir um número específico\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    inicializar();
    int op;
    int sair = 0;
    int ret;
    while (!sair)
    {
        op = menu();
        switch (op)
        {
        case 0:
        {
            sair = 1;
            finalizar();
            break;
        }
        case 1: 
        { // Criar estrutura auxiliar
            int posicao, tamanho, ret;

            printf("Digite a posição da estrutura auxiliar (1..10): ");
            scanf("%d", &posicao);

            printf("Digite o tamanho da estrutura auxiliar: ");
            scanf("%d", &tamanho);

            ret = criarEstruturaAuxiliar(posicao, tamanho);

            if (ret == SUCESSO) {
                printf("Estrutura criada com sucesso.\n");
            } else if (ret == JA_TEM_ESTRUTURA_AUXILIAR) {
                printf("Já existe uma estrutura auxiliar nessa posição.\n");
            } else if (ret == POSICAO_INVALIDA) {
                printf("Posição inválida.\n");
            } else if (ret == TAMANHO_INVALIDO) {
                printf("Tamanho inválido.\n");
            } else if (ret == SEM_ESPACO_DE_MEMORIA) {
                printf("Erro de memória.\n");
            }
            break;
        }

        case 2: 
        { // Inserir número na estrutura auxiliar
            int posicao, valor, ret;

            printf("Digite a posição da estrutura auxiliar (1..10): ");
            scanf("%d", &posicao);

            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);

            ret = inserirNumeroEmEstrutura(posicao, valor);
            if (ret == SUCESSO) {
                printf("Valor inserido com sucesso.\n");
            } else if (ret == SEM_ESPACO) {
                printf("Sem espaço na estrutura auxiliar.\n");
            } else if (ret == SEM_ESTRUTURA_AUXILIAR) {
                printf("Estrutura auxiliar inexistente.\n");
            } else if (ret == POSICAO_INVALIDA) {
                printf("Posição inválida.\n");
            }
            break;
        }

        case 3:
        { // Listar todas as estruturas
            listarTodasAsEstruturas();
            break;
        }

        case 4:
        { // Listar os números ordenados para cada estrutura auxiliar
            listarEstruturasOrdenadas();
            break;
        }

        case 5:
        { // Listar todos os números de forma ordenada
            listarTodosNumerosOrdenados();
            break;
        }

        case 6: 
        { // Excluir um número específico
            int posicao, valor, ret;

            printf("Digite a posição da estrutura auxiliar (1..10): ");
            scanf("%d", &posicao);

            printf("Digite o número a ser excluído: ");
            scanf("%d", &valor);

            ret = excluirNumeroEspecificoDeEstrutura(posicao, valor);

            if (ret == SUCESSO) {
                printf("Número excluído com sucesso.\n");
            } else if (ret == POSICAO_INVALIDA) {
                printf("Posição inválida.\n");
            } else if (ret == SEM_ESTRUTURA_AUXILIAR) {
                printf("Sem estrutura auxiliar na posição especificada.\n");
            } else if (ret == ESTRUTURA_AUXILIAR_VAZIA) {
                printf("Estrutura auxiliar vazia.\n");
            } else if (ret == NUMERO_INEXISTENTE) {
                printf("Número não encontrado na estrutura.\n");
            }

            break;
        }

        case 10:
        { //recuperar dados estrutura auxiliar
            int posicao, retorno;
            printf("Qual a estrutura a ser listada (1..10)?");
            scanf("%d", &posicao);

            int qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

            if (qtd == POSICAO_INVALIDA)
            {
                printf("Posição inválida");
            }
            else
            { // existe elemento
                int vetorAux[qtd];

                retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

                if (retorno == SUCESSO)
                {
                    //imprimir para os dados para o usuário
                    int i = 0;
                    for (int i = 0; i < qtd; i++) {
                        printf("%d ", vetorAux[i]); // Adicionando espaço entre números
                    }
                    printf("\n");
                }
            }
            break;
        }

        default:
        {
            printf("opcao inválida\n");
        }
        }
    }

    return 0;
}