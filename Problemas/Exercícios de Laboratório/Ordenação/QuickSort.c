#include <stdio.h>
#include <stdlib.h>

void quickSort(int *v, int esquerda, int direita){
	int pivo = v[(esquerda+direita)/2];
	int e = esquerda, d = direita, tmp;
	
	while(e<d){
		while(v[e]<pivo)
			e++;
		while(v[d]>pivo)
			d--;
		if(e<=d){
			tmp = v[e];
			v[e] = v[d];
			v[d] = tmp;
			e++;
			d--;
		}
	}
	
	if(esquerda<d){
		quickSort(v, esquerda, d);
	}
	if(e<direita){
		quickSort(v, e, direita);
	}
}

int main(){
	int vetor[10] = {9,8,7,6,5,4,3,2,1,0};
	quickSort(vetor, 0, 9);
	int i;
	for(i=0; i<10; i++){
		printf("%d ", vetor[i]);	
	}
}
