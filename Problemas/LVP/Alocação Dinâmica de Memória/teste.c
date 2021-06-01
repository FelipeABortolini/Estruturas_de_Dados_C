#include <stdio.h>
#include <stdlib.h>

int* junta_vetor(int *v1, int n1, int *v2, int n2){
	int *v, tam = n1+n2, i;
	v = malloc(sizeof(int)*tam);
	for(i=0; i<tam; i++){
		if(i<n1) *(v+i) = *(v1+i);
		else *(v+i) = *(v2+i-n1);
	}
	return v;
}

int main(){
	int i, v1[5] = {1, 4, 5, 6, 8}, v2[5] = {4, 8, 3, 8, 9}, *v3;
	v3 = junta_vetor(v1, 5, v2, 5);
	for(i=0; i<10; i++){
		printf("%d ", *(v3+i));
	}
}
