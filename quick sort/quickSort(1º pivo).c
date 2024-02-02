//Aluno: Matheus Lima Rodrigues BCC 4ºPeríodo

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int partition(int v[], int inicio, int fim){ 
	int atual, temp; 
	int pivo = v[inicio]; //pivô na posição inicial do vetor
	int maiores = fim + 1;

	for(atual = fim; atual > inicio ; atual--){
		if(v[atual] > pivo){
			maiores--; 
				temp = v[atual];
			v[atual] = v[maiores];			
			v[maiores] = temp;
		}
	}

	int meio = maiores - 1;

	temp = v[meio];
	v[meio] = v[inicio];
	v[inicio] = temp;
	
	return meio;
}

void quickSort(int v[], int inicio, int fim){

	if (inicio >= fim){
		return;
	}

	int meio = partition(v,inicio, fim);

	quickSort(v, 0, meio - 1);
	quickSort(v, meio + 1, fim); 
}

void imprimirLista(int v[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){

    int vetor[TAM] = {5,4,3,2,1}; //vetor desordenado   

    printf("Vetor desordenado:\n");
    imprimirLista(vetor, TAM);

    quickSort(vetor, 0, TAM - 1);

    printf("Vetor ordenado (Quick Sort):\n");
    imprimirLista(vetor, TAM);

    return 0;
}
