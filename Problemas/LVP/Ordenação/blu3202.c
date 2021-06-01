#include <stdlib.h>
#include <stdio.h>

void ordena(int *v , int esq , int meio , int dir );
void mergeSort(int inicio, int fim, int *v);

int main(){
	int vetor[10] = {75,98,26,105,48,35,2,7,5,47};
	mergeSort(0, 9, vetor);
	int i;
	for(i=0; i<10; i++){
		printf("%d ", vetor[i]);
	}
}

void mergeSort(int inicio, int fim, int *v){
    if(fim>inicio){
    	int meio = (inicio+fim)/2;
    	mergeSort(inicio,meio,v);
    	mergeSort(meio+1,fim,v);
    	ordena(v, inicio, meio, fim);
    }
}

void ordena(int *v, int inicio, int meio, int fim){
	int i, j, k;
	int tam1 = meio-inicio+1;
	int tam2 = fim-meio;
	
	int *sub1 = malloc(sizeof(int)*tam1);
	int *sub2 = malloc(sizeof(int)*tam2);
	
	for (i = 0; i < tam1; i++) sub1[i] = v[i+inicio];
	for (i = 0; i < tam2; i++) sub2[i] = v[i+meio+1];
	
	for (i = 0, j = 0, k = inicio; k <= fim; k++) {
		if(i == tam1) v[k] = sub2[j++];
		else if(j == tam2) v[k] = sub1[i++];
		else if(sub1[i] < sub2[j]) v[k] = sub1[i++];
		else v[k] = sub2[j++];
	}
	
	free(sub1); 
	free(sub2);
}
