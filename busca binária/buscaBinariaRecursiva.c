//Aluno: Matheus Lima Rodrigues BCC 4ºPeríodo

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int buscaBinariaRecursiva(int v[], int inicio, int fim, int chave)
{
    if (inicio > fim){
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (chave > v[meio]){
        buscaBinariaRecursiva(v, meio + 1, fim, chave);
    }
    else if (chave < v[meio]){
        buscaBinariaRecursiva(v, inicio, meio - 1, chave);
    }
    else if (chave == v[meio]){
        return meio;
    }
}

void imprimirLista(int v[], int tam)
{
    printf("Vetor Ordenado: [ ");
    for (int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("]\n");
}

int main(){

    int vetor[TAM], i = 0, chave;

    while (i < TAM){
        vetor[i] = i + 1;
        i++;
    }

    printf("Busca Binaria:\n\n");
    imprimirLista(vetor, TAM);

    printf("Digite um valor a ser buscado: ");
    scanf("%d", &chave);

    int resultado = buscaBinariaRecursiva(vetor, 0, TAM - 1, chave);

    if (resultado == -1){
        printf("\nValor nao encontrado!");
    }
    else{
        printf("\nValor %d encontrado na posicao %d", chave, resultado);
    }

    return 0;
}