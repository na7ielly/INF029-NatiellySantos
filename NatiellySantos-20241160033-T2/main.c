#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"
#define ARQUIVO_DADOS "dados.txt"

int menu();
void salvarDados();
void carregarDados();

int main()
{
    inicializar();
    carregarDados(); // Carrega os dados salvos, se existirem

    int op;
    int sair = 0;
    while (!sair)
    {
        op = menu();
        switch (op)
        {
        case 0:
            salvarDados(); // Salva os dados antes de sair
            finalizar();
            sair = 1;
            break;

        case 1: 
        { 
            // Criar estrutura auxiliar
            int posicao, tamanho, ret;
            printf("Digite a posição da estrutura auxiliar (1..10): ");
            scanf("%d", &posicao);

            printf("Digite o tamanho da estrutura auxiliar: ");
            scanf("%d", &tamanho);

            ret = criarEstruturaAuxiliar(posicao, tamanho);
            if (ret == SUCESSO) 
                printf("Estrutura criada com sucesso.\n");
            else if (ret == JA_TEM_ESTRUTURA_AUXILIAR) 
                printf("Já existe uma estrutura auxiliar nessa posição.\n");
            else if (ret == POSICAO_INVALIDA) 
                printf("Posição inválida.\n");
            else if (ret == TAMANHO_INVALIDO) 
                printf("Tamanho inválido.\n");
            else if (ret == SEM_ESPACO_DE_MEMORIA) 
                printf("Erro de memória.\n");
            break;
        }

        case 2: 
        { 
            // Inserir número na estrutura auxiliar
            int posicao, valor, ret;
            printf("Digite a posição da estrutura auxiliar (1..10): ");
            scanf("%d", &posicao);

            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);

            ret = inserirNumeroEmEstrutura(posicao, valor);
            if (ret == SUCESSO) 
                printf("Valor inserido com sucesso.\n");
            else if (ret == SEM_ESPACO) 
                printf("Sem espaço na estrutura auxiliar.\n");
            else if (ret == SEM_ESTRUTURA_AUXILIAR) 
                printf("Estrutura auxiliar inexistente.\n");
            else if (ret == POSICAO_INVALIDA) 
                printf("Posição inválida.\n");
            break;
        }

        case 3:
            listarTodasAsEstruturas();
            break;

        case 4:
            listarEstruturasOrdenadas();
            break;

        case 5:
            listarTodosNumerosOrdenados();
            break;

        case 6: 
        { 
            // Excluir um número específico
            int posicao, valor, ret;
            printf("Digite a posição da estrutura auxiliar (1..10): ");
            scanf("%d", &posicao);

            printf("Digite o número a ser excluído: ");
            scanf("%d", &valor);

            ret = excluirNumeroEspecificoDeEstrutura(posicao, valor);
            if (ret == SUCESSO) 
                printf("Número excluído com sucesso.\n");
            else if (ret == POSICAO_INVALIDA) 
                printf("Posição inválida.\n");
            else if (ret == SEM_ESTRUTURA_AUXILIAR) 
                printf("Sem estrutura auxiliar na posição especificada.\n");
            else if (ret == ESTRUTURA_AUXILIAR_VAZIA) 
                printf("Estrutura auxiliar vazia.\n");
            else if (ret == NUMERO_INEXISTENTE) 
                printf("Número não encontrado na estrutura.\n");
            break;
        }

        case 7:
        { 
            // Aumentar tamanho de uma estrutura auxiliar
            int posicao, tamanhoExtra, ret;
            printf("Digite a posição da estrutura auxiliar (1..10): ");
            scanf("%d", &posicao);

            printf("Digite o tamanho extra para aumentar a estrutura: ");
            scanf("%d", &tamanhoExtra);

            ret = modificarTamanhoEstruturaAuxiliar(posicao, tamanhoExtra);
            if (ret == SUCESSO) 
                printf("Tamanho da estrutura auxiliar aumentado com sucesso.\n");
            else if (ret == POSICAO_INVALIDA) 
                printf("Posição inválida.\n");
            else if (ret == SEM_ESTRUTURA_AUXILIAR) 
                printf("Sem estrutura auxiliar na posição especificada.\n");
            else if (ret == NOVO_TAMANHO_INVALIDO) 
                printf("Tamanho inválido. O tamanho total deve ser >= 1.\n");
            else if (ret == SEM_ESPACO_DE_MEMORIA) 
                printf("Erro de memória ao tentar aumentar o tamanho.\n");
            break;
        }

        case 8:
            salvarDados();
            break;

        default:
            printf("Opção inválida!\n");
        }
    }
    return 0;
}

int menu() {
    int op;
    printf("\n===== MENU =====\n");
    printf("0 - Sair\n");
    printf("1 - Criar estrutura auxiliar\n");
    printf("2 - Inserir número na estrutura auxiliar\n");
    printf("3 - Listar todas as estruturas\n");
    printf("4 - Listar os números ordenados para cada estrutura auxiliar\n");
    printf("5 - Listar todos os números de forma ordenada\n");
    printf("6 - Excluir um número específico\n");
    printf("7 - Aumentar tamanho de uma estrutura auxiliar\n");
    printf("8 - Salvar dados\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

void salvarDados() {
    FILE *file = fopen(ARQUIVO_DADOS, "w");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para salvar dados.\n");
        return;
    }

    for (int i = 1; i <= 10; i++) {
        int qtd = getQuantidadeElementosEstruturaAuxiliar(i);
        if (qtd > 0) {
            int vetorAux[qtd];
            if (getDadosEstruturaAuxiliar(i, vetorAux) == SUCESSO) {
                fprintf(file, "%d %d ", i, qtd);
                for (int j = 0; j < qtd; j++) {
                    fprintf(file, "%d ", vetorAux[j]);
                }
                fprintf(file, "\n");
            }
        }
    }

    fclose(file);
    printf("Dados salvos com sucesso.\n");
}

void carregarDados() {
    FILE *file = fopen(ARQUIVO_DADOS, "r");
    if (file == NULL) {
        printf("Nenhum dado anterior encontrado.\n");
        return;
    }

    int posicao, qtd, valor;
    while (fscanf(file, "%d %d", &posicao, &qtd) == 2) {
        criarEstruturaAuxiliar(posicao, qtd);
        for (int i = 0; i < qtd; i++) {
            fscanf(file, "%d", &valor);
            inserirNumeroEmEstrutura(posicao, valor);
        }
    }

    fclose(file);
    printf("Dados carregados com sucesso.\n");
}
