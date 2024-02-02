//Matheus Lima Rodrigues BCC 4º Período
//BubbleSort Dinâmico

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

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
        printf("%d ", ultimo->dado);
    } while (ultimo->prox != NULL);
}

void bubbleSortD(Tlista *lista)
{
    Tlista *atual, *ultimo;
    int aux, passos = 0;

    for (ultimo = lista; ultimo != NULL; ultimo = ultimo->prox)
    {
        for (atual = lista->prox; atual->prox != NULL; atual = atual->prox)
        {
            passos++;
            if (atual->dado > atual->prox->dado)
            {
                aux = atual->dado;
                atual->dado = atual->prox->dado;
                atual->prox->dado = aux;
            }
        }
    }
    printf("Quantidade de passos: %d\n\n", passos);
}

int main()
{
    int valor;

    Tlista *lista = criarLista();
    

    while (1)
    {
        printf("Digite um numero: ");
        scanf("%d", &valor);
        if (valor == 0)
            break;
        adicionarLista(lista, valor);
    }
    
    printf("\nLista desordenada:\n");
    imprimirLista(lista);

    printf("\n\nLista ordenada(bubblesort):\n");
    bubbleSortD(lista);
    imprimirLista(lista);

    return 0;
}