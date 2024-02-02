#include <stdio.h>
#include <stdlib.h>

void insertionSort(int v[], int tam){
    int j, i, atual, passos = 0;

    for(i = 1; i < tam; i++){
        atual = v[i]; 
        for(j = i - 1; (j >= 0 && atual < v[j]); j--){
            passos++;
            v[j+1] = v[j];
        }
        v[j + 1] = atual;
    }

    printf("\nPassos: %d\n", passos); 
}

void imprimirLista(int v[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int vetor[] = {5,4,3,2,1};

    imprimirLista(vetor, 5);
    insertionSort(vetor, 5);
    imprimirLista(vetor, 5);
    return 0;
}