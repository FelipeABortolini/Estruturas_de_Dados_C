#include <stdio.h>

int main(){
	int v[5];
	int *p = v;
	int i;
	for (i=0; i<5; i++){
		printf("%do valor: ", i+1);
		scanf("%d", v+i);
	}
	for(i=0; i<5; i++){
		*(v+i) = 2*(*(v+i));
	}
	for(i=0; i<5; i++){
		printf("%d\n", *(v+i));
	}
}
