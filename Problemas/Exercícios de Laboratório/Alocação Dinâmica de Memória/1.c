#include <stdio.h>
#include <stdlib.h>
#define N 10

void preenche(int *vet, int tam, int n){
	int i;
	vet = malloc(sizeof(int) * tam);
	for(i=0; i<tam; i++){
		*(vet+i) = n;
	}
	for(i=0; i<tam; i++){
		printf("%d ", *(vet+i));
	}
}

int main(){
	int *v, i;
	v = malloc(sizeof(int) * N);
	preenche(v, N, 8);
}
