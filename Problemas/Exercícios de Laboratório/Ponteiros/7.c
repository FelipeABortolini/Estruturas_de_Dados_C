#include <stdio.h>

void maximoMinimo(int *v, int N, int *maximo, int *minimo){
	int i;
	for(i=0; i<N; i++){
		if(i==0){
			*maximo = *v;
			*minimo = *v;
		} else if (*(v+i) > *maximo){
			*maximo = *(v+i);
		} else if (*(v+i) < *minimo){
			*minimo = *(v+i);
		}
	}
}

int main(){
	int v[5] = {8,6,45,2,3};
	int max, min;
	maximoMinimo(v, 5, &max, &min);
	printf("Max: %d\n", max);
	printf("Min: %d\n", min);
}
