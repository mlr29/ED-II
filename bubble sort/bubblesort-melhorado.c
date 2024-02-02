#include <stdio.h>

#define TAMANHO 5

void imprimirLista(int vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("\n%d", vet[i]);
    }
}

void bubblesort(int vet[], int tam)
{
    int i, j, k = 0, aux, passos = 0;

    for (j = 0; j < tam - 1; j++)
    { // condição tam - 1, que reduz um laço de operações
        for (i = 0; i < tam - (j + 1); i++)
        {
            passos++;
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                k++; // conta se houve troca de números
            }
        }
        if (k == 0) // se após o laço não houve nenhuma troca, o vetor está ordenado
            break;
        k = 0;
    }

    printf("\n\nQuantidade de passos: %d\n", passos);
}

int main()
{
    int valor, i, vet[TAMANHO];

    i = 0;
    while (1)
    {
        printf("Digite um numero (vet = %d numeros): ", TAMANHO);
        scanf("%d", &valor);

        vet[i++] = valor;

        if (i > TAMANHO - 1)
            break;
    }

    printf("\nLista:");
    imprimirLista(vet, TAMANHO);

    bubblesort(vet, TAMANHO);

    printf("\nLista Ordenadda:");
    imprimirLista(vet, TAMANHO);
}