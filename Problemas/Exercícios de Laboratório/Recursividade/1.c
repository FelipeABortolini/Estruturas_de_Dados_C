#include <stdio.h>
#include <stdlib.h>
#define N 10

int somaVetor(int *a, int n){
	if(n==1) return *a;
	return *a + somaVetor(a+1, n-1);
}

int main(){
	int *v, i, S;
	v = malloc(N*sizeof(int));
	for(i=0; i<N; i++){
		*(v+i) = i;
		printf("%d\n", *(v+i));
	}
	S = somaVetor(v, N);
	printf("Soma dos elementos: %d", S);
}
