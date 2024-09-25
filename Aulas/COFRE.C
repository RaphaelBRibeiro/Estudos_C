#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noMoeda
{ // ESTRUTURA DE MOEDAS
    int moeda;
    struct noMoeda *prox;
} noMoeda;

typedef struct noNome
{ // ESTRUTURA DE NOMES
    char nome[30];
    struct noNome *prox;
    struct noMoeda *proxMoeda;
} noNome;

int vazia(noNome *LISTA)
{
    return LISTA == NULL || LISTA->prox == NULL;
}

void inserirPessoa(noNome *LISTA)
{
    noNome *novo = (noNome *)malloc(sizeof(noNome));
    if (novo == NULL)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }

    printf("\nNome da pessoa: ");
    scanf("%s", novo->nome);
    novo->prox = NULL;
    novo->proxMoeda = NULL; // Inicializando o cofre como NULL

    if (vazia(LISTA))
    {
        LISTA->prox = novo;
    }
    else
    {
        noNome *temp = LISTA->prox;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void imprimir(noNome *LISTA)
{
    noNome *temp = LISTA->prox;
    int contador = 0;
    while (temp != NULL)
    {
        printf("Posicao %d: %s\n----------\n", contador, temp->nome);
        temp = temp->prox;
        contador++;
    }
}

void removerPessoa(noNome *LISTA)
{
    if (vazia(LISTA))
    {
        printf("Lista vazia! Nao ha o que remover.\n");
        return;
    }

    int posicao = 0;
    int cont = 0;
    printf("Qual posicao da pessoa que voce quer remover?: ");
    scanf("%d", &posicao);

    noNome *ant = LISTA;
    noNome *suc = LISTA->prox;

    while (cont < posicao && suc != NULL)
    {
        ant = suc;
        suc = suc->prox;
        cont++;
    }

    if (suc == NULL)
    {
        printf("Posicao %d nao encontrada.\n", posicao);
        return;
    }

    ant->prox = suc->prox;
    free(suc);
    printf("\n==========REMOVIDO_POSICAO: %d============\n", posicao);
}

void iniciaLista(noNome *LISTA)
{
    LISTA->prox = NULL;
}

void iniciaCofre(noMoeda *COFRE)
{
    COFRE->prox = NULL;
}

void liberarLista(noNome *LISTA)
{
    noNome *atual = LISTA->prox;
    noNome *prox;

    while (atual != NULL)
    {
        prox = atual->prox;

        // Libera todas as moedas do cofre
        noMoeda *moedaAtual = atual->proxMoeda;
        while (moedaAtual != NULL)
        {
            noMoeda *moedaProx = moedaAtual->prox;
            free(moedaAtual);
            moedaAtual = moedaProx;
        }

        free(atual);
        atual = prox;
    }

    free(LISTA); // Libera a estrutura inicial
}

void pushMoeda(noMoeda **COFRE)
{
    int valor;
    printf("\nQual o valor da moeda a ser inserida?: ");
    scanf("%d", &valor);
    noMoeda *novo = (noMoeda *)malloc(sizeof(noMoeda));
    if (novo == NULL)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo->moeda = valor;
    novo->prox = *COFRE;
    *COFRE = novo;

    printf("\nMoeda adicionada: %d\n", novo->moeda);
}

void imprimirMoedas(noMoeda *COFRE)
{
    noMoeda *temp = COFRE;

    while (temp != NULL)
    {
        printf("\n%d", temp->moeda);
        temp = temp->prox;
    }
    printf("\n=============FIM_IMPRESSAO==============");
}

void removerMoeda(noMoeda **COFRE)
{
    if (*COFRE == NULL)
    {
        printf("Cofre vazio, nao ha moedas para remover.\n");
        return;
    }

    noMoeda *temp = *COFRE;
    *COFRE = temp->prox;
    free(temp);
    printf("Moeda removida com sucesso.\n");
}

void acessarCofre(noNome *LISTA)
{
    int posicaoCofre;
    int contador = 0;
    noNome *AUX = LISTA->prox;

    printf("\n\nQual cofre deseja acessar?:\n---------------------------\n");
    imprimir(LISTA);
    printf("---------------------------\nPosicao?: ");
    scanf("%d", &posicaoCofre);

    while (contador < posicaoCofre && AUX != NULL)
    {
        AUX = AUX->prox;
        contador++;
    }

    if (AUX == NULL)
    {
        printf("Posicao nao encontrada.\n");
        return;
    }

    noMoeda **COFRE = &AUX->proxMoeda; // Usa o cofre da pessoa

    if (*COFRE == NULL)
    {
        *COFRE = NULL;
    }

    printf("\n====ACESSANDO_COFRE: %s====", AUX->nome);

    do
    {
        printf("\n\n====MENU_DE_COFRE: %s====\n1. Adicionar Moeda \n2. Retirar Moeda \n3. Apresentar todas as moedas \n0. Voltar.\nOp��o?: ", AUX->nome);
        scanf("%d", &posicaoCofre);

        switch (posicaoCofre)
        {
        case 1:
            printf("\n==========INSERINDO_MOEDAS_COFRE: %s==========\n", AUX->nome);
            pushMoeda(COFRE);
            break;
        case 2:
            printf("\n==========REMOVENDO_MOEDA_COFRE: %s==========\n", AUX->nome);
            removerMoeda(COFRE);
            break;
        case 3:
            printf("\n==========IMPRIMINDO_MOEDAS_COFRE: %s==========\n", AUX->nome);
            imprimirMoedas(*COFRE);
            break;
        }

    } while (posicaoCofre != 0);
}

int main() // MENU PRINCIPAL
{
    int opcao;

    noNome *LISTA = (noNome *)malloc(sizeof(noNome));
    if (LISTA == NULL)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    iniciaLista(LISTA);

    do
    {
        printf("\n\n===MENU_DE_OPCOES===\n1. Adicionar Pessoa \n2. Retirar Pessoa \n3. Apresentar todas as pessoas \n4. Acessar cofre de pessoa...: \n0. Sair.\nOpcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            inserirPessoa(LISTA);
            break;
        case 2:
            removerPessoa(LISTA);
            break;
        case 3:
            printf("\n==========IMPRIMINDO_LISTA==========\n");
            imprimir(LISTA);
            break;
        case 4:
            acessarCofre(LISTA);
            break;
        }
    } while (opcao != 0);

    liberarLista(LISTA);
    LISTA = NULL; 
    printf("Fim do programa, obrigado.");
    return 0;
}
