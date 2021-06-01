#include <stdio.h>
#include <stdlib.h>

int *vet(int *vet1, int *vet2, int num1, int num2){
	int n3 = num1 + num2, i;
	int *v = malloc(sizeof(int)*n3);
	for(i=0; i<num1; i++){
		*(v+i) = *(vet1+i);
	}
	for(i=num1; i<n3; i++){
		*(v+i) = *(vet2+i-num1);
	}
	return v;
}

int main(){
	int n1, n2, *v1, *v2, *v3, i;
	
	printf("Tamanho 1o vetor: ");
	scanf("%d", &n1);
	v1 = malloc(sizeof(int)*n1);
	for(i=0; i<n1; i++){
		printf("%do valor: ", i+1);
		scanf("%d", v1+i);
	}
	
	printf("Tamanho 2o vetor: ");
	scanf("%d", &n2);
	v2 = malloc(sizeof(int)*n2);
	for(i=0; i<n2; i++){
		printf("%do valor: ", i+1);
		scanf("%d", v2+i);
	}
	
	v3 = vet(v1, v2, n1, n2);
	
	for(i=0; i<n1+n2; i++){
		printf("%d ", *(v3+i));
	}
}
