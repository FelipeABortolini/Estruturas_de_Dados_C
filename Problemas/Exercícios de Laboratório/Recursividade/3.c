#include <stdio.h>
#include <stdlib.h>
#define N 10

int *inverteVetor(int *a, int n, int pos){
	if(n<=1)
		return a-pos;
	int aux = *(a+n-1);
	*(a+n-1) = *a;
	*a = aux;
	pos++;
	return inverteVetor(a+1, n-2, pos);
}

int main(){
	int *v, i, *S;
	
	v = malloc(N*sizeof(int));
	for(i=0; i<N; i++){
		*(v+i) = i;
		printf("%d\n", *(v+i));
	}
	
	S = inverteVetor(v, N, 0);
	
	printf("Vetor invertido: ");
	for(i=0; i<N; i++){
		printf("%d ", *(S+i));
	}
}
