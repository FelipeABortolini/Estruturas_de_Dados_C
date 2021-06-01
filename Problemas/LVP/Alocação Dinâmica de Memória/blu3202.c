#include <blu3202.h>
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
