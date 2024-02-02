#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int buscaBinaria(int v[], int tam, int chave){
    int inicio = 0, fim = tam - 1;
    int meio = (inicio + fim) / 2;
    
    while(inicio < fim){
        printf("inicio: %d fim: %d meio: %d\n", inicio, fim, meio);
        if(chave > v[meio]){
            inicio = meio + 1;
        } else if (chave < v[meio]){
            fim = meio - 1;
        } else if (chave == v[meio]){
            return meio;
        }

        meio = (inicio + fim) / 2;
    }

    return -1;
}

void imprimirLista(int v[], int tam){
    printf("Vetor Ordenado: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {

    int vetor[TAM], i = 0;

    while (i < 10){
        vetor[i] = i;
        i++;
    }

    imprimirLista(vetor, TAM);

    int resultado = buscaBinaria(vetor, TAM, 11);

    if(resultado == -1){
        printf("Valor nao encontrado!");
    }else{
        printf("Valor encontrado na posicao %d", resultado);
    }

    return 0;
}