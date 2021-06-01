#include<stdio.h>
#include<stdlib.h>


int selectionSort(int *v, int s){
	int i; // Marca o início da porção não ordenada.
	int j, temp;
	int menor, comp = 0;
	for(i=0; i<s-1; i++){
		menor = i;
		for(j=i+1; j<s; j++){
			comp++;
			if(v[j]<v[menor])
				menor = j;
		}
		temp = v[i];
		v[i] = v[menor];
		v[menor] = temp;
	}
	return comp;
}


int main(){
	int vetor[15] = {14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
	int i, comparacoes;
	comparacoes = selectionSort(vetor, 15);
	for(i=0; i<15; i++){
		printf("%d ", vetor[i]);
	}
	printf("Comparacoes: %d\n", comparacoes);
}
