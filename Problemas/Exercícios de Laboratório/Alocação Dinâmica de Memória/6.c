#include <stdio.h>
#include <stdlib.h>

void parImpar(int *vetor, int n){
	int *vetPar, *vetImpar, nPar = 0, nImpar = 0, i, j = 0;
	
	printf("Vetor original: [ ");
	for(i=0; i<n; i++){
		printf("%d ", *(vetor+i));
		if(*(vetor+i)%2==0) nPar++;
		else nImpar++;
	}
	printf("]\n");
	
	vetPar = malloc(sizeof(int)*nPar);
	printf("Numeros pares: [ ");
	for(i=0; i<n; i++){
		if(*(vetor+i)%2==0){
			*(vetPar+j) = *(vetor+i);
			printf("%d ", *(vetPar+j));
			j++;
		}
	}
	printf("]\n");
	
	j = 0;
	vetImpar = malloc(sizeof(int)*nImpar);
	printf("Numeros Impares: [ ");
	for(i=0; i<n; i++){
		if(*(vetor+i)%2!=0){
			*(vetImpar+j) = *(vetor+i);
			printf("%d ", *(vetImpar+j));
			j++;
		}
	}
	printf("]\n");
}

int main(){
	int N, i, *v, *v2, *v3;
	printf("Numero de elementos do vetor: ");
	scanf("%d", &N);
	v = malloc(sizeof(int)*N);
	for(i=0; i<N; i++){
		printf("%do elemento: ", i+1);
		scanf("%d", v+i);
	}
	parImpar(v, N);
}
