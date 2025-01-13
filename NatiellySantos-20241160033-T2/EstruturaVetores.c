#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

// Função de comparação para o qsort
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/*Objetivo: 
Criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

// Estrutura auxiliar
typedef struct 
{
    int *valores;
    int tamanho;
    int ocupados;
} EstruturaAuxiliar;

EstruturaAuxiliar *vetorPrincipal[TAM];

/* Objetivo: 
Inicializa o programa. deve ser chamado ao inicio do programa 
*/

// Função para inicializar as estruturas auxiliares
void inicializar() 
{
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i] = NULL;
    }
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int indice = posicao - 1;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[indice] != NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    if (tamanho < 1){
        return TAMANHO_INVALIDO;
    }

    vetorPrincipal[indice] = (EstruturaAuxiliar *)malloc(sizeof(EstruturaAuxiliar));

    if (!vetorPrincipal[indice]){
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[indice]->valores = (int *)malloc(tamanho * sizeof(int));

    if (!vetorPrincipal[indice]->valores) {
        free(vetorPrincipal[indice]);
        vetorPrincipal[indice] = NULL;
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[indice]->tamanho = tamanho;
    vetorPrincipal[indice]->ocupados = 0;
    return SUCESSO;
}

/* Objetivo: 
Inserir número 'valor' em estrutura auxiliar da posição 'posicao'

Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/

int inserirNumeroEmEstrutura(int posicao, int valor) {
    int retorno = 0;

    // Verifica se a posição é válida
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    // Verifica se a estrutura auxiliar já existe
    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR; // Sem criar dinamicamente
    }

    // Verifica se há espaço disponível na estrutura auxiliar
    if (vetorPrincipal[indice]->ocupados >= vetorPrincipal[indice]->tamanho) {
        return SEM_ESPACO;
    }

    // Insere o valor na estrutura auxiliar
    vetorPrincipal[indice]->valores[vetorPrincipal[indice]->ocupados++] = valor;
    return SUCESSO;
}

void listarTodasAsEstruturas() {
    for (int i = 0; i < TAM; i++) {
        printf("Posição %d:\n", i + 1);
        if (vetorPrincipal[i] == NULL) {
            printf("  Sem estrutura auxiliar.\n");
        } else {
            printf("  Tamanho total: %d\n", vetorPrincipal[i]->tamanho);
            printf("  Elementos ocupados: %d\n", vetorPrincipal[i]->ocupados);
            if (vetorPrincipal[i]->ocupados > 0) {
                printf("  Elementos: ");
                for (int j = 0; j < vetorPrincipal[i]->ocupados; j++) {
                    printf("%d ", vetorPrincipal[i]->valores[j]);
                }
                printf("\n");
            } else {
                printf("  Estrutura auxiliar vazia.\n");
            }
        }
    }
}

void listarEstruturasOrdenadas() {
    for (int i = 0; i < TAM; i++) {
        printf("Posição %d:\n", i + 1);
        if (vetorPrincipal[i] == NULL) {
            printf("  Sem estrutura auxiliar.\n");
        } else if (vetorPrincipal[i]->ocupados == 0) {
            printf("  Estrutura auxiliar vazia.\n");
        } else {
            int qtd = vetorPrincipal[i]->ocupados;
            int vetorAux[qtd];

            // Copia os elementos para ordenação
            for (int j = 0; j < qtd; j++) {
                vetorAux[j] = vetorPrincipal[i]->valores[j];
            }

            // Ordena os elementos
            qsort(vetorAux, qtd, sizeof(int), comparar);

            printf("  Elementos ordenados: ");
            for (int j = 0; j < qtd; j++) {
                printf("%d ", vetorAux[j]);
            }
            printf("\n");
        }
    }
}

void listarTodosNumerosOrdenados() {
    int totalNumeros = 0;
    int vetorAux[1000]; // Supondo um limite máximo de números

    // Copia todos os números das estruturas auxiliares para o vetor auxiliar
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->ocupados > 0) {
            for (int j = 0; j < vetorPrincipal[i]->ocupados; j++) {
                vetorAux[totalNumeros++] = vetorPrincipal[i]->valores[j];
            }
        }
    }

    if (totalNumeros == 0) {
        printf("Nenhum número encontrado em todas as estruturas auxiliares.\n");
        return;
    }

    // Ordena todos os números
    qsort(vetorAux, totalNumeros, sizeof(int), comparar);

    printf("Todos os números ordenados: ");
    for (int i = 0; i < totalNumeros; i++) {
        printf("%d ", vetorAux[i]);
    }
    printf("\n");
}

/* Objetivo: 
Excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int indice = posicao - 1;
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[indice] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[indice]->ocupados == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    vetorPrincipal[indice]->ocupados--;

    // Zerando o último valor para evitar lixo de memória
    vetorPrincipal[indice]->valores[vetorPrincipal[indice]->ocupados] = 0;
    return SUCESSO;
}

/* Objetivo: 
Excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    int indice = posicao - 1;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[indice]->ocupados == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    int encontrado = 0;
    for (int i = 0; i < vetorPrincipal[indice]->ocupados; i++) {
        if (vetorPrincipal[indice]->valores[i] == valor) {
            encontrado = 1;

            // Mover os números seguintes para "fechar o espaço"
            for (int j = i; j < vetorPrincipal[indice]->ocupados - 1; j++) {
                vetorPrincipal[indice]->valores[j] = vetorPrincipal[indice]->valores[j + 1];
            }

            vetorPrincipal[indice]->ocupados--; // Atualizar contador de elementos
            vetorPrincipal[indice]->valores[vetorPrincipal[indice]->ocupados] = 0; // Evitar lixo

            break; // Interromper após encontrar a primeira ocorrência
        }
    }

    if (!encontrado) {
        return NUMERO_INEXISTENTE;
    }

    return SUCESSO;
}

/* Objetivo: 
Retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int indice = posicao - 1;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    // Certifique-se de que não acessa além do limite
    for (int i = 0; i < vetorPrincipal[indice]->ocupados; i++) {
        vetorAux[i] = vetorPrincipal[indice]->valores[i];
    }

    return SUCESSO;
}

/* Objetivo: 
Retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int totalNumeros = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->ocupados > 0) {
            for (int j = 0; j < vetorPrincipal[i]->ocupados; j++) {
                vetorAux[totalNumeros++] = vetorPrincipal[i]->valores[j];
            }
        }
    }

    if (totalNumeros == 0) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    return SUCESSO;
}


/* Objetivo: 
Retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int totalNumeros = 0;

    // Percorre todas as posições do vetor principal
    for (int i = 0; i < TAM; i++) {
        // Verifica se há uma estrutura auxiliar válida e com elementos
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->ocupados > 0) {
            // Copia os números da estrutura auxiliar para o vetorAux
            for (int j = 0; j < vetorPrincipal[i]->ocupados; j++) {
                vetorAux[totalNumeros++] = vetorPrincipal[i]->valores[j];
            }
        }
    }

    // Verifica se todas as estruturas auxiliares estão vazias
    if (totalNumeros == 0) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    // Ordena o vetor com todos os números usando qsort
    qsort(vetorAux, totalNumeros, sizeof(int), comparar);

    return SUCESSO;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int indice = posicao - 1;

    // Verifica se a posição é válida
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    // Verifica se existe estrutura auxiliar na posição
    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    // Copia os valores da estrutura auxiliar para o vetorAux
    for (int i = 0; i < vetorPrincipal[indice]->ocupados; i++) {
        vetorAux[i] = vetorPrincipal[indice]->valores[i];
    }

    // Ordena os valores no vetorAux
    qsort(vetorAux, vetorPrincipal[indice]->ocupados, sizeof(int), comparar);

    return SUCESSO;
}

/* Objetivo: 
Modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/

// Função para modificar o tamanho da estrutura auxiliar
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    int indice = posicao - 1;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[indice] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int tamanhoAtual = vetorPrincipal[indice]->tamanho;
    int tamanhoFinal = tamanhoAtual + novoTamanho;

    // Garantir que o novo tamanho seja >= ao número de ocupados
    if (tamanhoFinal < vetorPrincipal[indice]->ocupados || tamanhoFinal < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novoArray = (int *)realloc(vetorPrincipal[indice]->valores, tamanhoFinal * sizeof(int));
    if (!novoArray)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[indice]->valores = novoArray;
    vetorPrincipal[indice]->tamanho = tamanhoFinal;

    return SUCESSO;
}

/* Objetivo: 
Retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/

// Função para obter a quantidade de elementos preenchidos
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    int indice = posicao - 1;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[indice] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[indice]->ocupados == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return vetorPrincipal[indice]->ocupados;
}

/* Objetivo: 
Montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

// Função para montar a lista encadeada com cabeçote
No *montarListaEncadeadaComCabecote() {
    No *cabecote = (No *)malloc(sizeof(No));
    if (!cabecote)
        return NULL;

    cabecote->conteudo = 0; // Cabeçote não contém valor relevante
    cabecote->prox = NULL;

    No *atual = cabecote;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->ocupados > 0) {
            for (int j = 0; j < vetorPrincipal[i]->ocupados; j++) {
                No *novoNo = (No *)malloc(sizeof(No));
                if (!novoNo) {
                    destruirListaEncadeadaComCabecote(&cabecote);
                    return NULL;
                }

                novoNo->conteudo = vetorPrincipal[i]->valores[j];
                novoNo->prox = NULL;
                atual->prox = novoNo;
                atual = novoNo;
            }
        }
    }

    // Retornar NULL se não houver nenhum elemento válido
    if (cabecote->prox == NULL) {
        free(cabecote);
        return NULL;
    }

    return cabecote;
}

/* Objetivo: 
Retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/

// Função para obter os dados da lista encadeada
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    No *atual = inicio->prox; // Pula o cabeçote
    int index = 0;

    while (atual != NULL) {
        vetorAux[index++] = atual->conteudo;
        atual = atual->prox;
    }
}

/* Objetivo: 
Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/

// Função para destruir a lista encadeada com cabeçote
void destruirListaEncadeadaComCabecote(No **inicio) {
    No *atual = *inicio;

    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}


/* Objetivo: 
Finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

// Função para liberar memória das estruturas auxiliares
void finalizar() {
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            free(vetorPrincipal[i]->valores);
            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}

void dobrar(int *x) {
    if (x != NULL) {
        *x = *x * 2;
    }
}