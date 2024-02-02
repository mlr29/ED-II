//Aluno: Matheus Lima Rodrigues BCC 4º Período
//Estrutura de Dados II

#include <stdio.h>
#include <stdlib.h>

typedef struct Slista
{
    int dado;
    struct Slista *prox;
} Tlista;

Tlista *criarLista()
{
    Tlista *lista = malloc(sizeof(Tlista));
    lista->prox = NULL;
    return lista;
}

void adicionarLista(Tlista *lista, int dado)
{
    Tlista *novo = malloc(sizeof(Tlista));

    novo->dado = dado;
    novo->prox = NULL;

    while (lista->prox != NULL)
    {
        lista = lista->prox;
    }

    lista->prox = novo;
}

void imprimirLista(Tlista *lista)
{
    Tlista *ultimo = lista;

    if (ultimo->prox == NULL)
    {
        printf("\nLista Vazia!");
        return;
    }

    do
    {
        ultimo = ultimo->prox;
        printf("%d -> ", ultimo->dado);
    } while (ultimo->prox != NULL);

    printf("NULL\n");
}

void selectionSortEstavel(Tlista *lista)
{
    Tlista *j, *i, *menor;
    int temp, trocas = 0;

    for (i = lista->prox; i->prox != NULL; i = i->prox)
    {
        menor = i;
        for (j = i->prox; j != NULL; j = j->prox)
        {
            if ((j->dado) < menor->dado)
            {
                menor = j;
            }
        }
        trocas++;

        temp = i->dado;
        i->dado = menor->dado;
        menor->dado = temp;
    }

    printf("\nTrocas feitas: %d", trocas);
}

int main()
{
    Tlista *sentinela = criarLista();

    int valor;

    while (1)
    {
        printf("Digite um numero: ");
        scanf("%d", &valor);
        if (valor == 0)
            break;
        adicionarLista(sentinela, valor);
    }

    printf("\nLista:\n");
    imprimirLista(sentinela);

    selectionSortEstavel(sentinela);

    printf("\n\nLista Ordenada (Selection Sort Estavel):\n");
    imprimirLista(sentinela);

    return 0;
}