//Aluno: Matheus Lima Rodrigues BCC(4ºP)

#include <stdio.h>
#include <stdlib.h>

typedef struct Slista{
    int dado;
    struct Slista *prox;
    struct Slista *prev;
}Tlista;

Tlista *criarLista()
{
    Tlista *lista = malloc(sizeof(Tlista));
    lista->prox = NULL;
    lista->prev = NULL;
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
    novo->prev = lista;
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

void insertionSortD(Tlista *lista){
    Tlista *i = NULL, *j = NULL;
    int valor, passos = 0;

    for(i = lista->prox->prox; i != NULL; i = i->prox){
        valor = i->dado;

        for(j = i->prev; (j->prev != NULL && valor < j->dado); j = j->prev){
                passos++;
                j->prox->dado =  j->dado;
        }

        j->prox->dado = valor;
    }

    printf("Passos feitos: %d\n\n", passos);
}

int main(){

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

    printf("\n\nLista ordenada(insertion sort):\n");
    insertionSortD(lista);
    imprimirLista(lista);

    return 0;
}

