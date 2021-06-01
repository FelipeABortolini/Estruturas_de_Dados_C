#include<stdio.h>
#include<stdlib.h>


int insertionSort(int *v, int s){
	int i; // Marca o início da porção não ordenada.
	int j; // Marca a posição que está sendo examinada na porção oredenada.
	int atual, comp = 0;
	for(i=1; i<s; i++){
		atual = v[i];
		j = i-1; // "j" é iniciializado com a última posição do vetor ordenado.
		while(atual<v[j] && j>=0){
			v[j+1] = v[j];
			j--;
			comp++;
		}
		v[j+1] = atual;
	}
	return comp;
}


int main(){
	int vetor[15] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
	int i, comparacoes;
	comparacoes = insertionSort(vetor, 15);
	for(i=0; i<15; i++){
		printf("%d ", vetor[i]);
	}
	printf("Comparacoes: %d\n", comparacoes);
}
